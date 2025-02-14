/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieli <marieli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:02:40 by marielidias       #+#    #+#             */
/*   Updated: 2025/02/03 17:49:07 by marieli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_bzero(void *str, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)str;
	while (len > 0)
	{
		*tmp = 0;
		tmp++;
		len--;
	}
	return (str);
}
