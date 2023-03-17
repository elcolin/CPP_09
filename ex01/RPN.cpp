/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:24:50 by elise             #+#    #+#             */
/*   Updated: 2023/03/17 17:17:32 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Arg::Arg(int &num, char op): num(num), op(op)
{
	
}

Arg::Arg(): num(11), op('\0')
{
	
}

Arg::~Arg()
{
	
}

Arg::Arg(int num): num(num)
{
	op = '\0';
}

Arg::Arg(Arg const &a): num(a.num), op(a.op)
{
	
}

Arg &Arg::operator=(Arg const &a)
{
	this->num = a.num;
	this->op = a.op;
	return (*this);
}