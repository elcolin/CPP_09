/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:49:51 by elise             #+#    #+#             */
/*   Updated: 2023/04/16 16:51:13 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int checkdate(std::string s)
{
	struct tm date;
	size_t pos = s.find("-");
	if (pos == s.npos || !pos)
		return (0);
	date.tm_year = atoi(s.substr(0, pos).c_str());
	s = &s[pos + 1];
	pos = s.find("-");
	if (pos == s.npos || date.tm_year <= 0 || !pos)
		return (0);
	date.tm_mon = atoi(s.substr(0, pos).c_str());
	s = &s[pos + 1];
	pos = s.find("-");
	if (pos != s.npos || date.tm_mon <= 0)
		return (0);
	date.tm_mday = atoi(s.c_str());
	if ((date.tm_mday > 30 && (date.tm_mon != 1 && 3 && 5 && 7 && 8 && 10 && 12)) || (date.tm_mon == 2 && date.tm_mday > 28) || date.tm_mon > 12 || date.tm_year < 2009 || date.tm_mday <= 0 || date.tm_mday > 31)
		return (0);
	return (1);
}

int create_data(std::ifstream &file, std::map <std::string, float> &data)
{
    size_t pos;
    std::string tmp;

    getline(file, tmp);
    while(getline(file, tmp))
    {
        pos = tmp.find(",");
        if (pos == tmp.npos)
        {
            std::cout << tmp << "Bad input\n";
            return 1;
        }
        try { 
            data[tmp.substr(0, pos)] = atof(tmp.substr(pos + 1).c_str());
        }
        catch (std::exception &e)
        {
            std::cout << "/!\\ " << tmp << " -> " << e.what() << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}
