/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:17:36 by elise             #+#    #+#             */
/*   Updated: 2023/03/14 17:09:30 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::ifstream	get_file(std::string file_name)
{
	std::string tmp;
	std::string txt;
	std::ifstream file(file_name.c_str());
	
	if (!file.is_open())
    {
        std::cout << "Unable to open file";
        exit(EXIT_FAILURE);
    }
	return (file);
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
            data[tmp.substr(0, pos)] = stof(tmp.substr(pos + 1));
        }
        catch (std::exception &e)
        {
            std::cout << "/!\\ " << tmp << " -> " << e.what() << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Wrong input file.\n";
        exit(EXIT_FAILURE);
    }
    std::ifstream data_file = get_file("data.csv");
    std::ifstream input_file = get_file(argv[1]);
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
            if (pos == tmp.npos)
                throw(BadInput());
            bc = stof(tmp.substr(pos + 3));
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