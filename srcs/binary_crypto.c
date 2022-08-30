/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_crypto.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 22:44:25 by awallet           #+#    #+#             */
/*   Updated: 2022/08/30 15:29:42 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary.h"

void	ft_encrypt(t_chaineoctet *self, unsigned int val)
{
	unsigned int	index;

	index = -1;
	while (++index < self->len)
		self->buffer[index] = (self->buffer[index]
				^ self->buffer[index - 1]) ^ (val & 255);
}

void	ft_decrypt(t_chaineoctet *self, unsigned int val)
{
	unsigned int	index;

	index = self->len;
	while (index--)
		self->buffer[index] = (self->buffer[index]
				^ self->buffer[index - 1]) ^ (val & 255);
}
