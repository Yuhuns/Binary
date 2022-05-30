/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_read_file.C                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:57:50 by awallet           #+#    #+#             */
/*   Updated: 2022/05/30 12:42:17 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/binary.h"

int     main(int ac, char **av)
{
        FILE *fichier = NULL;
        struct s_chaineoctet	*packet;
        unsigned char           data;
        const char              *header;
        unsigned int            boolean;
        
 
        fichier = fopen(av[1], "rb");
        packet = ft_instanciate(512);
        fread(packet->buffer, sizeof(packet), sizeof(packet), fichier);
        header = ft_rchaine(packet);
        boolean = ft_rbool(packet);
        if (header == (char *)"AWALLET42")
                printf("Oui c'est bon");
        else
                printf("probleme boolean=%s", header);
        fclose(fichier);	
}