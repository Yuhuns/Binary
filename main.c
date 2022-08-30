/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:12:51 by awallet           #+#    #+#             */
/*   Updated: 2022/08/30 17:09:51 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/binary.h"

int	main(void)
{
	t_chaineoctet	*buf;
	t_chaineoctet	*packet;

	buf = ft_instanciate(1024);
	ft_ecr(buf, -800000);
	ft_wbchaine(buf, "test");
	ft_wichaine(buf, "test int char");
	ft_ecr(buf, 0x80000000UL);
	ft_wbrutechaine(buf, "BRUTAL");
	packet = buf;
	ft_init(packet, buf->buffer, buf->len);
	ft_hexdump(packet);
	printf("%i\n", ft_lec(packet));
	printf("%s\n", ft_rbchaine(packet));
	printf("%s\n", ft_richaine(packet));
	printf("%i\n", ft_lec(packet));
	printf("%s\n", ft_rbrutechaine(packet));
	free(buf->buffer);
	free(packet);
}
