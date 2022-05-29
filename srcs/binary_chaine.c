/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_chaine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:17:17 by awallet           #+#    #+#             */
/*   Updated: 2022/05/29 20:48:14 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary.h"

void	ft_wchaine(struct s_chaineoctet *self, char *string)
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
//! Amélioration nécessaire :)

unsigned char	*ft_rchaine(struct s_chaineoctet *self)
{
	unsigned int	length;
	unsigned int	i;

	length = ft_rshort(self);
	while (length--)
		ft_putchar_fd(self->buffer[self->pos++], 1);
	return ("");
}
