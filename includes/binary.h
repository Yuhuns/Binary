/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:37:50 by awallet           #+#    #+#             */
/*   Updated: 2022/05/30 20:14:19 by awallet          ###   ########.fr       */
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
typedef struct s_chaineoctet	t_chaineoctet;

void					ft_initialize(struct s_chaineoctet *bin, unsigned char *buf, ...);
struct s_chaineoctet	*ft_instanciate(unsigned int bufsize);
unsigned int	ft_getpos(struct s_chaineoctet	*this);
void					ft_wbool(struct s_chaineoctet *self, unsigned int valeur);
void					ft_wbyte(struct s_chaineoctet *self, int entier);
void					ft_wshort(struct s_chaineoctet *self, int entier);
void					ft_wint(struct s_chaineoctet *self, int entier);
unsigned int	ft_rbool(struct s_chaineoctet *self);
signed int	ft_rbyte(struct s_chaineoctet *self);
signed short	ft_rshort(struct s_chaineoctet *self);
signed int	ft_rint(struct s_chaineoctet *self);
void	ft_ecr(struct s_chaineoctet *self, int entier);
signed int     ft_lec(struct s_chaineoctet *self);
void	ft_putstr_fd(char *s, int fd);
void	ft_bufferoverflow(void);
void	ft_hexdump(struct s_chaineoctet *buf);
void	ft_wlong(struct s_chaineoctet *self, long entier);
signed long int	ft_rlong(struct s_chaineoctet *self);
unsigned int	ft_rubyte(struct s_chaineoctet *self);
unsigned int	ft_rushort(struct s_chaineoctet *self);
size_t	ft_strlen(const char *s);
void	ft_wbchaine(struct s_chaineoctet *self, char *string);
char	*ft_rbchaine(struct s_chaineoctet *self);
void	ft_wschaine(struct s_chaineoctet *self, char *string);
void	ft_wichaine(struct s_chaineoctet *self, char *string);
void	ft_wbrutechaine(struct s_chaineoctet *self, char *string);
char	*ft_rschaine(struct s_chaineoctet *self);
char	*ft_richaine(struct s_chaineoctet *self);
char	*ft_rbrutechaine(struct s_chaineoctet *self);
void	ft_chardump(struct s_chaineoctet *buf);
void	ft_putchar_fd(char c, int fd);
void	ft_encrypt(struct s_chaineoctet *self, unsigned int valeur);
void	ft_decrypt(struct s_chaineoctet *self, unsigned int valeur);

#endif
