/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:33:01 by drayl             #+#    #+#             */
/*   Updated: 2022/03/28 22:33:03 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACH_HPP
# define MUTANTSTACH_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator rev_iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_rev_iterator;

    iterator rbegin() { return (this->c.begin()); }

    iterator rend() { return (this->c.end()); }

    const_iterator rbegin() const { return (this->c.begin()); }

    const_iterator rend() const { return (this->c.end()); }

    rev_iterator begin() { return (this->c.rbegin()); }

    rev_iterator end() { return (this->c.rend()); }

    const_rev_iterator begin() const { return (this->c.rbegin()); }

    const_rev_iterator end() const { return (this->c.rend()); }
};

#endif
