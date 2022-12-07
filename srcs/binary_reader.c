/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:17:25 by awallet           #+#    #+#             */
/*   Updated: 2022/12/07 18:08:48 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <binary.h>
#include <stdint.h>

int	ft_rbool(t_chaineoctet *self)
{
	int	res;

	res = self->buffer[self->pos++];
	return (res);
}

int	ft_rbyte(t_chaineoctet *self)
{
	int	res;

	res = (self->buffer[self->pos++] & 0xFF);
	return (res);
}

short	ft_rshort(t_chaineoctet *self)
{
	short	res;

	res = ((self->buffer[self->pos++] & 0xFF) << 8);
	res |= (self->buffer[self->pos++] & 0xFF);
	return (res);
}

int	ft_rint(t_chaineoctet *self)
{
	int	res;

	res = ((self->buffer[self->pos++] & 0xFF) << 24);
	res |= ((self->buffer[self->pos++] & 0xFF) << 16);
	res |= ((self->buffer[self->pos++] & 0xFF) << 8);
	res |= (self->buffer[self->pos++] & 0xFF);
	return (res);
}

unsigned long	ft_rlong(t_chaineoctet *self)
{
	unsigned long	res;

	res = ((uint64_t)(self->buffer[self->pos++] & 0xFF) << 56);
	res |= ((uint64_t)(self->buffer[self->pos++] & 0xFF) << 48);
	res |= ((uint64_t)(self->buffer[self->pos++] & 0xFF) << 40);
	res |= ((uint64_t)(self->buffer[self->pos++] & 0xFF) << 32);
	res |= ((self->buffer[self->pos++] & 0xFF) << 24);
	res |= ((self->buffer[self->pos++] & 0xFF) << 16);
	res |= ((self->buffer[self->pos++] & 0xFF) << 8);
	res |= (self->buffer[self->pos++] & 0xFF);
	return (res);
}
