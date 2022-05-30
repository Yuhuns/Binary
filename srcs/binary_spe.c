/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_spe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:52:06 by awallet           #+#    #+#             */
/*   Updated: 2022/05/30 20:57:38 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary.h"

void	ft_ecr(struct s_chaineoctet *self, int entier)
{
	int	rest;
	int	has_more;
	int	end;
	int	spe;

	if (isnan(entier))
		entier = 0;
	rest = entier >> 7;
	has_more = TRUE;
	if ((entier & 0x80000000) == 0)
		end = 0;
	else
		end = -1;
	while (has_more)
	{
		has_more = (rest != end) || ((rest & 1) != ((entier >> 6) & 1));
		if (has_more)
			spe = 0x80;
		else
			spe = 0;
		self->len++;
		self->buffer[self->pos++] = (entier & 0x7F) | (spe);
		entier = rest;
		rest >>= 7;
	}
}

signed int	ft_lec(struct s_chaineoctet *self)
{
	signed int	result;
	signed int	cur;
	signed int	count;
	signed int	sign_bits;

	result = 0;
	cur = 0;
	count = 0;
	sign_bits = -1;
	cur = ft_rbyte(self);
	result |= (cur & 0x7F) << (count * 7);
	sign_bits <<= 7;
	count++;
	while (((cur & 0x80) == 0x80) && count < 5)
	{
		cur = ft_rbyte(self);
		result |= (cur & 0x7F) << (count * 7);
		sign_bits <<= 7;
		count++;
	}
	if (((sign_bits >> 1) & result) != 0)
		result |= sign_bits;
	return (result);
}
