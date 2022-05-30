/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_read_chaine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:50:02 by awallet           #+#    #+#             */
/*   Updated: 2022/05/30 15:30:25 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary.h"

char	*ft_rbchaine(struct s_chaineoctet *self)
{
	unsigned int	length;
	char			*s;
	unsigned int	i;

	length = ft_rbyte(self);
	s = malloc(sizeof(char) * length);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < length)
		s[i] = self->buffer[self->pos++];
	return (s);
}

char	*ft_rbrutechaine(struct s_chaineoctet *self)
{
	char			*s;
	unsigned int	i;

	s = malloc(sizeof(char *));
	if (!s)
		return (NULL);
	i = -1;
	while (self->buffer[self->pos] != ENDFILE)
		s[++i] = self->buffer[self->pos++];
	return (s);
}

char	*ft_rschaine(struct s_chaineoctet *self)
{
	unsigned int	length;
	char			*s;
	unsigned int	i;

	length = ft_rshort(self);
	s = malloc(sizeof(char) * length);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < length)
		s[i] = self->buffer[self->pos++];
	return (s);
}

char	*ft_richaine(struct s_chaineoctet *self)
{
	unsigned int	length;
	char			*s;
	unsigned int	i;

	length = ft_rint(self);
	s = malloc(sizeof(char) * length);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < length)
		s[i] = self->buffer[self->pos++];
	return (s);
}