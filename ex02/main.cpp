/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:12:21 by ecolin            #+#    #+#             */
/*   Updated: 2023/04/17 15:41:55 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <cmath>


int main(int argc, char* argv[]) 
{
    errorin(argc < 2, "Error: No integer sequence provided\n");
    errorin(argc >= 3002, "Error: Sequence above 3000 numbers\n");
    std::deque<int> deque_sequence;
    std::vector<int> vector_sequence;
    for (int i = 1; i < argc; i++)
    {
        int num = std::atoi(argv[i]);
        errorin(num <= 0, "Error: Invalid input argument.\n");
        deque_sequence.push_back(num);
        vector_sequence.push_back(num);
    }

    std::cout << "Before:";
    print_arr(deque_sequence);
    unsigned long min_threshold = log2(deque_sequence.size());
    unsigned long max_threshold = sqrt(vector_sequence.size());

    //deque sorting
    std::clock_t start = std::clock();
    merge_sort(deque_sequence, min_threshold, max_threshold);
    std::clock_t end = std::clock();
    double deque_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "After:";
    print_arr(deque_sequence);
    std::cout << "Time to process a range of " << deque_sequence.size() << " elements with std::deque: " << deque_time << " s" << std::endl;
    
    //vector sorting
    start = std::clock();
    merge_sort(vector_sequence, min_threshold, max_threshold);
    end = std::clock();
    double vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "After:";
    print_arr(vector_sequence);
    std::cout << "Time to process a range of " << vector_sequence.size() << " elements with std::vector: " << vector_time << " s" << std::endl;
    return 0;
}

