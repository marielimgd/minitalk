/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieli <marieli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:14:43 by marieli           #+#    #+#             */
/*   Updated: 2025/02/03 20:26:15 by marieli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int ft_atoi(const char *str)
{
    long num;
    int sign;

    sign = 1;
    num = 0;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    if (!*str)
    {
        ft_putendl_fd("Error\n", STDERR_FILENO);
        exit(1);
    }
    while (*str)
    {
        if (*str < '0' || *str > '9')
        {
            ft_putendl_fd("Error\n", STDERR_FILENO);
            exit(1);
        }
        num = num * 10 + (*str - '0');
        if (num * sign > INT_MAX || num * sign < INT_MIN) 
        {
            ft_putendl_fd("Error\n", STDERR_FILENO);
            exit(1);
        }
        str++;
    }
    return ((int)(num * sign));
}
