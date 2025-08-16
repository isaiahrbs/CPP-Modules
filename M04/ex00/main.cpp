#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Testing Animal hierarchy (with virtual) ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    Dog testDog;
    Dog CopyDog(testDog);
    
    std::cout << "\nTesting getType():" << std::endl;
    std::cout << "meta type: " << meta->getType() << std::endl;
    std::cout << "j type: " << j->getType() << std::endl;
    std::cout << "i type: " << i->getType() << std::endl;
    
    std::cout << "\nTesting makeSound() - should show polymorphism:" << std::endl;
    meta->makeSound();
    j->makeSound();  // Should bark
    i->makeSound();  // Should meow
    
    std::cout << "\nDeleting Animal objects:" << std::endl;
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n=== Testing WrongAnimal hierarchy (without virtual) ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "\nTesting getType():" << std::endl;
    std::cout << "wrongMeta type: " << wrongMeta->getType() << std::endl;
    std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;
    
    std::cout << "\nTesting makeSound() - should NOT show polymorphism:" << std::endl;
    wrongMeta->makeSound();  // WrongAnimal sound
    wrongCat->makeSound();   // Should still be WrongAnimal sound (not WrongCat!)
    
    std::cout << "\nDeleting WrongAnimal objects:" << std::endl;
    delete wrongMeta;
    delete wrongCat;
    
    std::cout << "\n=== Testing direct object creation ===" << std::endl;
    WrongCat directCat;
    std::cout << "Direct WrongCat makeSound(): ";
    directCat.makeSound();  // This will correctly call WrongCat::makeSound()
    
    return 0;
}

