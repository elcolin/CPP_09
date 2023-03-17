/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:25:10 by elise             #+#    #+#             */
/*   Updated: 2023/03/17 17:28:48 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"



int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Bad Input.\n";
        exit(EXIT_FAILURE);
    }
    std::string s = argv[1];
    size_t  pos = s.find_first_not_of(' ');
    std::vector<int> tab;
	std::ve
    pos = s.find_first_not_of(' ');
    while (pos != s.npos)
    {
        if (isdigit(s[pos]))
        {
            if (std::atoi(&s[pos]) > 10)
            {
                std::cout << "Bad Input.\n";
                exit(EXIT_FAILURE);
            }
            tab.push_back(Arg(std::atoi(&s[pos])));
        }
        else
        {
            if (s[pos] == '*' || s[pos] == '/' || s[pos] == '+' || s[pos] == '-')
            {
				
			}
            else
            {
                std::cout << "Bad Input.\n";
                exit(EXIT_FAILURE);
            }
        }
        s = &s[pos + 1];
        pos = s.find_first_not_of(' ');
    }
}