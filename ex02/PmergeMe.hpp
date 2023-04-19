/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:28:56 by elise             #+#    #+#             */
/*   Updated: 2023/04/17 16:00:04 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <cmath>

unsigned long min(unsigned long a, unsigned long b);

void    errorin(int con, const char *msg);

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
};

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
};

#endif