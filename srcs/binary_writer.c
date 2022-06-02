/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_writer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:05:30 by awallet           #+#    #+#             */
/*   Updated: 2022/06/02 19:28:53 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary.h"

void	ft_wbool(t_chaineoctet *self, unsigned int valeur)
{
	self->len += 1;
	self->buffer[self->pos++] = valeur;
}

void	ft_wbyte(t_chaineoctet *self, int entier)
{
	self->len += 1;
	self->buffer[self->pos++] = entier & 0xFF;
}

void	ft_wshort(t_chaineoctet *self, int entier)
{
	self->len += 2;
	self->buffer[self->pos++] = (entier >> 8) & 0xFF;
	self->buffer[self->pos++] = entier & 0xFF;
}

void	ft_wint(t_chaineoctet *self, int entier)
{
	self->len += 4;
	self->buffer[self->pos++] = (entier >> 24) & 0xFF;
	self->buffer[self->pos++] = (entier >> 16) & 0xFF;
	self->buffer[self->pos++] = (entier >> 8) & 0xFF;
	self->buffer[self->pos++] = entier & 0xFF;
}

void	ft_wlong(t_chaineoctet *self, long entier)
{
	self->len += 8;
	self->buffer[self->pos++] = (entier >> 56) & 0xFF;
	self->buffer[self->pos++] = (entier >> 48) & 0xFF;
	self->buffer[self->pos++] = (entier >> 40) & 0xFF;
	self->buffer[self->pos++] = (entier >> 32) & 0xFF;
	self->buffer[self->pos++] = (entier >> 24) & 0xFF;
	self->buffer[self->pos++] = (entier >> 16) & 0xFF;
	self->buffer[self->pos++] = (entier >> 8) & 0xFF;
	self->buffer[self->pos++] = entier & 0xFF;
}
