/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:25:10 by elise             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/18 18:34:37 by elise            ###   ########.fr       */
=======
/*   Updated: 2023/03/17 17:28:48 by ecolin           ###   ########.fr       */
>>>>>>> e29fa65f1e2eff51dc44fc566632c1eb6af85e86
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
<<<<<<< HEAD
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
=======
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
>>>>>>> e29fa65f1e2eff51dc44fc566632c1eb6af85e86
}