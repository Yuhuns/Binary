/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_write_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:06:02 by awallet           #+#    #+#             */
/*   Updated: 2022/05/30 12:30:19 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/binary.h"

int     main(int ac, char **av)
{
        FILE *fichier = NULL;
        struct s_chaineoctet	*buf;
        struct s_chaineoctet	*packet;
        unsigned char           data;
        
 
        fichier = fopen(av[1], "wb");

        buf = ft_instanciate(512);
        ft_wchaine(buf, "AWALLET42"); //header
        ft_wbool(buf, TRUE);
        ft_wchaine(buf, "Melodie aime les billy");
        ft_wint(buf, buf->len);

        fwrite(buf->buffer, sizeof(t_chaineoctet), buf->len, fichier);
        fclose(fichier);	
}