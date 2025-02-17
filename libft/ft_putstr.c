/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:54:40 by marieli           #+#    #+#             */
/*   Updated: 2025/02/17 14:09:33 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putstr(char *str)
{
	int	index;

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
