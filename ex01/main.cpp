/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:25:10 by elise             #+#    #+#             */
/*   Updated: 2023/04/17 16:07:29 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
	errorin(argc != 2 || !argv[1][0], "Wrong Input.");
    int i = 0;
	int num = 0;
	int op = 0;
    std::list<int> tab;
	skip_space(argv[1], &i);
	errorin(!isdigit(argv[1][i]), "Input has a non-digit character.");
    tab.push_back(argv[1][i++]);
	errorin(argv[1][i] && argv[1][i] != ' ', "Wrong Input");
    while (argv[1][i])
    {
		skip_space(argv[1], &i);
		if (!argv[1][i])
			break;
        if ((isdigit(argv[1][i]) || strchr("*/-+", argv[1][i])) && argv[1][i - 1] == ' ')
		{
            tab.push_back(argv[1][i]);
			if (isdigit(argv[1][i]))
				num++;
			else
				op++;
		}
        else if (argv[1][i] != ' ' && argv[1][i])
			errorin(1, "Input has a non-digit character and is different then \" * / - + \"");
        i++;
    }
	errorin(num != op, "Wrong quantity of numbers and signs.");
    std::list<int>::iterator it = tab.begin();
    std::list <int>::iterator r = tab.begin();
    while (it != tab.end())
    {
        if (strchr("*/-+", *it) && it != r)
        {
            errorin(it == tab.begin() || it-- == tab.begin() || it-- == tab.begin(), "Invalid Input.");
            *it = do_op(*it++ - '0', *it++ - '0', *it) + '0';
            r = it;
            it--;
            tab.erase(it);
            it = r;
            it--;
            tab.erase(it);
            it = tab.begin();
        }
        it++;
    }
    std::cout << *tab.begin() - '0';
}