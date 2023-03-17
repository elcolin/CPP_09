/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:24:53 by elise             #+#    #+#             */
/*   Updated: 2023/03/17 17:17:14 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <cstdlib>

struct Arg
{
	private:
		int		num;
		char	op;
	public:
		Arg();
		Arg(int &num, char op);
		~Arg();
		Arg &operator=(Arg const &a);
		Arg(Arg const &a);
		Arg(int num);
};
