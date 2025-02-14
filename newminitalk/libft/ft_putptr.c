/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieli <marieli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:33:11 by marieli           #+#    #+#             */
/*   Updated: 2025/02/03 17:54:18 by marieli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_putnbr_hex(ptr, 0);
	}
	return (count);
}
