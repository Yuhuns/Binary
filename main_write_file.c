/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_write_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:06:02 by awallet           #+#    #+#             */
/*   Updated: 2022/08/30 17:07:23 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/binary.h"

int     main(int ac, char **av)
{
        FILE *fichier = NULL;
        t_chaineoctet	*buf;
        t_chaineoctet	*packet;
        unsigned char           data;
        
 
        fichier = fopen(av[1], "wb");

        buf = ft_instanciate(1024);
        ft_wbrutechaine(buf, "42"); //magic header
        ft_wichaine(buf, "string");
        ft_wbchaine(buf, "42");
        ft_wichaine(buf, "42 file");

        fwrite(buf->buffer, sizeof(t_chaineoctet), 42, fichier);
        fclose(fichier);	
}