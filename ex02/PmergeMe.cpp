/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:00:21 by elise             #+#    #+#             */
/*   Updated: 2023/04/17 15:25:58 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

unsigned long min(unsigned long a, unsigned long b)
{
    if (a < b)
        return a;
    return b;
}

void    errorin(int con, const char *msg)
{
    if (con)
    {
        std::cout << msg;
        exit(EXIT_FAILURE);
    }
    return;
}