//
// Created by Price Skip on 8/27/22.
//

#ifndef EASYFIND_H
#define EASYFIND_H

#include "iostream"

template<typename T>
typename T::iterator easyfind(T &array, int elem)
{
	typename T::iterator res = find(array.begin(), array.end(), elem);
	if (res == array.end())
		throw std::exception();
	return (res);
}

#endif //EASYFIND_H
