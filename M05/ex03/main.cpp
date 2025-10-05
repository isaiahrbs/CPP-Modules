#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(std::time(0));

    std::cout << "\n===== Test ShrubberyCreationForm =====\n" << std::endl;
    Bureaucrat boss("Boss", 1);
    ShrubberyCreationForm shrub("garden");
    try {
        boss.signForm(shrub);
        boss.executeForm(shrub);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Test ShrubberyCreationForm (grade trop bas pour exec) =====\n" << std::endl;
    Bureaucrat low("Low", 146);
    ShrubberyCreationForm shrub2("yard");
    try {
        low.signForm(shrub2);
        low.executeForm(shrub2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Test RobotomyRequestForm =====\n" << std::endl;
    Bureaucrat rob("Rob", 1);
    RobotomyRequestForm robot("Bender");
    try {
        rob.signForm(robot);
        rob.executeForm(robot);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Test RobotomyRequestForm (non signé) =====\n" << std::endl;
    RobotomyRequestForm robot2("Flexo");
    try {
        rob.executeForm(robot2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Test PresidentialPardonForm =====\n" << std::endl;
    Bureaucrat pres("President", 1);
    PresidentialPardonForm pardon("Ford Prefect");
    try {
        pres.signForm(pardon);
        pres.executeForm(pardon);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Test PresidentialPardonForm (grade trop bas pour signer) =====\n" << std::endl;
    try {
        Bureaucrat helper("Helper", 151);
        PresidentialPardonForm pardon2("Arthur Dent");

        helper.signForm(pardon2);
        helper.executeForm(pardon2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Test Polymorphisme =====\n" << std::endl;
    AForm* form = new ShrubberyCreationForm("polymorph");
    try {
        boss.signForm(*form);
        boss.executeForm(*form);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    delete form;

    std::cout << "\n===== Test Intern =====\n" << std::endl;
    Intern newIntern;

    Bureaucrat CEO("CEO", 1);
    try {
        AForm* NewForm = newIntern.makeForm("PresidentialPardon", "Speech");
        CEO.signForm(*NewForm);
        CEO.executeForm(*NewForm);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Fin des tests =====\n" << std::endl;
    return 0;
}