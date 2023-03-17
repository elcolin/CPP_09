/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:25:10 by elise             #+#    #+#             */
/*   Updated: 2023/03/15 17:51:44 by elise            ###   ########.fr       */
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
    std::vector<int> num;
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
            num.push_back(s[pos]);
        }
        else
        {
            if (s[pos] == '*' || s[pos] == '/' || s[pos] == '+' || s[pos] == '-')
                num.push_back(s[pos]);
            else
            {
                std::cout << "Bad Input.\n";
                exit(EXIT_FAILURE);
            }
        }
        s = &s[pos + 1];
        pos = s.find_first_not_of(' ');
    }
    std::vector<int>::iterator it = num.begin();
    int tmp = 0;
    int res = 0;
    while(it != num.end())
    {
        
        it++;
    }
}