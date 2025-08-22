#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    // Définition d'un triangle
    Point a(0.0f, 0.0f);    // Sommet A
    Point b(5.0f, 0.0f);    // Sommet B  
    Point c(2.5f, 5.0f);    // Sommet C

    // Tests de points
    Point inside(2.5f, 2.0f);      // À l'intérieur
    Point outside(10.0f, 10.0f);   // À l'extérieur
    Point onEdge(2.5f, 0.0f);      // Sur un bord
    Point vertex(0.0f, 0.0f);      // Sur un sommet

    // Test 1: Point à l'intérieur
    std::cout << "Point inside triangle: ";
    if (bsp(a, b, c, inside))
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;

    // Test 2: Point à l'extérieur
    std::cout << "Point outside triangle: ";
    if (bsp(a, b, c, outside))
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;

    // Test 3: Point sur un bord
    std::cout << "Point on edge: ";
    if (bsp(a, b, c, onEdge))
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;

    // Test 4: Point sur un sommet
    std::cout << "Point on vertex: ";
    if (bsp(a, b, c, vertex))
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;

    return 0;
}