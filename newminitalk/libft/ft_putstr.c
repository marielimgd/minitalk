/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieli <marieli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:54:40 by marieli           #+#    #+#             */
/*   Updated: 2025/02/03 17:54:32 by marieli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putstr(char *str)
{
	int index;

	if (!str)
		return (ft_putstr("(null)"));
	index = 0;
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
	}
	return (index);
}