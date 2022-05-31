/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_read_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:57:50 by awallet           #+#    #+#             */
/*   Updated: 2022/05/30 16:02:17 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/binary.h"

int     main(int ac, char **av)
{
        FILE *fichier = NULL;
        struct s_chaineoctet	*packet;
        unsigned char           data;
        char              *magic_header;
        unsigned int            boolean;
        
        fichier = fopen(av[1], "rb");
        packet = ft_instanciate(512);
        fread(packet->buffer, sizeof(packet), sizeof(packet), fichier);
        magic_header = ft_rbrutechaine(packet);
        boolean = ft_rbool(packet);
        if (strcmp(magic_header, FILE_HEADER) == 0)
        {
                printf("MAGIC HEADER : OK\n");
                printf("bool: %u \n", ft_rbool(packet));
                printf("phrase: %s \n", ft_rbchaine(packet));
        }
        else if (strcmp(magic_header, "NES") == 0)
        {
                printf("prg rom: %u \n", ft_rubyte(packet));
                printf("chr rom: %u \n", ft_rubyte(packet));
                printf("flags_6: %u \n", ft_rubyte(packet));
                printf("flags_7: %u \n", ft_rubyte(packet));
                printf("prg_ram: %u \n", ft_rubyte(packet));
                printf("flags_9: %u \n", ft_rubyte(packet));
        }
        else
                printf("BAD HEADER EXPECTED %s RESULT -> %s", FILE_HEADER, magic_header);
        fclose(fichier);
}