/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/08/07 23:57:28 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *find_free_var(t_env *env, char *var)
{
	char *res;
	int i;

	i = 0;
	while(env->env[i])
	{
		if (str_n_cmp(env->env[i], var, str_len(var)) == 0 && env->env[i][str_len(var)] == '=')
		{
			res = env->env[i];
			while(res[0] != '=')
				res++;
			res++;
			return (res);
		}
		i++;
	}
	if (var[0] == '?')
		return(itoa(env->value + 1));
	free(var);
	return (0);
}


