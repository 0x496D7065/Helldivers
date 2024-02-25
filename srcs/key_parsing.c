/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:31:55 by lpetit            #+#    #+#             */
/*   Updated: 2024/02/25 16:52:23 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helldivers.h"

void	key_parsing(int c)
{
	if (c == 'w')
		printf("\U0001F845");
	if (c == 's')
		printf("\U0001F847");
	if (c == 'a')
		printf("\U0001F844");
	if (c == 'd')
		printf("\U0001F846");
	fflush(stdout);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 32)
		i++;
	while (str[i] == 32)
		i++;
	write(1, " ", 1);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_valid(int index, int	*forget)
{
	int	i;

	i = 0;
	while (i < 60)
	{
		if (forget[i] == index)
			return (0);
		i++;
	}
	return (1);
}

void	ft_reset(int *i, int *forget, int *i_forget)
{
	int	n;

	n = 0;
	*i = 0;
	*i_forget = 0;
	while (n < 60)
		forget[n++] = 0;
}

int	check_entry(int c, char **strat_list)
{
	static	int	i;
	static	int	forget[60];
	static	int	i_forget;
	int		index;
	int		n;

	index = 0;
	n = 0;
	while (strat_list[index])
	{
		while (strat_list[n])
		{
			if (strat_list[n][i] != c)
			{
				if (is_valid(n, forget) == 1)
				{
					forget[i_forget] = n;
					i_forget++;
				}
			}
			n++;
		}
		if (strat_list[index][i] == c && is_valid(index, forget) == 1)
		{
			i += 1;
			if (strat_list[index][i] == 32)
			{
				key_parsing(c);
				ft_putstr(strat_list[index]);
				ft_reset(&i, forget, &i_forget);
				return (2);
			}
			return (1);
		}
		index++;	
	}
	ft_reset(&i, forget, &i_forget);
	return (0);
}
