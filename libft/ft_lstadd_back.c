/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieli <marieli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:15:23 by marieli           #+#    #+#             */
/*   Updated: 2025/02/03 17:51:03 by marieli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last_node;

    if (*lst == NULL)
        *lst = new;
    else
    {
        last_node = ft_lstlast(*lst);
        last_node->next = new;
    }
}
