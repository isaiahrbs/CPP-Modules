#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "🧠 === TEST COPIES PROFONDES === 🧠" << std::endl;
    {
        std::cout << "\n--- Test Dog ---" << std::endl;
        Dog rex;
        Dog buddy = rex;
        Dog max;
        max = rex;
        
        std::cout << "\n--- Test Cat ---" << std::endl;
        Cat whiskers;
        Cat mittens(whiskers);
        Cat shadow;
        shadow = whiskers;
        
        std::cout << "\n--- Fin du scope (destructeurs appelés) ---" << std::endl;
    }
    
    std::cout << "\n🐕🐱 === TEST TABLEAU POLYMORPHE === 🐕🐱" << std::endl;
    const int ARRAY_SIZE = 6;
    Animal* zoo[ARRAY_SIZE];
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i % 2 == 0) {
            std::cout << "Création chien " << i/2 + 1 << std::endl;
            zoo[i] = new Dog();
        } else {
            std::cout << "Création chat " << (i+1)/2 << std::endl;
            zoo[i] = new Cat();
        }
    }
    
    std::cout << "\n--- Concert animalier ---" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "Animal " << i + 1 << " (" << zoo[i]->getType() << ") : ";
        zoo[i]->makeSound();
    }
    
    std::cout << "\n--- Libération de la ménagerie ---" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "Suppression animal " << i + 1 << std::endl;
        delete zoo[i];
    }
    
    std::cout << "\n❌ === TEST WRONG CLASSES === ❌" << std::endl;
    WrongAnimal* wrongPtr = new WrongCat();
    Animal* rightPtr = new Cat();
    
    std::cout << "WrongAnimal* pointant vers WrongCat : ";
    wrongPtr->makeSound();
    std::cout << "Animal* pointant vers Cat : ";
    rightPtr->makeSound();
    
    delete wrongPtr;
    delete rightPtr;
    
    std::cout << "\n✅ === TESTS TERMINÉS === ✅" << std::endl;
    return 0;
}