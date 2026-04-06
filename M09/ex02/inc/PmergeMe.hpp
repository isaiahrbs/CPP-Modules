#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <stdexcept>

// ================================================================
// Ford-Johnson "merge-insert sort" — explication de l'algo
// ================================================================
//
// Idée de base : trier en faisant le moins de comparaisons possible.
//
// ÉTAPE 1 — Former des paires
//   On groupe les éléments deux par deux. Dans chaque paire, on compare
//   et on identifie le "gagnant" (le plus grand) et le "perdant" (le plus petit).
//
// ÉTAPE 2 — Trier les gagnants récursivement
//   On extrait les gagnants et on les trie avec le même algorithme (récursion).
//   Résultat : on a une séquence de gagnants triée.
//
// ÉTAPE 3 — Construire la chaîne initiale
//   On démarre avec [perdant[0], gagnant[0], gagnant[1], gagnant[2], ...]
//   perdant[0] va forcément devant gagnant[0] car perdant[0] < gagnant[0].
//
// ÉTAPE 4 — Insérer les perdants restants dans l'ordre de Jacobsthal
//   Les nombres de Jacobsthal (0, 1, 1, 3, 5, 11, 21, 43...) donnent l'ordre
//   optimal d'insertion pour minimiser le nombre de comparaisons.
//   Chaque insertion utilise une recherche binaire (lower_bound).
//
// ÉTAPE 5 — Insérer le "straggler" (l'élément orphelin si n est impair)
//
// On fait ça pour std::vector ET std::deque pour comparer les perfs.
// ================================================================

// ----------------------------------------------------------------
// Fonctions utilitaires (en dehors de la classe, liées au template)
// ----------------------------------------------------------------

// Génère les nombres de Jacobsthal jusqu'à n.
// Définition : J(0)=0, J(1)=1, J(n) = J(n-1) + 2*J(n-2)
// Séquence : 0, 1, 1, 3, 5, 11, 21, 43, 85, 171 ...
inline std::vector<int> getJacobsthal(int n) {
    std::vector<int> jac;
    jac.push_back(0);
    jac.push_back(1);
    while (jac.back() < n)
        jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);
    return jac;
}

// Génère l'ordre dans lequel insérer les perdants pend[1..pendSize-1].
// (pend[0] est déjà dans la chaîne, donc on commence à 1.)
//
// L'idée : on insère en groupes, chaque groupe allant de l'index le plus
// haut vers le bas. Ça garantit que la zone de recherche binaire pour
// chaque insertion est toujours une puissance de 2 - 1 (optimal).
inline std::vector<int> getInsertionOrder(int pendSize) {
    std::vector<int> jac = getJacobsthal(pendSize);
    std::vector<int> order;

    // Pour chaque groupe k, on insère de jac[k]-1 jusqu'à jac[k-1] (0-indexé)
    for (size_t k = 2; k < jac.size(); k++) {
        int hi = std::min(jac[k], pendSize) - 1; // borne haute (0-indexé)
        int lo = jac[k - 1];                      // borne basse (0-indexé)
        for (int i = hi; i >= lo; i--)
            order.push_back(i);
        if (jac[k] >= pendSize)
            break;
    }
    return order;
}

// ----------------------------------------------------------------
// fordJohnson — template qui marche pour vector<int> et deque<int>
// ----------------------------------------------------------------
template<typename Container>
void fordJohnson(Container &v) {
    int n = (int)v.size();
    if (n <= 1)
        return;

    // Si impair, on met l'élément orphelin de côté
    bool hasOdd = (n % 2 == 1);
    int  straggler = 0;
    if (hasOdd) {
        straggler = v.back();
        v.pop_back();
        n--;
    }

    // --- ÉTAPE 1 : former des paires (perdant, gagnant) ---
    // pairs[i].first  = le plus petit des deux (perdant)
    // pairs[i].second = le plus grand des deux (gagnant)
    std::vector<std::pair<int, int> > pairs;
    for (int i = 0; i < n; i += 2) {
        int lo = (v[i] < v[i + 1]) ? v[i] : v[i + 1];
        int hi = (v[i] < v[i + 1]) ? v[i + 1] : v[i];
        pairs.push_back(std::make_pair(lo, hi));
    }

    // --- ÉTAPE 2 : trier les gagnants récursivement ---
    Container winners;
    for (size_t i = 0; i < pairs.size(); i++)
        winners.push_back(pairs[i].second);
    fordJohnson(winners); // appel récursif — winners est maintenant trié

    // Reconstituer les paires dans l'ordre trié des gagnants.
    // Le drapeau "used" permet de gérer les doublons correctement.
    std::vector<bool> used(pairs.size(), false);
    std::vector<std::pair<int, int> > sortedPairs;
    for (size_t wi = 0; wi < winners.size(); wi++) {
        for (size_t pi = 0; pi < pairs.size(); pi++) {
            if (!used[pi] && pairs[pi].second == winners[wi]) {
                sortedPairs.push_back(pairs[pi]);
                used[pi] = true;
                break;
            }
        }
    }

    // pend[i] = le perdant associé au i-ème gagnant trié
    std::vector<int> pend;
    for (size_t i = 0; i < sortedPairs.size(); i++)
        pend.push_back(sortedPairs[i].first);

    // --- ÉTAPE 3 : construire la chaîne initiale ---
    // pend[0] va forcément avant winners[0] donc on le place en tête
    Container chain;
    chain.push_back(pend[0]);
    for (size_t i = 0; i < winners.size(); i++)
        chain.push_back(winners[i]);

    // --- ÉTAPE 4 : insérer pend[1..] dans l'ordre de Jacobsthal ---
    int pendSize = (int)pend.size();
    if (pendSize > 1) {
        std::vector<int> order = getInsertionOrder(pendSize);
        for (size_t i = 0; i < order.size(); i++) {
            int idx = order[i];
            if (idx <= 0 || idx >= pendSize)
                continue;
            // lower_bound trouve la première position où pend[idx] peut s'insérer
            typename Container::iterator pos =
                std::lower_bound(chain.begin(), chain.end(), pend[idx]);
            chain.insert(pos, pend[idx]);
        }
    }

    // --- ÉTAPE 5 : insérer le straggler ---
    if (hasOdd) {
        typename Container::iterator pos =
            std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }

    v = chain;
}

// ================================================================
// Classe PmergeMe — gère le parsing, le tri, et l'affichage
// ================================================================
class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &src);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &src);

    // Point d'entrée principal : parse argv, trie, affiche le résultat + temps
    void run(int argc, char **argv);

private:
    std::vector<int> _vec;
    std::deque<int>  _deq;

    void parseInput(int argc, char **argv);
};

#endif
