/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 16:14:12 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/09 16:16:43 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_HPP
# define OPERATOR_HPP

class Operator
{
	public:

		/*
		** CONSTRUCT & DESTRUCT
		*/
		Operator( void );
		Operator( Operator const & cpy );
		~Operator( void );

		/*
		** OPERATOR
		*/
		Operator &	operator=( Operator const & cpy );

		/*
		** METHOD
		*/

		/*
		** GETTER
		*/

	private:
		string		value;
		int			weight;
};

#endif