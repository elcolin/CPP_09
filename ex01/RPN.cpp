/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:24:50 by elise             #+#    #+#             */
/*   Updated: 2023/04/17 15:19:00 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int do_op(int a, int b, char op)
{
    if (op == '*')
        return a * b;
    else if (op == '-')
        return a - b;
    else if (op == '/')
        return a / b;
    else if (op == '+')
        return a + b;
    std::cout << "WHAT?\n";
    exit(EXIT_FAILURE);
}

void print(std::list<int> &tab)
{
    std::list<int>::iterator it = tab.begin();
    while (it != tab.end())
    {
        std::cout << *it - '0' << " ";
        it++;
    }
    std::cout << "\n";
}

void errorin(int con, const char *err_msg)
{
	if (con)
	{
		std::cout << err_msg << std::endl;
		exit(EXIT_FAILURE);
	}
}

void	skip_space(char *str, int *i)
{
	while (str[*i] && str[*i] == ' ')
		(*i)++;
}
