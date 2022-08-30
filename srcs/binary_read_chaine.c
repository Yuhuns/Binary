/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_read_chaine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:50:02 by awallet           #+#    #+#             */
/*   Updated: 2022/08/30 17:10:16 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary.h"

char	*ft_rbchaine(t_chaineoctet *self)
{
	unsigned int	length;
	char			*s;
	unsigned int	i;

	length = ft_rbyte(self);
	s = ft_calloc(1, sizeof(char *) * length);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < length)
		s[i] = self->buffer[self->pos++];
	return (s);
}

char	*ft_rbrutechaine(t_chaineoctet *self)
{
	char			*s;
	unsigned int	i;

	s = ft_calloc(1, sizeof(char *));
	if (!s)
		return (NULL);
	i = -1;
	while (self->buffer[self->pos] != ENDFILE)
		s[++i] = self->buffer[self->pos++];
	return (s);
}

char	*ft_rschaine(t_chaineoctet *self)
{
	unsigned int	length;
	char			*s;
	unsigned int	i;

	length = ft_rshort(self);
	s = ft_calloc(1, sizeof(char *) * length);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < length)
		s[i] = self->buffer[self->pos++];
	return (s);
}

char	*ft_richaine(t_chaineoctet *self)
{
	int		length;
	int		i;
	char	*s;

	length = ft_rint(self);
	s = ft_calloc(1, sizeof(char *) * length);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < length)
		s[i] = self->buffer[self->pos++];
	return (s);
}