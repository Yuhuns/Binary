/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_write_chaine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:17:17 by awallet           #+#    #+#             */
/*   Updated: 2022/05/30 15:47:08 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary.h"

void	ft_wbrutechaine(struct s_chaineoctet *self, char *string)
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

void	ft_wbchaine(struct s_chaineoctet *self, char *string)
{
	size_t	length;

	length = 0;
	if (*string)
	{
		length = ft_strlen(string);
		ft_wbyte(self, length);
		self->len += length;
		while (*string)
			self->buffer[self->pos++] = *string++;
	}
}

void	ft_wschaine(struct s_chaineoctet *self, char *string)
{
	size_t	length;

	length = 0;
	if (*string)
	{
		length = ft_strlen(string);
		ft_wshort(self, length);
		self->len += length;
		while (*string)
			self->buffer[self->pos++] = *string++;
	}
}

void	ft_wichaine(struct s_chaineoctet *self, char *string)
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
