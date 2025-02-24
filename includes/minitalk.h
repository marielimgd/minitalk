/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:44:46 by mmariano          #+#    #+#             */
/*   Updated: 2025/02/24 19:50:15 by mmariano         ###   ########.fr       */
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