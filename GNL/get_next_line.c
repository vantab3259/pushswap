/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:44:30 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/18 02:52:59 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_addtotmp(char *tmp, int fd)
{
	int		check;
	char	*buffer;

	check = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(tmp, '\n'))
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[check] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (check == 0 && tmp)
		{
			free(buffer);
			return (tmp);
		}
	}
	free(buffer);
	return (tmp);
}

char	*extract_and_addtores(char *tmp)
{
	int		i;
	char	*res;

	i = 0;
	if (!*tmp)
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	res = malloc(sizeof(char) * i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
			res[i] = tmp[i];
			i++;
	}
	if (tmp[i] == '\n')
	{
		res[i] = tmp[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*collect_andaddtotmp(char *tmp)
{
	char	*rest;
	int		i;
	int		j;

	j = 0;
	i = 0;
	rest = NULL;
	while (tmp[i] && tmp[i] != '\n')
			i++;
	if (!tmp[i])
	{
		free(tmp);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(tmp) - i));
	if (!rest)
		return (NULL);
	i = i + 1;
	while (tmp[i])
		rest[j++] = tmp[i++];
	rest[j] = '\0';
	free(tmp);
	return (rest);
}

char	*get_next_line(int fd, int b)
{
	static char		*tmp;
	char			*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (b)
		return(free(tmp), NULL);
	tmp = read_and_addtotmp(tmp, fd);
	if (!tmp)
		return (NULL);
	res = extract_and_addtores(tmp);
	tmp = collect_andaddtotmp(tmp);
	return (res);
}

// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	fd = open("txt", O_RDONLY);
// 	while (i != 6)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		free (str);
// 		i++;
// 	}
// }
