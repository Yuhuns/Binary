/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:45:25 by awallet           #+#    #+#             */
/*   Updated: 2022/05/29 19:56:14 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_bufferoverflow(void)
{
	ft_putstr_fd("Dépassement du tampon !", 2);
}

void	ft_hexdump(struct s_chaineoctet *buf)
{
	unsigned int	i;

	i = -1;
	printf("Binary result: \n");
	while (++i < buf->len)
		printf("\\x%02x", buf->buffer[i]);
	printf("\n");
	printf("-------\n");
}

void	ft_chardump(struct s_chaineoctet *buf)
{
	unsigned int	i;

	i = -1;
	while (++i < buf->len)
		printf("%c", buf->buffer[i]);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
