/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:37:50 by awallet           #+#    #+#             */
/*   Updated: 2022/06/02 19:28:53 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_H
# define BINARY_H

# include <stdlib.h>
# define TRUE 1
# define FALSE 0
# define VERBOSE 0
# define FILE_HEADER "AWALLET42"
# define ENDFILE 26
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <math.h>

struct	s_chaineoctet
{
	unsigned char	*buffer;
	unsigned int	bufsize;
	unsigned int	len;
	unsigned int	pos;
};	
typedef t_chaineoctet	t_chaineoctet;

void					ft_initialize(t_chaineoctet *bin, unsigned char *buf, ...);
t_chaineoctet	*ft_instanciate(unsigned int bufsize);
unsigned int	ft_getpos(t_chaineoctet	*this);
void					ft_wbool(t_chaineoctet *self, unsigned int valeur);
void					ft_wbyte(t_chaineoctet *self, int entier);
void					ft_wshort(t_chaineoctet *self, int entier);
void					ft_wint(t_chaineoctet *self, int entier);
unsigned int	ft_rbool(t_chaineoctet *self);
signed int	ft_rbyte(t_chaineoctet *self);
signed short	ft_rshort(t_chaineoctet *self);
signed int	ft_rint(t_chaineoctet *self);
void	ft_ecr(t_chaineoctet *self, int entier);
signed int     ft_lec(t_chaineoctet *self);
void	ft_putstr_fd(char *s, int fd);
void	ft_bufferoverflow(void);
void	ft_hexdump(t_chaineoctet *buf);
void	ft_wlong(t_chaineoctet *self, long entier);
signed long int	ft_rlong(t_chaineoctet *self);
unsigned int	ft_rubyte(t_chaineoctet *self);
unsigned int	ft_rushort(t_chaineoctet *self);
size_t	ft_strlen(const char *s);
void	ft_wbchaine(t_chaineoctet *self, char *string);
char	*ft_rbchaine(t_chaineoctet *self);
void	ft_wschaine(t_chaineoctet *self, char *string);
void	ft_wichaine(t_chaineoctet *self, char *string);
void	ft_wbrutechaine(t_chaineoctet *self, char *string);
char	*ft_rschaine(t_chaineoctet *self);
char	*ft_richaine(t_chaineoctet *self);
char	*ft_rbrutechaine(t_chaineoctet *self);
void	ft_chardump(t_chaineoctet *buf);
void	ft_putchar_fd(char c, int fd);
void	ft_encrypt(t_chaineoctet *self, unsigned int valeur);
void	ft_decrypt(t_chaineoctet *self, unsigned int valeur);

#endif
