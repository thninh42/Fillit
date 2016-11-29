/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 22:27:23 by thninh            #+#    #+#             */
/*   Updated: 2016/11/29 11:13:55 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_clean_grid(char **grid, char letter)
{
	int			i;
	int			j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == letter)
				grid[i][j] = '.';
			j++;
		}
		i++;
	}
}

char			**ft_new_grid(int len)
{
	int			i;
	int			j;
	char		**result;

	i = 0;
	result = (char**)malloc(sizeof(char*) * len + 1);
	if (!result)
		ft_putstr("malloc error in new_grid(1)\n");
	result[len] = NULL;
	while (len - i)
	{
		result[i] = (char*)malloc(sizeof(char) * len);
		if (!result[i])
			ft_putstr("malloc error in new_grid(2)\n");
		j = 0;
		while (len - j)
		{
			result[i][j] = '.';
			j++;
		}
		result[i][j] = '\0';
		i++;
	}
	return (result);
}

void			ft_print_grid(char **tab)
{
	int			i;
	int			j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

char			**ft_copy_grid(char **grid, int len)
{
	int			i;
	int			j;
	char		**result;

	i = 0;
	result = ft_new_grid(len + 1);
	while (len - i)
	{
		j = 0;
		while (len - j)
		{
			if (grid[i][j] != '.')
				result[i][j] = grid[i][j];
			j++;
		}
		result[i][j] = '\0';
		i++;
	}
	result[i] = NULL;
	return (result);
}

char			ft_grid_isfull(char **tab)
{
	int			i;
	int			j;
	int			c;

	c = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '.')
				c++;
			j++;
		}
		i++;
	}
	if (c < 4)
		return (1);
	return (0);
}
