/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helldivers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:59:10 by lpetit            #+#    #+#             */
/*   Updated: 2024/02/25 14:02:38 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELLDIVERS_H
# define HELLDIVERS_H

#include <stdio.h>
#include <termios.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	**ft_split(char const *s, char c);

int	check_entry(int c, char **strat_list);

void	ft_free_all_tab(char **tab);
void	key_parsing(int c);

#endif
