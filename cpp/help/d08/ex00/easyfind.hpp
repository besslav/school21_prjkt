/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:33:43 by drayl             #+#    #+#             */
/*   Updated: 2022/03/28 22:33:44 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

template<typename T>
typename T::iterator easyfind(T &array, int element) {
    typename T::iterator result = find(array.begin(), array.end(), element);
    if (result == array.end())
        throw std::exception();
    return (result);
}

#endif
