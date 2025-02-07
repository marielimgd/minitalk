/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieli <marieli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:02:47 by marielidias       #+#    #+#             */
/*   Updated: 2025/02/03 17:55:37 by marieli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return (0);
	while ((index < n) && (str1[index] || str2[index]))
	{
		if ((unsigned char)str1[index] != (unsigned char)str2[index])
			return ((unsigned char)str1[index] - (unsigned char)str2[index]);
		index++;
	}
	return (0);
}
