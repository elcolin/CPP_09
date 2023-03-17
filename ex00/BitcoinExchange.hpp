/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:18:04 by elise             #+#    #+#             */
/*   Updated: 2023/03/17 16:54:27 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>

class BadInput: public std::exception
{
    const char *what() const throw()
    {
        return ("Bad input");
    }
};

class NegNum: public std::exception
{
    const char *what() const throw()
    {
        return ("Not a positive number");
    }
};

class TooHighNum: public std::exception
{
    const char *what() const throw()
    {
        return ("Number too high");
    }
};
