/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieli <marieli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:15:39 by marieli           #+#    #+#             */
/*   Updated: 2025/02/03 17:51:37 by marieli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return (0);
	del(lst->data);
	free(lst);
	return (1);
}
