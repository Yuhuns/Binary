/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:45:25 by awallet           #+#    #+#             */
/*   Updated: 2022/08/30 15:24:04 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <binary.h>

void	ft_bufferoverflow(void)
{
	if (VERBOSE)
		ft_putstr_fd("ERREUR:\n Dépassement du tampon !", 2);
}

void	ft_hexdump(t_chaineoctet *buf)
{
	unsigned int	i;

	i = -1;
	printf("Binary result: \n");
	while (++i < buf->len)
		printf("\\x%02x", buf->buffer[i]);
	printf("\n");
	printf("-------\n");
}
