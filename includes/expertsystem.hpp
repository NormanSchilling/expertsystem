/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expertsystem.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:40:26 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/08 14:50:15 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERTSYSTEM_HPP
# define EXPERTSYSTEM_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

class ExpertSystem
{
	public:

		/*
		** CONSTRUCT & DESTRUCT
		*/
		ExpertSystem( void );
		ExpertSystem( ExpertSystem const & cpy );
		~ExpertSystem( void );

		/*
		** OPERATOR
		*/
		ExpertSystem &	operator=( ExpertSystem const & cpy );

		/*
		** METHOD
		*/
		void			fetch_parsing();
		void			parsing_init_fact(std::string line);
		void			parsing_init_queries(std::string line);

		/*
		** GETTER
		*/

	private:
		std::string		init_fact;
		std::string		init_queries;

};

#endif