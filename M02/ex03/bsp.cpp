#include "Point.hpp"
#include "Fixed.hpp"

// Calcule l'aire signée d'un triangle (déterminant)
/*
    positif = a gauche
    negatif = a droite
    0 = sur la ligne
*/

/*
     Y
     ↑
     |    C(2.5, 5)
   5 |       /\
     |      /  \
     |     /    \
   2 |    /   *  \
     |   /(2.5,2) \
   0 |  A-----------B  → X
     0  0    2.5    5
        A(0,0)     B(5,0)

*/
static Fixed sign(Point const &p1, Point const &p2, Point const &p3) {
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
         - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

/*
    Il n'y a pas vraiment des lignes, bsp "imagine" ces lignes
    comment on fait c'est quon test le point avec chaque coter du triangle un par un
*/
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed d1 = sign(point, a, b); // contre coter AB
    Fixed d2 = sign(point, b, c); // contre coter BC
    Fixed d3 = sign(point, c, a); // contre coter CA

    /*
    si le point est a gauche de AB : > 0
    si il est a droite : < 0
    si il est sur la ligne : = 0
    */
    bool has_neg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
    bool has_pos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

    // Si le point est sur un bord ou un sommet, retourne false
    if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
        return false;

    return !(has_neg && has_pos);
}
