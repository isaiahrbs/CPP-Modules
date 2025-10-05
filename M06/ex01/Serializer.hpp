#pragma once

#include <string>
#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
		// ===== Private Members =====
		Serializer();
		Serializer(const std::string& target);
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();
		

	protected:
		// ===== Protected Members =====

	public:
		// ===== Canonical Form =====

		// ===== Setters =====
		
		//It takes a pointer and converts it to the unsigned integer type uintptr_t.
		static uintptr_t serialize(Data* ptr);

		//It takes an unsigned integer parameter and converts it to a pointer to Data.
		static Data* deserialize(uintptr_t raw);

		// ===== Getters =====

		// ===== Abstract Functions =====

		// ===== Other Classes/Types =====

		// ===== Friends =====

		// ===== Static Members =====

};
