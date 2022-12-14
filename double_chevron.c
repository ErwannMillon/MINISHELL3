#include "./libftextended/headers/libft.h"
#include "minishell.h"
#include <fcntl.h>
char	*cas_heredoc(char *input, t_command *command, t_env *env)
{
	const int	heredoc = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0640);
	char		*heredoc_input;
	int			i;
	char		*terminator;	

	i = 0;
	input += 2;
	input = forward_space(input);
	command->file_in = ".heredoc";
	if (command->fd_file_in) 
		close(command->fd_file_in);
	while (input[i] && maybe_char(input[i]))
		i++;
	printf("input_.beginning: %s\n", input);
	terminator = str_n_dup(input, i);
	// printf("terminator:_%s_\n", terminator);
	// printf("terminator:_%d_\n", str_len(terminator));
	
	heredoc_input = readline("heredoc> ");
	while (str_n_cmp(heredoc_input, terminator, str_len(terminator)))
	{
		write(heredoc, heredoc_input, str_len(heredoc_input));
		write(heredoc, "n", 1);
		heredoc_input = readline("heredoc> ");
	}
	close(heredoc);
	command->fd_file_in = open(".heredoc", O_RDONLY);
	command->fd_in = command->fd_file_in;
	input = input + i;
	printf("ass%d\n", i);
	if (str_len(input) == 0)
		return (0);
	// exit(0);
	printf("inputLreturned:_%s_%d\n", input, str_len(input));
	return (input);

}

// int main(void)
// {
// 	double_chevrons("x");
// 	return(0);
// }