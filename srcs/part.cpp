/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:50 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/11 16:00:34 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <part.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Part::Part( void )
{
	return ;
}

Part::Part( std::string part, std::vector<Fact*> init_fact ) : part(part)
{
	std::cout << part << std::endl;
	this->assign_fact_state(init_fact);
	return ;
}

Part::Part( Part const & cpy )
{
	*this = cpy;
}

Part::~Part( void )
{
	return ;
}

/*
** OPERATOR
*/
Part &	Part::operator=( Part const & cpy )
{
	if ( this == &cpy )
		return ( *this );

	// this->weight = cpy.getWeight();
	return ( *this );
}

/*
** METHOD
*/
void		Part::assign_fact_state(std::vector<Fact*> init_fact)
{
	int k;

	k = 0;
	for (unsigned long i = 0; i < init_fact.size(); i++)
	{
		std::cout << "BEFORE : " << init_fact[i]->getValue() << std::endl;
	}

	// for (int j = 0; this->part[j] != '\0'; j++)
	// {
	// 	if ( this->part[j] >= 'A' && this->part[j] <= 'Z')
	// 	{
	// 		k = 0;
	// 		for (unsigned long i = 0; i < init_fact.size(); i++)
	// 		{
	// 			if ( init_fact[i]->getValue() == this->part[j] )
	// 			{
	// 				std::cout << "IN : " << init_fact[i]->getValue() << std::endl;
	// 				k = -1;
	// 				break ;
	// 			}
	// 		}
	// 		if (k == 0)
	// 		{
	// 			std::cout <<  "OUT : " << this->part[j] << std::endl;
	// 			init_fact.push_back( new Fact( this->part[j], -2 ) );
	// 		}
	// 	}
	// }
}