#pragma once

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
private:
	
public:

	// shortening the names
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	// ===== Functions =====
	iterator begin() {
		return this->c.begin();
	}
	iterator end() {
		return this->c.end();
	}
	iterator begin() const {
		return this->c.begin();
	}
	iterator end() const {
		return this->c.end();
	}
};
