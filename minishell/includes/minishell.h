#ifndef     MINISHELL_H
# define    MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <termios.h>
# include <errno.h>
# include <signal.h>
# include <sys/wait.h>

struct termios	g_orig_termios;

typedef struct s_scanner
{
	char	**all_words;
	char	*command;
	int		tot_len;
	int		len_str;
	t_list	*lst;
	t_list	*lst2;
	t_list	*lst_tmp;
	t_list	*lst_tmp2;
	t_list	*lst_tmp3;
	char	**history;
	int		trigger;
	int		trigger2;
	char	*arg;
	char	**arg_exec;
	char	spl_str[1000];
	char	**all_words2;
	int		redirect;
	char	**file_re;
	char	**split_str;
	char	*path;
	char	**format_cmd;
	char	**env;
	int		global_exit;
	int		valid_arg;
	int		n_file;
	char	**all_words3;
	int		count_pipe;
	char	**piped;
	char	**piped2;
	char	**red_rev_all;
	char	**red_rev_split;
	char	*command_reverse;
	int		count_rev;
	int		fd;
	char	buf[100000];
	int		glob_len;
	int		glob_len2;
	int		glob_len3;
	int		trigger3;
	int		first;
	int		signal;
	int		att;
	char	c;
	int		up_attivo;
	int		down_attivo;
	int		replay;
	int		i;
	int		x;
	int		z;
	int		j;
	int		count;
	int		fd2[2];
	char	**exp;
	int		ret;
}				t_scanner;

typedef enum e_enu
{
	ERROR,
	SUCCESS,
	CD,
	ECHO1,
	caratterenullo,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	MALLOC_ERROR,
	QUOTES,
	REDIRECT_ERR,
	REDIRECT_1,
	REDIRECT_2,
	NOT_REDIRECT,
	EXIT,
	ARROW_LEFT,
	ARROW_RIGHT,
	ARROW_UP,
	ARROW_DOWN,
	INVALID_CMD = 127
}				t_enu;

void	print_prompt1(void);
void	init_scan(t_scanner *scan);
int		ft_strcmp(const char *s1, const char *s2);
void	exit_shell(char *cmd, t_scanner *scan, int err);
void	*my_realloc(void *ptr, size_t len);
void	enableRawMode(void);
void	rawmode(t_scanner *scan);
void	disableRawMode(void);
char	editorReadKey(void);
void	free_all(t_scanner *scan);
void	rawmode(t_scanner *scan);
void	if_no_print(t_scanner *scan);
void	if_ten(t_scanner *scan);
void	if_down2(t_scanner *scan, t_list *tmp, t_list *tmp2);
void	if_up(t_scanner *scan);
void	if_up2(t_scanner *scan);
int		if_up3(t_scanner *scan);
int		if_up4(int replay, t_scanner *scan);
void	if_down(t_scanner *scan);
t_list	*ft_lstlast_len(t_list *lst, int len);
char	editorReadKey(void);
void	enableRawMode(void);
void	disableRawMode(void);
void	die(const char *s);
void	split_string(t_scanner *scan);
int		split_string2(t_scanner *scan, int count);
void	split_string3(t_scanner *scan, int i, int j, int z);
void	free_scanner(t_scanner *scan);
void	free_scanner2(t_scanner *scan);
void	get_command(t_scanner *scan, char *cmd);
int		count_quotes_2(char *cmd);
int		count_quotes_1(char *cmd);
int		get_command2(t_scanner *scan, char *cmd, int z, int i);
void	get_command3(t_scanner *scan, int i, int j, char *cmd);
int		find_quot(t_scanner *scan, int z, int i, char *cmd);
void	if_wrong_quot(char *cmd, t_scanner *scan, int z);
void	all_words(t_scanner *scan, char *str);
void	allocate_word(t_scanner *scan, char *str);
void	get_words3(t_scanner *scan, char *str);
void	get_words2(t_scanner *scan, char *str);
void	get_words(t_scanner *scan, char *str);
void	malloc_str(t_scanner *scan);
void	set_words(t_scanner *scan);
void	analyze_quot(t_scanner *scan, char *str);
void	analyze_quot2(t_scanner *scan, char *str);
void	normal_count(t_scanner *scan, char *str);
void	conversion_command(t_scanner *scan, char *cmd);
void	get_arg(t_scanner *scan, char *str);
void	get_exec_arg(t_scanner *scan);
void	get_all_str2(t_scanner *scan, char *cmd);
void	get_all_str(t_scanner *scan, char *cmd);
void	check_redirect(t_scanner *scan);
void	free_format_cmd(t_scanner *scan);
int		cmp_command(t_scanner *scan);
void	parse_cmd(int res, t_scanner *scan, char *cmd);
int		check_execve(t_scanner *scan);
void	take_env(t_scanner *scan, char *envp[]);
void	reload_env(t_scanner *scan);
int		ft_echo(t_scanner *scan);
void	check_quotes(t_scanner *scan);
void	check_quotes2(t_scanner *scan, char *str, char tmp);
int		ft_pwd(t_scanner *scan);
int		ft_cd(t_scanner *scan);
int		ft_env(t_scanner *scan);
int		ft_export(t_scanner *scan);
int		ft_unset(t_scanner *scan);
void	ft_handler(int sig);
void	check_space(t_scanner *scan);
int		check_execve(t_scanner *scan);
void	ft_handler(int sig);
void	free_pipe(t_scanner *scan);
void	check_pipe(char *str, t_scanner *scan);
int		execve_pipe(t_scanner *scan, int i, int z, int status);
void	wait_pipe(t_scanner *scan, pid_t pid);
void	check_reverse_red(t_scanner *scan, char *str);
void	free_rev(t_scanner *scan);
void	exec_redrev(t_scanner *scan, char **str, int status, int z);
void	execution_redrev(t_scanner *scan, int z, int status, char **nstr);
char	**get_redrevstr(t_scanner *scan, int z, char **str);
void	welcome(void);

#endif
