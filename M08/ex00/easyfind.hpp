#pragma once

#include <vector>
#include <algorithm>

// On apprend les iterators et pour retourner l'iterator d'un type il faut ecrire avec cette syntaxe

/*

• le compilateur ne reconnait pas encore `T`, il ne sait pas si c'est une fonction ou quelquechose d'autre
donc pour preciser que c'est bien un template j'ajouter le type typename avant pour qu'il sache.
- "Hey compilateur, T::iterator est un TYPE"

• "auto" est un type de variable qui dit à C++ : "détecte automatiquement le type de ce qui se fait assigner"
Utile pour les variables locales, mais éviter pour les types de retour de fonctions

*/
template<typename T>
typename T::iterator easyfind(T& container, int value) {
	auto it = std::find(container.begin(), container.end(), value);
	// auto = typename T::iterator
	return it;
}
