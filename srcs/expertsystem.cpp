/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expertsystem.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:50 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/18 13:50:22 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expertsystem.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
ExpertSystem::ExpertSystem( void )
{
	return ;
}

ExpertSystem::ExpertSystem( ExpertSystem const & cpy )
{
	*this = cpy;
}

ExpertSystem::~ExpertSystem( void )
{
	return ;
}

/*
** OPERATOR
*/
ExpertSystem &	ExpertSystem::operator=( ExpertSystem const & cpy )
{
	if ( this == &cpy )
		return ( *this );

	return ( *this );
}

/*
** METHOD
*/

void			ExpertSystem::queries_answer()
{
	for (unsigned long i = 0; i < this->init_queries.size(); i++)
	{
		for (unsigned long k = 0; k < this->init_fact.size(); k++)
		{
			if ( this->init_queries[i]->getValue() == this->init_fact[k]->getValue() )
			{
				if (this->init_fact[k]->getState() == 1)
					std::cout << this->init_fact[k]->getValue() << " is true !" << std::endl;
				else if (this->init_fact[k]->getState() == 0 || this->init_fact[k]->getState() == -2)
					std::cout << this->init_fact[k]->getValue() << " is false !" << std::endl;
				else if (this->init_fact[k]->getState() == 2)
					std::cout << this->init_fact[k]->getValue() << " is undetermined !" << std::endl;
			}
		}
	}
}

int				ExpertSystem::check_contradictions()
{
	std::vector<int>	verif;
	std::string			numeric;
	int					number_bracket;

	for (unsigned long i = 0; i < this->init_fact.size(); i++)
		verif.push_back(this->init_fact[i]->getState());
	for (unsigned long i = 0; i < this->rules.size(); i++)
	{
		numeric = numerize(this->rules[i]->getOperation()->getPart());
		number_bracket = count_first_bracket(numeric);
		for (int j = 0; j < number_bracket; j++ )
			numeric = get_bracket(numeric);
		numeric = resolve_and(numeric);
		numeric = resolve_or(numeric);
		numeric = resolve_xor(numeric);
		set_initial_fact(numeric, this->rules[i]);
		for (unsigned long k = 0; k < this->init_fact.size(); k++)
		{
			if (this->init_fact[k]->getState() != verif[k])
				return (1);
		}
	}
	return (0);
}

void			ExpertSystem::set_impossible_fact(void)
{
	std::vector<char>	verif;
	std::string			result;
	int					found;

	for (unsigned long i = 0; i < this->rules.size(); i++)
	{
		result = this->rules[i]->getResult()->getPart();
		for (int j = 0; result[j]; j++)
		{
			if (result[j] >= 'A' && result[j] <= 'Z')
				verif.push_back(result[j]);
		}
	}

	for (unsigned long k = 0; k < this->init_fact.size() ; k++)
	{
		if (this->init_fact[k]->getState() == -2)
		{
			found = 0;
			for(unsigned long i = 0; i < verif.size(); i++)
			{
				if (this->init_fact[k]->getValue() == verif[i])
				{
					found = 1;
					break ;
				}
			}
			if (!found)
				this->init_fact[k]->setState(0);
		}
	}
}

