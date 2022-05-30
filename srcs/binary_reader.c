/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:17:25 by awallet           #+#    #+#             */
/*   Updated: 2022/05/30 15:42:52 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary.h"

unsigned int	ft_rbool(struct s_chaineoctet *self)
{
	if (self->pos + 1 > self->len)
		ft_bufferoverflow();
	return (self->buffer[self->pos++]);
}

signed int	ft_rbyte(struct s_chaineoctet *self)
{
	if (self->pos + 1 > self->len)
		ft_bufferoverflow();
	return (self->buffer[self->pos++] & 0xFF);
}

signed short	ft_rshort(struct s_chaineoctet *self)
{
	if (self->pos + 2 > self->len)
		ft_bufferoverflow();
	return ((self->buffer[self->pos++] & 0xFF) << 8
		| (self->buffer[self->pos++] & 0xFF));
}

signed int	ft_rint(struct s_chaineoctet *self)
{
	if (self->pos + 4 > self->len)
		ft_bufferoverflow();
	return ((self->buffer[self->pos++] & 0xFF) << 24
		| (self->buffer[self->pos++] & 0xFF) << 16
		| (self->buffer[self->pos++] & 0xFF) << 8
		| (self->buffer[self->pos++] & 0xFF));
}

signed long int	ft_rlong(struct s_chaineoctet *self)
{
	if (self->pos + 8 > self->len)
		ft_bufferoverflow();
	return ((self->buffer[self->pos++] & 0xFF) << 56
		| (self->buffer[self->pos++] & 0xFF) << 48
		| (self->buffer[self->pos++] & 0xFF) << 40
		| (self->buffer[self->pos++] & 0xFF) << 32
		| (self->buffer[self->pos++] & 0xFF) << 24
		| (self->buffer[self->pos++] & 0xFF) << 16
		| (self->buffer[self->pos++] & 0xFF) << 8
		| (self->buffer[self->pos++] & 0xFF));
}
