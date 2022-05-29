/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_read_file.C                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:57:50 by awallet           #+#    #+#             */
/*   Updated: 2022/05/29 22:39:01 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/binary.h"

int     main(int ac, char **av)
{
        FILE *fichier = NULL;
        struct s_chaineoctet	*packet;
        unsigned char           data;
        
 
        fichier = fopen("./files/test.awallet", "rb");
        packet = ft_instanciate(1024);
        fread(packet->buffer, sizeof(packet), sizeof(packet), fichier);
        printf("%s\n", ft_rchaine(packet));
        printf("%i\n", ft_rint(packet));
        printf("%i\n", ft_rbool(packet));
        printf("%s\n", ft_rchaine(packet));
        fclose(fichier);	
}