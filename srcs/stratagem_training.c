/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stratagem_training.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:47:52 by lpetit            #+#    #+#             */
/*   Updated: 2024/02/25 16:45:53 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helldivers.h"

void set_raw_mode() 
{
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void	on_key_pressed(int c, char **strat_list)
{
	int	n;
	int	i;

	i = 0;
	if (c == 'w' || c == 'a' || c == 's' || c == 'd' || c == 'h')
	{
		if (c != 'h')
		{
			n = check_entry(c, strat_list);
			if (n == 1)
				key_parsing(c);
			else if (n == 0)
				printf(" Wrong entry\n\n");
		}
		else if (c == 'h')
		{
			while (strat_list[i])
			{
				printf("%s\n", strat_list[i]);
				i++;
			}
		}
        	fflush(stdout);
	}
}

int main(void)
{
	set_raw_mode();

	fd_set readfds;
	struct timeval timeout;
	char	**strat_list;
	char	buffer[1000000 + 1];
	char	c;
	int	n;
	int	fd;
	int	ret;

	fd = open("stratagem.txt", O_RDONLY);
	n = read(fd, buffer, 1000000);
	if (n < 0)
		return (0);
	strat_list = ft_split(buffer, '\n');
	while (1)
	{
		FD_ZERO(&readfds);
		FD_SET(STDIN_FILENO, &readfds);
		timeout.tv_sec = 0;
		timeout.tv_usec = 10000;
		ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);
		if (ret == -1)
		{
		perror("select");
		break;
		}
		else if (ret > 0)
		{
			if (FD_ISSET(STDIN_FILENO, &readfds))
			{
				read(STDIN_FILENO, &c, 1);
				if (c == 'q')
					break;
				on_key_pressed(c, strat_list);
			}
		}
	}
	ft_free_all_tab(strat_list);	
	return 0;
}
