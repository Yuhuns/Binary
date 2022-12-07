/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:05:58 by awallet           #+#    #+#             */
/*   Updated: 2022/12/07 17:26:41 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <binary.h>

int	main(int ac __attribute__((unused)), char **av)
{
	t_chaineoctet		*buf;
	t_chaineoctet		*b;
	FILE				*fichier;

	fichier = NULL;
	fichier = fopen(av[1], "wb");
	if (!fichier)
		return (perror("File"), 1);
	buf = ft_instanciate(1024);
	ft_wlenbrutechaine(buf, "YUHUNS");
	printf("taille renvoye: %zu\n", fwrite(buf->buffer,
			1, buf->len, fichier));
	fclose(fichier);
	fichier = fopen(av[1], "rb");
	b = ft_instanciate(512);
	fread(b->buffer, buf->len, buf->len, fichier);
	printf("-> HEADER %s\n", ft_rlenbrutechaine(b, 6));
	fclose(fichier);
	memg(PURGE, 0, NULL, 0);
}
