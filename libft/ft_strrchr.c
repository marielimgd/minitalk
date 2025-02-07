/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieli <marieli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:55:25 by marielidias       #+#    #+#             */
/*   Updated: 2025/02/03 17:55:46 by marieli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	index;

	index = ft_strlen(str);
	if ((char)c == '\0')
		return ((char *)&str[index]);
	while (index > 0)
	{
		if (str[index] == (char)c)
			return ((char *)&str[index]);
		index--;
	}
	if (str[index] == (char)c)
		return ((char *)&str[index]);
	return (NULL);
}
