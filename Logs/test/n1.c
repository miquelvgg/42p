#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*ft_strdup_custom(const char *s)
{
	int		i;
	int		length;
	char	*p_res;

	if (s == NULL)
		return (NULL);
	length = 0;
	while (s[length] != '\0')
		length++;
	p_res = malloc((length + 1) * sizeof(char));
	if (!p_res)
		return (NULL);
	i = 0;
	while (i < length)
	{
		p_res[i] = s[i];
		i++;
	}
	p_res[i] = '\0';
	return (p_res);
}

size_t	ft_strlen_custom(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_first_sl(char *str)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_lenstr(const char *s1, const char *s2, size_t *l1, size_t *l2)
{
	*l1 = 0;
	while (s1[*l1] != '\0')
		(*l1)++;
	*l2 = 0;
	while (s2[*l2] != '\0')
		(*l2)++;
}

char	*ft_strjoin_custom(const char *s1, const char *s2)
{
	size_t	i;
	size_t	l1;
	size_t	l2;
	char	*p_res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ft_lenstr(s1, s2, &l1, &l2);
	p_res = malloc((l1 + l2 + 1) * sizeof(char));
	if (p_res == NULL)
		return (NULL);
	i = 0;
	while (i < (l1 + l2))
	{
		if (i < l1)
			p_res[i] = s1[i];
		else
			p_res[i] = s2[i - l1];
		i++;
	}
	p_res[i] = '\0';
	return (p_res);
}

static char	*append_buffer(char *buf_ln, char *buf)
{
	char	*tmp;

	if (buf_ln)
	{
		tmp = ft_strjoin_custom(buf_ln, buf);
		free(buf_ln);
	}
	else
	{
		tmp = ft_strdup_custom(buf);
	}
	return (tmp);
}

static char	*create_line(const char *buf, int count)
{
	char	*line;
	int		i;

	line = malloc(count + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (i <= count)
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*merge_buffers(char *buf_ln, const char *buf, int count)
{
	char	*line;
	char	*new_buf;
	int		len;
	int		i;

	if (buf_ln == NULL)
	{
		line = create_line(buf, count);
	}
	else
	{
		len = ft_strlen_custom(buf_ln);
		line = malloc(len + count + 2);
		if (!line)
			return (NULL);
		i = 0;
		while (i < len)
		{
			line[i] = buf_ln[i];
			i++;
		}
		i = 0;
		while (i <= count)
		{
			line[len + i] = buf[i];
			i++;
		}
		line[len + i] = '\0';
		free(buf_ln);
	}
	new_buf = ft_strdup_custom(buf + count + 1);
	if (!new_buf)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*read_buffer(int fd, char **buf_ln)
{
	char	*buf;
	char	*tmp;
	int		nb_read;
	int		count;

	while (ft_first_sl(*buf_ln) == -1)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read < 0)
		{
			free(buf);
			return (*buf_ln);
		}
		buf[nb_read] = '\0';
		count = ft_first_sl(buf);
		if (count == -1)
		{
			tmp = append_buffer(*buf_ln, buf);
			free(buf);
			*buf_ln = tmp;
			if (nb_read < BUFFER_SIZE)
				break ;
		}
		else
		{
			tmp = merge_buffers(*buf_ln, buf, count);
			free(buf);
			return (tmp);
		}
	}
	return (*buf_ln);
}

static char	*extract_line(char **buf_ln)
{
	char	*line;
	char	*new_buf;
	int		count;

	count = ft_first_sl(*buf_ln);
	if (count == -1)
	{
		line = ft_strdup_custom(*buf_ln);
		free(*buf_ln);
		*buf_ln = NULL;
		return (line);
	}
	line = create_line(*buf_ln, count);
	if (!line)
		return (NULL);
	new_buf = ft_strdup_custom(*buf_ln + count + 1);
	free(*buf_ln);
	*buf_ln = new_buf;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf_ln;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0 || fd == 1 || fd == 2)
		return (NULL);
	buf_ln = read_buffer(fd, &buf_ln);
	if (buf_ln == NULL)
		return (NULL);
	line = extract_line(&buf_ln);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*buffer;
	int		count;

	count = 0;
	printf("\n%d\n", 10);
	fd = open("cat.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	buffer = get_next_line(fd);
	while (buffer != NULL && buffer[0] != '\0')
	{
		printf("%s", buffer);
		if (buffer)
			free(buffer);
		buffer = get_next_line(fd);
		count++;
	}
	close(fd);
	if (buffer)
		free(buffer);
	return (0);
}
