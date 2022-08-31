//
// Created by Price Skip on 8/28/22.
//

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
# include <stack>

template<typename T>
class MutantStack: public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator rbegin() { return (this->c.begin()); }
	iterator rend() { return (this->c.end()); }

	typedef typename std::stack<T>::container_type::reverse_iterator rev_iterator;
	rev_iterator begin() { return (this->c.rbegin()); }
	rev_iterator end() { return (this->c.rend()); }
};


#endif //MUTANTSTACK_H
