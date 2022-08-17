/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:31:58 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/17 14:37:36 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	swap_contents(char *str_array[], int index1, int index2)
{
	char	*temp;

	temp = str_array[index1];
	str_array[index1] = str_array[index2];
	str_array[index2] = temp;
}

int	check_if_ordered(char *str_array[], int array_length)
{
	int	i;
	int	j;

	printf("begin checking\n");
	i = 0;
	while (i < array_length - 1)
	{
		printf("	i is %d now, %d < %d\n", i, i, array_length - 1);
		j = 0;
		while (str_array[i][j] == str_array[i + 1][j])
		{
			printf("	\tj is %d now, string: %s with %s\n", j, str_array[i], str_array[i + 1]);
			if (str_array[i][j] == 0 && str_array[i + 1][j] != 0)
				break ;
			if (str_array[i][j] != 0 && str_array[i + 1][j] == 0)
				return (0);
			j++;
			printf("	\t\tj++\n");
		}
		if (str_array[i][j] > str_array[i + 1][j])
			return (0);
		i++;
	}
	return (1);
}

void	order_array(char *str_array[], int array_length)
{
	int	i;
	int	j;
	// printf("array length: %d\n", array_length);
	i = 0;
	while (!check_if_ordered(str_array, array_length))
	{
		printf("begin order array\n");
		printf("	i is %d now, %d < %d\n", i, i, array_length - 1);
		j = 0;
		while (str_array[i][j] == str_array[i + 1][j])
		{
			printf("	\tj is %d now, string: %s with %s\n", j, str_array[i], str_array[i + 1]);
			if (str_array[i][j] == 0 || str_array[i + 1][j] == 0)
				break ;
			j++;
		}

		i = 0;
		printf("i in order array\n");
		while (i < (array_length - 1) && str_array[i][j] <= str_array[i + 1][j])
		{
			i++;
			// printf("i is %d now, %d < %d\n", i, i, array_length - 1);
		}
		// printf("about to swap %s and %s\n", str_array[i], str_array[i + 1]);
		// printf("i is %d now, %d < %d\n", i, i, array_length - 1);
		if (i < array_length - 1)
			swap_contents(str_array, i, i + 1);
		printf("result: %s %s %s %s %s\n", str_array[0], str_array[1], str_array[2], str_array[3], str_array[4]);
		// printf("is ordered? %d\n", check_if_ordered(str_array, array_length));
	}
}

int	main(int argc, char *argv[])
{
	int		arguments;
	int		c;
	char	**start;

	if (argc == 1)
		return (0);
	start = argv + 1;
	order_array(start, argc - 1);
	arguments = 1;
	while (arguments < argc)
	{
		c = 0;
		while (argv[arguments][c])
		{
			write(1, argv[arguments] + c, 1);
			c++;
		}
		write(1, "\n", 1);
		arguments++;
	}
	return (0);
}