void			ExpertSystem::expert()
{
	int				number_bracket;
	std::string		numeric;

	this->set_impossible_fact();
	this->get_rules_set();
	while (this->number_rules_set != this->rules.size() )
	{
		this->get_max_ratio();
		if (this->max_ratio != 0)
		{
			for (unsigned long i = 0; i < this->rules.size(); i++)
			{
				if (this->rules[i]->getSet() == 0 && this->max_ratio == this->rules[i]->getRatio())
				{
					numeric = numerize(this->rules[i]->getOperation()->getPart());
					number_bracket = count_first_bracket(numeric);
					for (int j = 0; j < number_bracket; j++ )
						numeric = get_bracket(numeric);
					numeric = resolve_and(numeric);
					numeric = resolve_or(numeric);
					numeric = resolve_xor(numeric);
					set_initial_fact(numeric, this->rules[i]);
					this->rules[i]->setSet(1);
				}
			}
		}
		else if (this->max_ratio == 0)
		{
			this->ma_bite();
			for (unsigned long i = 0; i < this->rules.size(); i++)
			{
				if (this->rules[i]->getSet() == 0 && this->max_ratio == this->rules[i]->getRatio())
				{
					numeric = numerize(this->rules[i]->getOperation()->getPart());
					number_bracket = count_first_bracket(numeric);
					for (int j = 0; j < number_bracket; j++ )
						numeric = get_bracket(numeric);
					numeric = resolve_and(numeric);
					numeric = resolve_or(numeric);
					numeric = resolve_xor(numeric);
					std::cout << "RULE = " << this->rules[i]->getRule() << std::endl;
					set_initial_fact(numeric, this->rules[i]);
					this->rules[i]->setSet(1);
				}
			}
		}
		this->get_rules_set();
	}
	if (!check_contradictions())
		this->queries_answer();
	else
		std::cout << "Some rules are conflicting !" << std::endl;
	return ;
}

int				ExpertSystem::check_rules_ratio(void)
{
	for (unsigned long i = 0; i < this->rules.size(); i++)
	{
		if (this->rules[i]->getSet() == 0 && this->max_ratio == 0)
		{

		}
	}
	return (0);
}

void			ExpertSystem::set_initial_fact(std::string numeric, Rule *rule)
{
	std::string		result = rule->getResult()->getPart();
	int				tmp;

	for (int i = 0; result[i]; i++)
	{
		if (result[i] >= 'A' && result[i] <= 'Z')
		{
			for (unsigned long k = 0; k < this->init_fact.size() ; k++)
			{
				if (this->init_fact[k]->getValue() == result[i])
				{
					tmp = static_cast<int>(numeric[0]) - 48;
					if (tmp == 1)
					{
						this->init_fact[k]->setState(tmp);
						if (i > 0)
						{
							if (result[i - 1] == '!' && tmp == 0)
								this->init_fact[k]->setState(1);
							else if (result[i - 1] == '!' && tmp == 1)
								this->init_fact[k]->setState(0);
						}
					}
				}
			}
		}
	}
}

void			ExpertSystem::get_rules_set()
{
	this->number_rules_set = 0;

	for (unsigned long i = 0; i < this->rules.size(); i++)
	{
		if (this->rules[i]->getSet() == 1)
			this->number_rules_set++;
	}
}

void			ExpertSystem::get_max_ratio(void)
{
	float	ratio_max = 0.f;
	int		ratio_nbr = 1;

	for (unsigned long i = 0; i < this->rules.size(); i++)
		this->rules[i]->count_truefact(this->rules[i]->getOperation()->getPart(), &(this->init_fact));

	for (unsigned long i = 0; i < this->rules.size(); i++)
	{
		if (this->rules[i]->getSet() == 0)
		{
			if (this->rules[i]->getRatio() > ratio_max)
			{
				ratio_max = this->rules[i]->getRatio();
				ratio_nbr = 1;
			}
			else if (this->rules[i]->getRatio() == ratio_max)
				ratio_nbr++;
		}
	}
	this->max_ratio = ratio_max;
	this->max_ratio_nbr = ratio_nbr;
}

void			ExpertSystem::ma_bite(void)
{
	float	ratio_max = 0.f;
	int		ratio_nbr = 1;

	for (unsigned long i = 0; i < this->rules.size(); i++)
		this->rules[i]->count_ratio_zero(this->rules[i]->getOperation()->getPart(), &(this->init_fact));

	for (unsigned long i = 0; i < this->rules.size(); i++)
	{
		if (this->rules[i]->getSet() == 0)
		{
			if (this->rules[i]->getRatio() > ratio_max)
			{
				ratio_max = this->rules[i]->getRatio();
				ratio_nbr = 1;
			}
			else if (this->rules[i]->getRatio() == ratio_max)
				ratio_nbr++;
		}
	}
	this->max_ratio = ratio_max;
	this->max_ratio_nbr = ratio_nbr;
}

