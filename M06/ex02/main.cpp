#include "Base.hpp"
#include "BaseA.hpp"
#include "BaseB.hpp"
#include "BaseC.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void);
void printType(Base* ptr);
void	identify(Base* p);
void	identify(Base &p);

int main()
{
    std::srand(time(0));
    Base* ptr = generate();

    printType(ptr);
    identify(ptr);
    identify(*ptr);
    std::cout << std::endl;

    char letter = 'A';  // 1 byte: [65]
    int* bad_ptr = reinterpret_cast<int*>(&letter);
    int result = *bad_ptr;

    std::cout << result << std::endl;

    char* caca_ptr = reinterpret_cast<char*>(&result);
    std::cout << *caca_ptr << std::endl;
}