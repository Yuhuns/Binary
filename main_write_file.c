/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_write_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:06:02 by awallet           #+#    #+#             */
/*   Updated: 2022/05/29 21:55:15 by awallet          ###   ########.fr       */
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
        ft_wshort(buf, 8877633);
        ft_wchaine(buf, "KEY=ABCDEF");
        ft_wchaine(buf, "OUI");
        ft_wchaine(buf, "CECI EST UN TEST");
        ft_wbool(buf, TRUE);
        ft_wint(buf, 999999999);
        ft_wlong(buf, 9086675874576444);

        fwrite(buf->buffer, sizeof(t_chaineoctet), buf->len, fichier);
        fclose(fichier);	
}