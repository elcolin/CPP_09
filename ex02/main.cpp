/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:12:21 by ecolin            #+#    #+#             */
/*   Updated: 2023/03/31 14:10:48 by elise            ###   ########.fr       */
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

unsigned long min(unsigned long a, unsigned long b)
{
    if (a < b)
        return a;
    return b;
}

template<typename T>
void merge_sort(T& arr, unsigned long min_threshold, unsigned long max_threshold) 
{
    if (arr.size() <= min_threshold) 
    { // insert
        for (unsigned long i = 1; i < arr.size(); i++)
        {
            for (unsigned long j = i; j > 0 && arr[j - 1] > arr[j]; j--)
                std::swap(arr[j-1], arr[j]);
        }
    }
    else if (arr.size() > max_threshold) //merge
    {
        T left;
        T right;
        unsigned long middle = arr.size() / 2;
    
        for (unsigned long i = 0; i < middle; i++)
            left.push_back(arr[i]);
        for (unsigned long i = middle; i < arr.size(); i++)
            right.push_back(arr[i]);

        max_threshold = min(sqrt(arr.size()), max_threshold);
        merge_sort(left, min_threshold, max_threshold);
        merge_sort(right, min_threshold, max_threshold);

        unsigned long i = 0;
        unsigned long j = 0;
        int k = 0;
    
        while (i < left.size() && j < right.size())
        {
            if (left[i] < right[j])
                arr[k++] = left[i++];
            else
                arr[k++] = right[j++];
        }
        while (i < left.size())
            arr[k++] = left[i++];
 
        while (j < right.size())
            arr[k++] = right[j++];
    }
}


void    errorin(int con, const char *msg)
{
    if (con)
    {
        std::cout << msg;
        exit(EXIT_FAILURE);
    }
    return;
}

template<typename T>
void print_arr(T &arr)
{
    typename T::iterator it;
    it = arr.begin();
    while(it != arr.end())
    {
        std::cout << " " << *it;
        it++;
    }
    std::cout << std::endl;
}

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