std::string		ExpertSystem::resolve_and(std::string numeric)
{
	std::string		resolved(numeric.size(), 0);
	int				k = 0;

	for (int i = 0; numeric[i] != '\0'; i++)
	{
		if (numeric[i]  == '+')
		{
			k--;
			if (numeric[i - 1] == '1' && numeric[i + 1] == '1')
				resolved[k] = '1';
			else if (numeric[i - 1] == '0' || numeric[i + 1] == '0')
				resolved[k] = '0';
			else 
				resolved[k] = '2';
			i++;
		}
		else
			resolved[k] = numeric[i];
		k++;
	}
	return (resolved);
}

std::string		ExpertSystem::resolve_or(std::string numeric)
{
	std::string		resolved(numeric.size(), 0);
	int				k = 0;

	for (int i = 0; numeric[i] != '\0'; i++)
	{
		if (numeric[i]  == '|')
		{
			k--;
			if (numeric[i - 1] == '1' || numeric[i + 1] == '1')
				resolved[k] = '1';
			else if (numeric[i - 1] == '0' && numeric[i + 1] == '0')
				resolved[k] = '0';
			else 
				resolved[k] = '2';
			i++;
		}
		else
			resolved[k] = numeric[i];
		k++;
	}
	return (resolved);
}

std::string		ExpertSystem::resolve_xor(std::string numeric)
{
	std::string		resolved(numeric.size(), 0);
	int				k = 0;

	for (int i = 0; numeric[i] != '\0'; i++)
	{
		if (numeric[i]  == '^')
		{
			k--;
			if (numeric[i - 1] == '2' || numeric[i + 1] == '2')
				resolved[k] = '2';
			else if (numeric[i - 1] == numeric[i + 1])
				resolved[k] = '0';
			else
				resolved[k] = '1';
			i++;
		}
		else
			resolved[k] = numeric[i];
		k++;
	}
	return (resolved);
}

std::string			ExpertSystem::get_bracket(std::string numeric)
{
	std::string		bracket(numeric.size(), 0);
	std::string		new_numeric(numeric.size(), 0);
	int				k = 0;
	int				count = 0;

	for (int i = 0; numeric[i] != '\0'; i++)
	{
		if (numeric[i] == '(')
		{
			bracket = simplification_bracket(numeric, i);
			break ;
		}	
	}

	for (int i = 0; numeric[i] != '\0'; i++)
	{
		if (numeric[i] == '(' && count == 0)
		{
			while (numeric[i] != ')')
				i++;
			new_numeric[k] = resolve_bracket(bracket);
			count++;
		}
		else
			new_numeric[k] = numeric[i];
		k++;
	}

	return (new_numeric);
}

