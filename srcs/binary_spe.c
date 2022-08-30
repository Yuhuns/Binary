/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_spe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:52:06 by awallet           #+#    #+#             */
/*   Updated: 2022/08/30 16:53:55 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary.h"

static unsigned int	ft_hasmore(int rest, int end, int entier)
{
	return (rest != end || ((rest & 1) != ((entier >> 6) & 1)));
}

static signed int	ft_sign(signed int s_b, signed int res)
{
	if (((s_b >> 1) & res) != 0)
		res |= s_b;
	return (res);
}

void	ft_ecr(t_chaineoctet *self, int entier)
{
	int	rest;
	int	has_more;
	int	end;
	int	spe;

	rest = entier >> 7;
	has_more = TRUE;
	if ((entier & 0x80000000) == 0)
		end = 0;
	else
		end = -1;
	while (has_more)
	{
		has_more = ft_hasmore(rest, end, entier);
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

signed int	ft_lec(t_chaineoctet *self)
{
	signed int	result;
	signed int	cur;
	signed int	count;
	signed int	sign_bits;

	result = 0;
	cur = 0;
	count = 0;
	sign_bits = -1;
	if (cur == 0)
	{
		cur = ft_rbyte(self);
		result |= (cur & 0x7F) << (count * 7);
		sign_bits <<= 7;
		count++;
	}
	while (((cur & 0x80) == 0x80) && count < 5)
	{
		cur = ft_rbyte(self);
		result |= (cur & 0x7F) << (count * 7);
		sign_bits <<= 7;
		count++;
	}
	result = ft_sign(sign_bits, result);
	return (result);
}
