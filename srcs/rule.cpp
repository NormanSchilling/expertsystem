/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:50 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/16 16:55:30 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rule.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Rule::Rule( void )
{
	return ;
}

Rule::Rule( std::string rule, std::vector<Fact*> *init_fact ) : rule(rule)
{
	std::string				operation;
	std::string				sign;
	std::string				result;
	std::smatch				m;
	std::regex				e( "<=>|=>" );


	this->set = 0;
	this->number_fact = 0.f;
	std::regex_search( this->rule, m, e );
	operation = this->rule.substr(0, m.position(0) );
	operation.erase(std::remove(operation.begin(), operation.end(), ' '), operation.end());

	for (int i = 0; operation[i] != '\0'; i++)
	{
		if (operation[i] >= 'A' && operation[i] <= 'Z')
			this->number_fact++;
	}
	count_truefact(operation, init_fact);
	sign = this->rule.substr(m.position(0), 3 );
	sign.erase(std::remove(sign.begin(), sign.end(), ' '), sign.end());
	result = this->rule.substr(m.position(0) + 3, m.position(1) );
	result.erase(std::remove(result.begin(), result.end(), ' '), result.end());

	this->operation = new Part( operation, init_fact );
	this->result = new Part( result, init_fact );
	return ;
}


Rule::Rule( Rule const & cpy )
{
	*this = cpy;
}

Rule::~Rule( void )
{
	return ;
}

/*
** OPERATOR
*/
Rule &	Rule::operator=( Rule const & cpy )
{
	if ( this == &cpy )
		return ( *this );

	return ( *this );
}

/*
** METHOD
*/
void		Rule::count_truefact(std::string operation, std::vector<Fact*> *init_fact)
{
	this->number_truefact = 0.f;

	for (int i = 0; operation[i]; i++)
	{
		if (operation[i] >= 'A' && operation[i] <= 'Z')
		{
			for (unsigned long k = 0; k < init_fact->size(); k++)
			{
				if ((*init_fact)[k]->getValue() == operation[i] && (*init_fact)[k]->getState() >= 0)
					this->number_truefact++;
			}
		}
	}
	this->ratio = this->number_truefact / this->number_fact;
}

/*
** GETTER
*/
std::string	Rule::getRule(void)
{
	return (this->rule);
}

int			Rule::getSet(void)
{
	return (this->set);
}

Part		*Rule::getOperation(void)
{
	return (this->operation);
}

Part		*Rule::getResult(void)
{
	return (this->result);
}

float		Rule::getRatio(void)
{
	return (this->ratio);
}

int			Rule::getNumberFact(void)
{
	return (this->number_fact);
}


/*
** SETTER
*/
void		Rule::setSet(int value)
{
	this->set = value;
}
