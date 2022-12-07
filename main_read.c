/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:05:58 by awallet           #+#    #+#             */
/*   Updated: 2022/12/07 18:03:40 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <binary.h>

int	main(int ac __attribute__((unused)), char **av)
{
	t_chaineoctet		*b;
	FILE				*fichier;

	fichier = NULL;
	fichier = fopen(av[1], "rb");
	if (!fichier)
		return (perror("File"), 1);
	b = ft_instanciate(1024);
	fread(b->buffer, sizeof(b), sizeof(b), fichier);
	printf("-> HEADER %s\n", ft_rlenbrutechaine(b, 4));
	printf("-> VERSION MAJOR %u MINOR %u\n", ft_rushort(b), ft_rushort(b));
	printf("-> UNUSED1 %u CREATION_DATE %lu UPDATE DATE %lu\n", ft_rshort(b), ft_rlong(b), ft_rlong(b));
	printf("-> INDEX_ENTRY_C %u INDEX_POS_LOW %u INDEX_SIZE %u\n", ft_rushort(b), ft_rushort(b), ft_rushort(b));
	printf("-> UNUSED3 %u UNUSED4 %u\n", ft_rushort(b), ft_rushort(b));
	fclose(fichier);
	memg(PURGE, 0, NULL, 0);
}
