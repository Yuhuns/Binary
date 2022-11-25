/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_read_chaine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:50:02 by awallet           #+#    #+#             */
/*   Updated: 2022/11/25 18:57:00 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <binary.h>

char	*ft_rbchaine(t_chaineoctet *self)
{
	unsigned int	length;
	char			*s;
	unsigned int	i;

	length = ft_rbyte(self);
	s = memg(MALLOC, sizeof(char) * length + 1, NULL, BINARY);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < length)
		s[i] = self->buffer[self->pos++];
	s[i++] = '\0';
	return (s);
}

char	*ft_rbrutechaine(t_chaineoctet *self, int eof)
{
	char			*s;
	unsigned int	i;

	i = 0;
	while (self->buffer[self->pos] != eof)
	{
		self->pos++;
		i++;
	}
	s = memg(MALLOC, sizeof(char) * (i + 1), NULL, BINARY);
	printf("length: %i\n", i);
	self->pos -= i;
	if (!s)
		return (NULL);
	i = -1;
	while (self->buffer[self->pos] != eof)
		s[++i] = self->buffer[self->pos++];
	s[++i] = '\0';
	return (s);
}

char	*ft_rschaine(t_chaineoctet *self)
{
	unsigned int	length;
	char			*s;
	unsigned int	i;

	length = ft_rshort(self);
	s = memg(MALLOC, sizeof(char) * length + 1, NULL, BINARY);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < length && self->buffer[self->pos])
		s[i] = self->buffer[self->pos++];
	s[i++] = '\0';
	return (s);
}

char	*ft_richaine(t_chaineoctet *self)
{
	int		length;
	int		i;
	char	*s;

	length = ft_rint(self);
	s = memg(MALLOC, sizeof(char) * length + 1, NULL, BINARY);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < length)
		s[i] = self->buffer[self->pos++];
	s[i++] = '\0';
	return (s);
}
