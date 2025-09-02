#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main() {
    IMateriaSource* source = new MateriaSource();
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());

    ICharacter* player = new Character("player");
    AMateria* iceSpell = source->createMateria("ice");
    AMateria* cureSpell = source->createMateria("cure");

    player->equip(iceSpell);
    player->equip(cureSpell);

    ICharacter* target = new Character("target");

    player->use(0, *target); // Utilise la materia "ice" sur "target"
    player->use(1, *target); // Utilise la materia "cure" sur "target"

    // Test supplémentaire : inventaire plein
    player->equip(source->createMateria("ice"));
    player->equip(source->createMateria("cure"));
    player->equip(source->createMateria("ice")); // Ne doit rien faire

    // Test unequip
    player->unequip(0);
    player->use(0, *target); // Ne doit rien afficher

    delete target;
    delete player;
    delete source;
    return 0;
}