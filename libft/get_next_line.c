#include "libft.h"

static char	*get_ret(int fd, char *buff, char *rem)
{
	ssize_t		check_read;
	char		*tmp;

	check_read = 1;
	while (check_read > 0)
	{
		check_read = read(fd, buff, BUFFER_SIZE);
		if (check_read == -1)
		{
			free(rem);
			return (NULL);
		}
		if (check_read == 0)
			break ;
		buff[check_read] = '\0';
		if (!rem)
			rem = ft_strdup("");
		tmp = rem;
		rem = ft_strjoin(tmp, buff);
		free(tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (rem);
}

static char	*get_rem(char *ret)
{
	char	*rem;
	ssize_t	i;

	i = 0;
	while (ret[i] != '\n' && ret[i] != '\0')
		i++;
	if (ret[i] == 0 || ret[1] == 0)
		return (NULL);
	rem = ft_substr(ret, i + 1, ft_strlen(ret) - i);
	if (*rem == '\0')
	{
		free(rem);
		rem = NULL;
	}
	ret[i + 1] = 0;
	return (rem);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*ret;
	static char	*rem = NULL;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		free(rem);
		buffer = NULL;
		rem = NULL;
		return (NULL);
	}
	ret = get_ret(fd, buffer, rem);
	free (buffer);
	if (!ret)
		return (NULL);
	rem = get_rem(ret);
	return (ret);
}
