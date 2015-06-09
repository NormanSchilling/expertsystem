/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:34:37 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/09 17:05:05 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expertsystem.hpp"

int		main(int argc, char **argv)
{
	ExpertSystem	*e = new ExpertSystem();
	std::string		line;

	if ( argc == 2 )
	{
		std::ifstream	file( argv[1] );
		while ( std::getline( file, line ) )
		{
			if ( line[0] != '#' )
			{
				e->parsing_init_fact(line);
				// e->parsing_init_queries(line);
			}
		}
		e->fetch_init_fact();
		delete(e);
	}
	else
		return (-1);
	return (0);
}
