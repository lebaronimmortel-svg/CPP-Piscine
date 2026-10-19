/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int power(int src, int pow)
{
    int i = 1;
    int res = src;

    if (pow == 0)
        return (1);

    while (i < pow)
    {
        res = src * res;
        i++;
    }

    return (res);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (1000000 * tv.tv_sec + tv.tv_usec);
}

void vector_sort(char **argv)
{
    PmergeMe<std::vector <int> > vect_instance;
    std::vector <int> losers;
    std::vector <int> sorted;

    try
    {
        vect_instance.fill(argv);
        std::cout << "Before: " << std::endl;
        vect_instance.print(vect_instance.getSeq());
        split<std::vector <int> > in = {vect_instance.getSeq(), losers};
        vect_instance.setStart(get_time());
        sorted = vect_instance.sort(in).winners;
        long span = get_time() - vect_instance.getStart();
        std::cout << "After: " << std::endl;
        vect_instance.print(sorted);
        std::cout << "time to process a range of " << vect_instance.getSeq().size() << " elements with std::vector : " << span << " us" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << BOLD BLUE << "Error <vector>:\n" << RESET << e.what() << std::endl;
    }
}

void deque_sort(char **argv)
{
    PmergeMe<std::deque <int> > deque_instance;
    std::deque <int> losers;
    std::deque <int> sorted;

    try
    {
        deque_instance.fill(argv);
        deque_instance.setStart(get_time());
        split<std::deque <int> > in = {deque_instance.getSeq(), losers};
        sorted = deque_instance.sort(in).winners;
        long span = get_time() - deque_instance.getStart();
        std::cout << "time to process a range of " << deque_instance.getSeq().size() << " elements with std::deque : " << span << " us" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << BOLD BLUE << "Error <deque>:\n" << RESET << e.what() << std::endl;
    }
}