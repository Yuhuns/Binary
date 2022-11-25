/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:05:58 by awallet           #+#    #+#             */
/*   Updated: 2022/11/25 19:46:02 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <binary.h>

int	main(int ac, char **av)
{
	t_chaineoctet		*buf;
	FILE				*fichier;
	FILE				*test;
	int					i;
	char				buffer[2];
	int					rd;

	fichier = NULL;
	fichier = fopen(av[1], "wb");
	if (!fichier)
		return (perror("File"), 1);
	buf = ft_instanciate(1024);
	ft_wbchaine(buf, "YUHUNS");
	i = 1;
	while (++i < ac - 1)
	{
		test = fopen(av[i], "rb");
		rd = fread(buffer, 1, 1, test);
		while (rd)
			ft_wbyte(buf, buffer[0]);
	}
	printf("taille renvoye: %zu\n ", fwrite(buf->buffer,
			buf->len, buf->len, fichier));
	fclose(fichier);
}
