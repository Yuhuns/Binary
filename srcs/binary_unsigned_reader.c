/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_unsigned_reader.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:07:00 by awallet           #+#    #+#             */
/*   Updated: 2022/06/02 19:28:53 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary.h"

unsigned int	ft_rubyte(t_chaineoctet *self)
{
	unsigned int	x;

	x = ft_rbyte(self);
	if (x > 127)
		x = x - 256;
	return (x);
}

unsigned int	ft_rushort(t_chaineoctet *self)
{
	unsigned int	x;

	x = ft_rshort(self);
	if (x > 32767)
		x = x - 65536;
	return (x);
}
