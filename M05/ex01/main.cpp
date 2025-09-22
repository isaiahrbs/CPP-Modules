#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <unistd.h>


int main() {

	std::cout << "{--------------EX00--------------}" << std::endl;
	std::cout << "[--------------Test #1--------------]" << std::endl;
	try {
		Bureaucrat e("Eminem", 160);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "[--------------Test #2--------------]" << std::endl;
	try {
		Bureaucrat l("Link", 160);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "[--------------Test #3--------------]" << std::endl;
	try {
		Bureaucrat l("Zelda", 150);
		l.decrementGrade();
		// it skips this one because as soon as there is a throw, it goes to the catch block
		Bureaucrat b("Bob", 170);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "{--------------EX01--------------}" << std::endl;
	// Test 1 : Bureaucrat peut signer le formulaire
    std::cout << "[--------------Test #1--------------]" << std::endl;
    Bureaucrat b1("Alice", 10);
    Form f1("FormA", 20, 30);
    b1.signForm(f1);
    std::cout << f1 << std::endl;

    // Test 2 : Bureaucrat ne peut pas signer (grade trop bas)
    std::cout << "[--------------Test #2--------------]" << std::endl;
    Bureaucrat b2("Bob", 50);
    Form f2("FormB", 20, 30);
    b2.signForm(f2);
    std::cout << f2 << std::endl;

    // Test 3 : Form déjà signé
    std::cout << "[--------------Test #3--------------]" << std::endl;
    Bureaucrat b3("Charlie", 1);
    Form f3("FormC", 10, 10);
    b3.signForm(f3); // Premier essai
    b3.signForm(f3); // Deuxième essai (déjà signé)
    std::cout << f3 << std::endl;

    // Test 4 : Création Form avec grade trop haut/bas
    std::cout << "[--------------Test #4--------------]" << std::endl;
    try {
        Form f4("FormD", 0, 10); // trop haut
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form f5("FormE", 10, 151); // trop bas
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}