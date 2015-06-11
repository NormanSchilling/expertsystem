/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 16:18:56 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/11 15:59:53 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PART_HPP
# define PART_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <operation.hpp>

class Part
{
	public:

		/*
		** CONSTRUCT & DESTRUCT
		*/
		Part( void );
		Part(std::string part, std::vector<Fact*> init_fact);
		Part( Part const & cpy );
		~Part( void );

		/*
		** OPERATOR
		*/
		Part &	operator=( Part const & cpy );

		/*
		** METHOD
		*/
		void		assign_fact_state(std::vector<Fact*> init_fact);

	private:
		std::string		part;		
		Operation 		operation;

};

#endif