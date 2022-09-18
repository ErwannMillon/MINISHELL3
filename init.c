/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/08/07 23:57:28 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int init(t_command *command)
{
	command->options = 0;
	command->fd_file_in = 0;
	command->file_in = 0;
	command->fd_file_out = 0;
	command->file_out = 0;
	command->pipe_flag_in = 0;
	command->pipe_flag_out = 0;
	command->fd_pipe_in = 0;
	command->fd_pipe_in_next = 0;
	command->fd_pipe_out = 0;
	command->fd_in = 1;
	command->fd_out = 0;
	return 0;
}

int init_cmd(t_command *command)
{
	command->options = 0;
	command->fd_file_in = 0;
	command->file_in = 0;
	command->fd_file_out = 0;
	command->file_out = 0;
	return 0;
}
