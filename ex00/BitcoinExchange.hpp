/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:18:04 by elise             #+#    #+#             */
/*   Updated: 2023/04/17 15:58:16 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
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

int checkdate(std::string s);
int create_data(std::ifstream &file, std::map <std::string, float> &data);

#endif