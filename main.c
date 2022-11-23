/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:12:51 by awallet           #+#    #+#             */
/*   Updated: 2022/09/01 20:11:18 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/binary.h"

void	packet_code(int e1, int e2, t_chaineoctet *packet)
{
	ft_wshort(packet, (e1 << 8) | (e2 & 255));
}

void	packet_reader(t_chaineoctet *packet)
{
	int	code;
	int	e1;
	int	e2;
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
				printf("Oh there is some data: %d\n", ft_rint(packet));
		}
		else
			printf("Unknown packet (%d,%d)\n", e1, e2);
	}
}

t_chaineoctet	*packet_init(void)
{
	t_chaineoctet	*packet;
	
	packet = ft_instanciate(1024);
	if (!packet)
		return (perror("instanciate"), NULL);
	packet_code(26, 26, packet);
	ft_wbchaine(packet, "ABsJ3334AOOBSkkdbrooz::ajaja1188377==");
	return (packet);
}

t_chaineoctet	*packet_test(void)
{
	t_chaineoctet	*packet;
	
	packet = ft_instanciate(1024);
	if (!packet)
		return (perror("instanciate"), NULL);
	packet_code(26, 27, packet);
	ft_wschaine(packet, "This is a test for bool instruction...");
	ft_wbool(packet, TRUE);
	ft_wint(packet, 42);
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
	memg(PURGE, 0, NULL, 0);
}
