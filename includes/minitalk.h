/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieli <marieli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:44:46 by mmariano          #+#    #+#             */
/*   Updated: 2025/02/25 12:29:38 by marieli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void	process_signal(int signal, siginfo_t *info, void *context);
void	confirm_bits(int signal);
void	send_signal(int pid, unsigned char c);

#endif