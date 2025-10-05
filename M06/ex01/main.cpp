#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
	Data data;
	data.value = 42;

	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);

	std::cout << "Original address: " << &data << std::endl;
    std::cout << "Deserialized address: " << ptr << std::endl;
    std::cout << "Value: " << ptr->value << std::endl;

	if (ptr == &data)
        std::cout << "Success: Pointers match!" << std::endl;
    else
        std::cout << "Error: Pointers do not match!" << std::endl;

}