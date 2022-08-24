/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:51:04 by drayl             #+#    #+#             */
/*   Updated: 2022/03/27 19:51:05 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Invalid argument" << std::endl;
        return (1);
    }
    Convert convert = Convert(argv[1]);
    convert.printValue();
}
