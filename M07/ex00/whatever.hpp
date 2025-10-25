#pragma once

template<typename T>

void swap(T& arg1, T& arg2) {
	T temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

template<typename T>
const T& min(T& arg1, T& arg2) {
	return (arg1 < arg2 ? arg1 : arg2);
}

template<typename T>
const T& max(T& arg1, T& arg2) {
	return (arg1 > arg2 ? arg1 : arg2);
}

