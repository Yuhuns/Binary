/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:34:11 by awallet           #+#    #+#             */
/*   Updated: 2022/06/02 19:28:53 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary.h"

t_chaineoctet	*ft_instanciate(unsigned int bufsize)
{
	t_chaineoctet	*this;

	this = malloc(sizeof(t_chaineoctet));
	if (!this)
		return (NULL);
	this->buffer = malloc(bufsize);
	this->bufsize = bufsize;
	this->len = 0;
	this->pos = 0;
	return (this);
}

void	ft_initialize(t_chaineoctet *bin, unsigned char *buf, ...)
{
	va_list	args;

	va_start(args, buf);
	bin->buffer = buf;
	bin->len = va_arg(args, unsigned int);
	bin->bufsize = 0;
	bin->pos = 0;
	va_end(args);
}

unsigned int	ft_getpos(t_chaineoctet *this)
{
	return (this->pos);
}