std::string		ExpertSystem::simplification_bracket(std::string numeric, int c)
{
	std::string		tmp(numeric.size(), 0);
	int				j;

	j = 0;
	c++;
	for (int i = c; numeric[i] != ')'; i++)
	{
		tmp[j] = numeric[i];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

std::string		ExpertSystem::numerize(std::string part)
{
	int				j;
	int 			k = 0;
	int				state;
	std::string		numeric(part.size(), 0);

	for (int i = 0; part[i]; i++)
	{
		if (part[i] == '!' && part[i + 1] && part[i + 1] >= 'A' && part[i + 1] <= 'Z')
			i++;
		if (part[i] >= 'A' && part[i] <= 'Z')
		{
			j = 0;
			while (this->init_fact[j]->getValue() != part[i])
				j++;
			state = this->init_fact[j]->getState();

			if (state == -1)
				part[i] = '2';
			else if (i == 0 || part[i - 1] != '!')
			{
				if (state == 0 || state == -2)
					part[i] = '0';
				else if (state == 1)
					part[i] = '1';
			}
			else
			{
				if (state == 0 || state == -2)
					part[i] = '1';
				else if (state == 1)
					part[i] = '0';
			}
		}
		numeric[k] = part[i];
		k++;
	}
	return (numeric);
}


char		ExpertSystem::resolve_bracket(std::string bracket)
{
	std::string		numeric;

	numeric = resolve_and(bracket);
	numeric = resolve_or(numeric);
	numeric = resolve_xor(numeric);

	return (numeric[0]);
}

void			ExpertSystem::fetch_init_fact()
{
	std::cout << "FETCH_INIT_FACT" << std::endl;
	for (unsigned long i = 0; i < this->init_fact.size(); i++)
	{
		std::cout << this->init_fact[i]->getValue() << " =  " << this->init_fact[i]->getState() << std::endl;
	}
}

void			ExpertSystem::fetch_init_queries()
{
	for (unsigned long i = 0; i < this->init_queries.size(); i++)
	{
		std::cout << this->init_queries[i]->getValue() << std::endl;
		std::cout << this->init_queries[i]->getState() << std::endl;
	}
}

void			ExpertSystem::fetch_rules()
{
	for (unsigned long i = 0; i < this->rules.size(); i++)
	{
		std::cout << this->rules[i]->getRule() << std::endl;
	}
}

int				ExpertSystem::check_syntax_rule(std::string line)
{
	std::string				tmp;
	std::smatch				m;
	std::regex				e( "#" );
	std::regex				c( "([\\s]{0,1}[(]{0,1}[!]{0,1}[A-Z]{1,1}[)]{0,1}[\\s]{0,1}[+^|]{0,1}[\\s]{0,1})*[<]{0,1}[=]{1,1}[>]{1,1}([\\s]{0,1}[!]{0,1}[A-Z]{1,1}[\\s]{0,1}[+]{0,1}[\\s]{0,1})*" );

	if ( line[0] != '\n' && line[0] != '\0' && line[0] != '=' && line[0] != '?')
	{
		std::regex_search( line, m, e );
		tmp = line.substr( 0, m.position(0) );
		if (std::regex_match (tmp, c))
		{
			if (this->count_first_bracket(tmp) == this->count_second_bracket(tmp))
				this->rules.push_back( new Rule( tmp, &(this->init_fact) ) );
			else
			{
				std::cout << "error syntax : " << tmp << std::endl;
				exit(-1);
			}
		}
		else
		{
			std::cout << "error syntax : " << tmp << std::endl;
			exit(-1);
		}
	}
	return (0);
}

int				ExpertSystem::count_first_bracket(std::string tmp)
{
	int		count = 0;

	for (int i = 0; tmp[i] != '\0'; i++)
	{
		if (tmp[i] == '(')
			count++;
	}
	return (count);
}

int				ExpertSystem::count_second_bracket(std::string tmp)
{
	int		count = 0;

	for (int i = 0; tmp[i] != '\0'; i++)
	{
		if (tmp[i] == ')')
			count++;
	}
	return (count);
}

void	 		ExpertSystem::parsing_init_fact(std::string line)
{
	std::string				tmp;
	std::smatch				m;
	std::regex				e( "#" );

	if ( line[0] == '=')
	{
		std::regex_search( line, m, e );
		tmp = line.substr( 0, m.position(0) );
		for (int i = 1; tmp[i]; i++)
		{
			if ( tmp[i] >= 'A' && tmp[i] <= 'Z')
			{
				this->init_fact.push_back( new Fact( tmp[i], 1 ) );
			}
		}
	}
}

void	 		ExpertSystem::parsing_init_queries(std::string line)
{
	std::string				tmp;
	std::smatch				m;
	std::regex				e( "#" );

	if ( line[0] == '?')
	{
		std::regex_search( line, m, e );
		tmp = line.substr( 0, m.position(0) );
		for (int i = 1; tmp[i]; i++)
		{
			if ( tmp[i] >= 'A' && tmp[i] <= 'Z')
			{
				this->init_queries.push_back( new Fact( tmp[i], -2 ) );
			}
		}
	}
}