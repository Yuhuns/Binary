/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_write_chaine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:17:17 by awallet           #+#    #+#             */
/*   Updated: 2022/12/07 17:10:27 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <binary.h>

void	ft_wbrutechaine(t_chaineoctet *self, char *string, int eof)
{
	size_t	length;

	length = 0;
	if (*string)
	{
		length = ft_strlen(string) + 1;
		self->len += length;
		while (*string)
			self->buffer[self->pos++] = *string++;
		self->buffer[self->pos++] = eof;
	}
}

void	ft_wlenbrutechaine(t_chaineoctet *self, char *string)
{
	if (*string)
	{
		self->len += ft_strlen(string);
		while (*string)
			self->buffer[self->pos++] = *string++;
	}
}

void	ft_wbchaine(t_chaineoctet *self, char *string)
{
	size_t	length;
	int		i;

	length = 0;
	i = -1;
	if (string)
	{
		length = ft_strlen(string);
		ft_wbyte(self, length);
		self->len += length;
		while (*(string + ++i))
			self->buffer[self->pos++] = *(string + i);
	}
}

void	ft_wschaine(t_chaineoctet *self, char *string)
{
	size_t	length;
	int		i;

	length = 0;
	i = -1;
	if (string)
	{
		length = ft_strlen(string);
		ft_wshort(self, length);
		self->len += length;
		while (*(string + ++i))
			self->buffer[self->pos++] = *(string + i);
	}
}

void	ft_wichaine(t_chaineoctet *self, char *string)
{
	size_t	length;

	length = 0;
	if (*string)
	{
		length = ft_strlen(string);
		ft_wint(self, length);
		self->len += length;
		while (*string)
			self->buffer[self->pos++] = *string++;
	}
}
