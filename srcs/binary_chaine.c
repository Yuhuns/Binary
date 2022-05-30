/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_chaine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:17:17 by awallet           #+#    #+#             */
/*   Updated: 2022/05/30 12:41:37 by awallet          ###   ########.fr       */
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

const char	*ft_rchaine(struct s_chaineoctet *self)
{
	unsigned int	length;
	unsigned char	*s;
	unsigned int	i;

	length = ft_rshort(self);
	s = malloc(sizeof(unsigned char) * length + 1);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < length)
		s[i] = self->buffer[self->pos++];
	return (s);
}
