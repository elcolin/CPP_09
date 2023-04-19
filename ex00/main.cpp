/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:17:36 by elise             #+#    #+#             */
/*   Updated: 2023/04/16 16:54:21 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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