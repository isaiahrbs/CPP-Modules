#pragma once

#include <string>
#include <iostream>

template<typename T>
class Array
{
private:
	// ===== Private Members =====
	T* array;
	

protected:
	// ===== Protected Members =====

public:
	// ===== Canonical Form =====
	Array(); // creates empty array
	Array(unsigned int n); // creates array of N elements
	Array(const Array& other); // copy other array
	~Array();
	
	// ===== Setters =====
	Array& operator=(const Array& other);

	// ===== Getters =====

	// ===== Abstract Functions =====

	// ===== Other Classes/Types =====

	// ===== Friends =====

	// ===== Static Members =====

};
