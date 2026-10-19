/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	capitalize(char *str)
{
	int i;
	
	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	int i;
	
	if (argc == 1)
	{
		std::cout << ("* LOUD AND UNBEARABLE FEEDBACK NOISE *\n");
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		capitalize(argv[i]);
		std::cout << (argv[i]);
		i++;
	}
	std::cout << "\n";
	return (0);
}
