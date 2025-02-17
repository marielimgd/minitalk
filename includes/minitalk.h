/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:44:46 by mmariano          #+#    #+#             */
/*   Updated: 2025/02/17 16:38:15 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	send_signal(int pid, unsigned char c);
void	process_signal(int signal);
void	process_signal_back(int signal, siginfo_t *info, void *context);
void	confirm_bits(int signal);

#endif