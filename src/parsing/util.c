#include "cub3D.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char	*ft_strdup_trim(char *line)
{
	char	*new;
	int		i;

	if (!line)
		return (NULL);
	new = ft_calloc(ft_strlen(line), sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	return (new);
}

int	ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	get_max_len(char **map_2d)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (map_2d[i])
	{
		if ((int)ft_strlen(map_2d[i]) > max)
			max = ft_strlen(map_2d[i]);
		i++;
	}
	return (max);
}

void	ft_copy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}
