/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:25:10 by elise             #+#    #+#             */
/*   Updated: 2023/03/20 10:29:12 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//faire des exceptions

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

int main(int argc, char *argv[])
{
    if (argc != 2 || !argv[1][0] || !isdigit(argv[1][0]))
    {
        std::cout << "Bad Input.\n";
        exit(EXIT_FAILURE);
    }
    int i = 1;
    std::list<int> tab;
    tab.push_back(argv[1][0]);
    if (argv[1][i] != ' ')
        exit(EXIT_FAILURE);
    while (argv[1][i])
    {
        if ((argv[1][i] == ' ' && argv[1][i - 1] == ' '))
            exit(EXIT_FAILURE);
        if ((isdigit(argv[1][i]) || strchr("*/-+", argv[1][i])) && argv[1][i - 1] == ' ')
            tab.push_back(argv[1][i]);
        else if (argv[1][i] != ' ')
            exit(EXIT_FAILURE);
        i++;
    }
    std::list<int>::iterator it = tab.begin();
    std::list<int>::iterator tmp = tab.begin();
    std::list <int>::iterator r = tab.begin();
    while (it != tab.end())
    {
        if (strchr("*/-+", *it) && it != r)
        {
            it--;
            it--;
            *it = do_op(*it++ - '0', *it++ - '0', *it) + '0';
            r = it;
            it--;
            tmp = it--;
            tab.erase(it);
            tab.erase(tmp);
            it = tab.begin();
        }
        it++;
    }
    std::cout << *tab.begin() - '0';
}