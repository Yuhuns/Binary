/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_write_chaine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:17:17 by awallet           #+#    #+#             */
/*   Updated: 2022/06/02 19:28:53 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <binary.h>

void	ft_wbrutechaine(t_chaineoctet *self, char *string)
{
	size_t	length;

	length = 0;
	if (*string)
	{
		length = ft_strlen(string) + 1;
		self->len += length;
		while (*string)
			self->buffer[self->pos++] = *string++;
		self->buffer[self->pos++] = ENDFILE;
	}
}

void	ft_wbchaine(t_chaineoctet *self, char *string)
{
	size_t	length;

	length = 0;
	if (*string)
	{
		length = ft_strlen(string) + 1;
		printf("wrt length = %li\n", length);
		ft_wbyte(self, length);
		self->len += length;
		while (*string)
			self->buffer[self->pos++] = *string++;
	}
}

void	ft_wschaine(t_chaineoctet *self, char *string)
{
	size_t	length;

	length = 0;
	if (*string)
	{
		length = ft_strlen(string) + 1;
		printf("wrt (short) length = %li\n", length);
		ft_wshort(self, length);
		self->len += length;
		while (*string)
			self->buffer[self->pos++] = *string++;
	}
}

void	ft_wichaine(t_chaineoctet *self, char *string)
{
	size_t	length;

	length = 0;
	if (*string)
	{
		length = ft_strlen(string) + 1;
		ft_wint(self, length);
		self->len += length;
		while (*string)
			self->buffer[self->pos++] = *string++;
	}
}
