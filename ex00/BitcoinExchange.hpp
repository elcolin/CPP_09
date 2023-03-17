/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:18:04 by elise             #+#    #+#             */
/*   Updated: 2023/03/14 15:55:27 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <map>

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
