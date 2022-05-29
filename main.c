/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:12:51 by awallet           #+#    #+#             */
/*   Updated: 2022/05/29 20:26:36 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/binary.h"

int	main(void)
{
	struct s_chaineoctet	*buf;
	struct s_chaineoctet	*packet;

	buf = ft_instanciate(1024);
	ft_wbyte(buf, 12);
	ft_wshort(buf, 800);
	ft_wlong(buf, 1234556);
	ft_wchaine(buf, "abcdef");
	ft_encrypt(buf, 10L); //effectue un opération pour brouiller les data
	ft_hexdump(buf);
	packet = buf;
	ft_initialize(packet, buf->buffer, buf->len);
	ft_decrypt(packet, 10L); //permet d'enlever l'encryption du packet
	ft_hexdump(packet);
	printf("%i\n", ft_rbyte(packet));
	printf("%i\n", ft_rshort(packet));
	printf("%i\n", ft_rlong(packet));
}
