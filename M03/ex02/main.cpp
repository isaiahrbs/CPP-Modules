#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== CLAPTRAP TESTS ===" << std::endl;
    {
        ClapTrap a("Alpha");
        ClapTrap b("Bravo");

        a.attack("Bravo");
        b.takeDamage(5);
        b.beRepaired(3);
        for (int i = 0; i < 11; ++i)
            a.attack("Bravo");
    }

    std::cout << "\n=== SCAVTRAP TESTS ===" << std::endl;
    {
        ScavTrap s("Scavy");
        s.attack("Target1");
        s.takeDamage(20);
        s.beRepaired(10);
        s.guardGate();
        for (int i = 0; i < 51; ++i)
            s.attack("Target2");
    }

    std::cout << "\n=== FRAGTRAP TESTS ===" << std::endl;
    {
        FragTrap f("Fraggy");
        f.attack("Enemy");
        f.takeDamage(50);
        f.beRepaired(25);
        f.highFivesGuys();
        for (int i = 0; i < 101; ++i)
            f.attack("Enemy");
    }

    std::cout << "\n=== DESTRUCTION ORDER TEST ===" << std::endl;
    {
        FragTrap f1("Destructor");
        ScavTrap s1("DestructorScav");
        ClapTrap c1("DestructorClap");
    }

    return 0;
}