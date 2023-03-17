/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:17:36 by elise             #+#    #+#             */
/*   Updated: 2023/03/17 16:54:57 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Wrong input file.\n";
        exit(EXIT_FAILURE);
    }
	std::ifstream data_file("data.csv");
    std::ifstream input_file(argv[1]);
	if (!data_file.is_open() || !input_file.is_open())
	{
		std::cout << "Wrong input file.\n";
        exit(EXIT_FAILURE);
	}
    std::map <std::string, float> data;
    if(create_data(data_file, data))
    {
        std::cout << "Data creation failed.\n";
        exit(EXIT_FAILURE);
    }
    std::string tmp;
    size_t pos = 0;
    float  bc = -1;
    std::map<std::string, float>::iterator it;
    while(getline(input_file, tmp))
    {
        pos = tmp.find(" | ");
        try {
            if (pos == tmp.npos || !checkdate(tmp.substr(0, pos)))
                throw(BadInput());
            bc = atof(tmp.substr(pos + 3).c_str());
            if (bc > 100)
                throw(TooHighNum());
            else if (bc < 0)
                throw(NegNum());
            it = data.upper_bound(tmp.substr(0, pos));
            if (it == data.begin() && data.find(tmp.substr(0, pos)) == data.end())
                throw(BadInput());
            std::cout << tmp.substr(0, pos) << " => " << tmp.substr(pos + 3) << " = " << (--it)->second * bc << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "/!\\ " << tmp << " -> " << e.what() << std::endl;
        }
    }
    data_file.close();
    input_file.close();
}