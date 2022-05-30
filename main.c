/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:12:51 by awallet           #+#    #+#             */
/*   Updated: 2022/05/30 20:59:27 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/binary.h"

int	main(void)
{
	struct s_chaineoctet	*buf;
	struct s_chaineoctet	*packet;

	buf = ft_instanciate(1024);
	ft_ecr(buf, -8000000);
	ft_ecr(buf, 2147897);
	ft_hexdump(buf);
	packet = buf;
	ft_initialize(packet, buf->buffer, buf->len);
	ft_hexdump(packet);
	printf("%i\n", ft_lec(packet));
	printf("%i\n", ft_lec(packet));
}
