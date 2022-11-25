/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:37:50 by awallet           #+#    #+#             */
/*   Updated: 2022/11/25 19:00:08 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_H
# define BINARY_H

# include <stdlib.h>
# define VERBOSE 0
# define FILE_HEADER "AWALLET42"
# define KEY "ABsJ3334AOOBSkkdbrooz::ajaja1188377=="
# define ENDFILE 26
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include "../libft/libft.h"
# include <math.h>

//# define malloc(...) 0;

typedef enum e_label
{
	BINARY,
	OTHER,
}	t_label;

typedef enum e_mem_t
{
	MALLOC,
	FREE,
	PURGE,
	LABEL
}	t_mem_t;

typedef struct s_garbage
{
	void				*address;
	t_label				label;
	struct s_garbage	*next;
}					t_garbage;

typedef struct s_chaineoctet
{
	unsigned char	*buffer;
	unsigned int	bufsize;
	unsigned int	len;
	unsigned int	pos;
}	t_chaineoctet;

typedef struct s_data
{
	t_garbage	*garbage;
}	t_data;

typedef enum e_bool
{
	false,
	true
}	t_bool;

t_chaineoctet				*ft_instanciate(unsigned int bufsize);
unsigned int				ft_rubyte(t_chaineoctet *self);
unsigned int				ft_rushort(t_chaineoctet *self);
unsigned int				ft_getpos(t_chaineoctet	*this);
int							ft_rbool(t_chaineoctet *self);
int							ft_rbyte(t_chaineoctet *self);
int							ft_rint(t_chaineoctet *self);
int							ft_lec(t_chaineoctet *self);
short						ft_rshort(t_chaineoctet *self);
char						*ft_rbchaine(t_chaineoctet *self);
char						*ft_rschaine(t_chaineoctet *self);
char						*ft_richaine(t_chaineoctet *self);
char						*ft_rbrutechaine(t_chaineoctet *self, int eof);
void						ft_ecr(t_chaineoctet *self, int entier);
void						ft_bufferoverflow(void);
void						ft_hexdump(t_chaineoctet *buf);
void						ft_wbchaine(t_chaineoctet *self, char *string);
void						ft_wschaine(t_chaineoctet *self, char *string);
void						ft_wichaine(t_chaineoctet *self, char *string);
void						ft_wbrutechaine(t_chaineoctet *self, char *string,
								int eof);
void						ft_chardump(t_chaineoctet *buf);
void						ft_encrypt(t_chaineoctet *self, unsigned int val);
void						ft_decrypt(t_chaineoctet *self, unsigned int val);
void						ft_wbool(t_chaineoctet *self, t_bool valeur);
void						ft_wbyte(t_chaineoctet *self, int entier);
void						ft_wshort(t_chaineoctet *self, int entier);
void						ft_wint(t_chaineoctet *self, int entier);
void						ft_init(t_chaineoctet *bin, unsigned char *b, ...);

void						init_data(t_data **data);
t_data						*get_data(void);

void						*memg(t_mem_t type, size_t size, void *adr,
								t_label label);
void						*free_label(t_garbage *garbage, t_label label);
void						*free_adr(t_garbage *garbage, void *adr);
void						*purge_garbage(t_garbage *garbage);
void						*add_garbage(t_data *data, size_t size, void *adr,
								t_label label);

#endif
