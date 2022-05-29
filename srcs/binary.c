/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:34:11 by awallet           #+#    #+#             */
/*   Updated: 2022/05/29 17:24:42 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary.h"

struct s_chaineoctet	*ft_instanciate(unsigned int bufsize)
{
	struct s_chaineoctet	*this;

	this = malloc(sizeof(struct s_chaineoctet));
	this->buffer = malloc(bufsize);
	this->bufsize = bufsize;
	this->len = 0;
	this->pos = 0;
	return (this);
}

void	ft_initialize(struct s_chaineoctet *bin, unsigned char *buf, ...)
{
	va_list	args;

	va_start(args, buf);
	bin->buffer = buf;
	bin->len = va_arg(args, unsigned int);
	bin->bufsize = 0;
	bin->pos = 0;
	va_end(args);
}

unsigned int	ft_getpos(struct s_chaineoctet *this)
{
	return (this->pos);
}
