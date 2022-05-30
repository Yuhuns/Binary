/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:37:50 by awallet           #+#    #+#             */
/*   Updated: 2022/05/30 12:40:32 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_H
# define BINARY_H

# include <stdlib.h>
# define TRUE 1
# define FALSE 0
# define VERBOSE 0
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

struct	s_chaineoctet
{
	unsigned char	*buffer;
	unsigned int	bufsize;
	unsigned int	len;
	unsigned int	pos;
}	t_chaineoctet;

void					ft_initialize(struct s_chaineoctet *bin, unsigned char *buf, ...);
struct s_chaineoctet	*ft_instanciate(unsigned int bufsize);
unsigned int	ft_getpos(struct s_chaineoctet	*this);
void					ft_wbool(struct s_chaineoctet *self, unsigned int valeur);
void					ft_wbyte(struct s_chaineoctet *self, int entier);
void					ft_wshort(struct s_chaineoctet *self, int entier);
void					ft_wint(struct s_chaineoctet *self, int entier);
unsigned int	ft_rbool(struct s_chaineoctet *self);
int	ft_rbyte(struct s_chaineoctet *self);
int	ft_rshort(struct s_chaineoctet *self);
int	ft_rint(struct s_chaineoctet *self);
void	ft_putstr_fd(char *s, int fd);
void	ft_bufferoverflow(void);
void	ft_hexdump(struct s_chaineoctet *buf);
void	ft_wlong(struct s_chaineoctet *self, long entier);
int	ft_rlong(struct s_chaineoctet *self);
unsigned int	ft_rubyte(struct s_chaineoctet *self);
unsigned int	ft_rushort(struct s_chaineoctet *self);
size_t	ft_strlen(const char *s);
void	ft_wchaine(struct s_chaineoctet *self, char *string);
const char	*ft_rchaine(struct s_chaineoctet *self);
void	ft_chardump(struct s_chaineoctet *buf);
void	ft_putchar_fd(char c, int fd);
void	ft_encrypt(struct s_chaineoctet *self, unsigned int valeur);
void	ft_decrypt(struct s_chaineoctet *self, unsigned int valeur);

#endif
