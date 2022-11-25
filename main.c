/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:12:51 by awallet           #+#    #+#             */
/*   Updated: 2022/11/25 19:02:48 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/binary.h"

void	packet_code(int e1, int e2, t_chaineoctet *packet)
{
	ft_wshort(packet, (e1 << 8) | (e2 & 255));
}

void	packet_reader(t_chaineoctet *packet)
{
	int		code;
	int		e1;
	int		e2;
	char	*key;

	key = NULL;
	ft_init(packet, packet->buffer, packet->len);
	code = ft_rshort(packet);
	e1 = code >> 8;
	e2 = code & 255;
	printf("PACKET [%d,%d]:\n", e1, e2);
	if (e1 == 26)
	{
		if (e2 == 26)
		{
			key = ft_rbchaine(packet);
			if (ft_strcmp(KEY, key) == 0)
				printf("KEY: CORRECT !\n");
			else
				printf("KEY: BAD (%s) !\n", key);
		}
		else if (e2 == 27)
		{
			printf("%s\n", ft_rschaine(packet));
			if (ft_rbool(packet))
				printf("There is some data : %i\n", ft_rint(packet));
			if (ft_rbool(packet))
				printf("Data in block : %s\n", ft_rbrutechaine(packet, 26));
		}
		else if (e2 == 28)
			printf("chiffre : %i\n", ft_lec(packet));
		else
			printf("Unknown packet (%d,%d)\n", e1, e2);
	}
}

t_chaineoctet	*packet_init(void)
{
	t_chaineoctet	*packet;

	packet = ft_instanciate(512);
	if (!packet)
		return (perror("instanciate"), NULL);
	packet_code(26, 26, packet);
	ft_wbchaine(packet, "ABsJ3334AOOBSkkdbrooz::ajaja1188377==");
	return (packet);
}

t_chaineoctet	*packet_ecriture(void)
{
	t_chaineoctet	*packet;

	packet = ft_instanciate(512);
	if (!packet)
		return (perror("instanciate"), NULL);
	packet_code(26, 28, packet);
	ft_ecr(packet, -80000000);
	return (packet);
}

t_chaineoctet	*packet_test(void)
{
	t_chaineoctet	*packet;

	packet = ft_instanciate(512);
	if (!packet)
		return (perror("instanciate"), NULL);
	packet_code(26, 27, packet);
	ft_wschaine(packet, "I'm a packet a struct of binary with a lots a bytes.");
	ft_wbool(packet, true);
	ft_wint(packet, 42);
	ft_wbool(packet, true);
	ft_wbrutechaine(packet, "BRUTAL", 26);
	return (packet);
}

int	main(void)
{
	t_chaineoctet	*packet;
	t_data			*data;

	init_data(&data);
	packet = packet_init();
	if (!packet)
		return (exit(1), 1);
	packet_reader(packet);
	packet = packet_test();
	packet_reader(packet);
	packet = packet_ecriture();
	packet_reader(packet);
	memg(PURGE, 0, NULL, 0);
}
