#pragma once

#include <iostream>
#include <cstddef>

template<typename T>
class Array
{
private:
	// ===== Private Members =====
	T* array;
	unsigned int len;
	

protected:
	// ===== Protected Members =====

public:
	// ===== Canonical Form =====
	Array(); // creates empty array
	Array(unsigned int n); // creates array of N elements
	Array(const Array& other); // copy other array
	~Array();
	
	// ===== Operators =====
	Array& operator=(const Array& other);
	const T& operator[](unsigned int i) const;
	T& operator[](unsigned int i);

	// ===== Setters =====

	// ===== Getters =====

	// ===== Abstract Functions =====

	// ===== Other Classes/Types =====
	class PassedArrayLimit : std::exception {
		virtual const char* what() const throw(); 
	}

	// ===== Friends =====

	// ===== Static Members =====

};
