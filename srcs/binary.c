/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:34:11 by awallet           #+#    #+#             */
/*   Updated: 2022/08/30 16:43:52 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <binary.h>

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

t_chaineoctet	*ft_instanciate(unsigned int bufsize)
{
	t_chaineoctet	*self;

	self = memg(MALLOC, sizeof(t_chaineoctet), NULL, BINARY);
	if (!self)
		return (perror("malloc"), NULL);
	self->buffer = memg(MALLOC, bufsize, NULL, BINARY);
	if (!self->buffer)
		return (perror("malloc"), NULL);
	self->bufsize = bufsize;
	self->len = 0;
	self->pos = 0;
	return (self);
}

void	ft_init(t_chaineoctet *bin, unsigned char *b, ...)
{
	va_list	args;

	va_start(args, b);
	bin->buffer = b;
	bin->len = va_arg(args, unsigned int);
	bin->bufsize = 0;
	bin->pos = 0;
	va_end(args);
}

unsigned int	ft_getpos(t_chaineoctet *this)
{
	return (this->pos);
}
