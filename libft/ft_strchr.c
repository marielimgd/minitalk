/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieli <marieli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:59:52 by marielidias       #+#    #+#             */
/*   Updated: 2025/02/03 17:54:45 by marieli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == (char)c)
			return ((char *)&str[index]);
		index++;
	}
	if (str[index] == (char)c)
		return ((char *)&str[index]);
	return (NULL);
}
