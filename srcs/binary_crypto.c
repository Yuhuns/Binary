/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_crypto.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 22:44:25 by awallet           #+#    #+#             */
/*   Updated: 2022/05/29 22:44:31 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary.h"

void	ft_encrypt(struct s_chaineoctet *self, unsigned int valeur)
{
	int	index;

	index = -1;
	while (++index < self->len)
		self->buffer[index] = (self->buffer[index]
				^ self->buffer[index - 1]) ^ (valeur & 255);
}

void	ft_decrypt(struct s_chaineoctet *self, unsigned int valeur)
{
	int	index;

	index = self->len;
	while (index--)
		self->buffer[index] = (self->buffer[index]
				^ self->buffer[index - 1]) ^ (valeur & 255);
}
