/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:24:53 by elise             #+#    #+#             */
/*   Updated: 2023/04/17 15:59:23 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <list>
#include <cstdlib>

void print(std::list<int> &tab);
void errorin(int con, const char *err_msg);
void	skip_space(char *str, int *i);
int do_op(int a, int b, char op);

#endif