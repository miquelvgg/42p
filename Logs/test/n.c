#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif


char	*ft_strdup(const char *s)
{
	int		i;
	int		l;
	char	*p_res;

	if (s == NULL)
		return (NULL);
	l = 0;
	while (s[l] != '\0')
		l++;
	p_res = malloc((l + 1) * sizeof(char));
	if (!p_res)
		return (NULL);
	i = 0;
	while (i < l)
	{
		p_res[i] = s[i];
		i++;
	}
	p_res[i] = '\0';
	return (p_res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int ft_first_sl(char *str)
{
	int i;
	int sl;
	
	sl = 0;
	if (str == NULL)
		return 0;
	i = 0 ;
	while (str[i] != '\0') 
	{
		if (str[i] == '\n')
			return(i);
		i++;
	}
	return sl;
}


static void	ft_lenstr(char const *s1, char const *s2, size_t *l1, size_t *l2)
{
	*l1 = 0;
	while (s1[*l1] != '\0')
		(*l1)++;
	*l2 = 0;
	while (s2[*l2] != '\0')
		(*l2)++;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		l1;
	size_t		l2;
	char		*p_res;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	ft_lenstr(s1, s2, &l1, &l2);
	p_res = (char *)malloc((l1 + l2 + 1) * sizeof(char));
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


char *get_next_line(int fd)
{
	int		nb_read;
	int		count;
	char 	*tmp;
	char	*buf;
//	static char	*buf_ln[OPEN_MAX];
	static char	*buf_ln;
	int len;

	tmp = NULL;
	count = 0;
	nb_read = 0;
	if ((BUFFER_SIZE < 1) || (fd == 1 ) || (fd == 2))
		return (NULL);
	// cuidado si llega de nuevo y hay un salto de linea en la parte de linea que no se a procesado 
	// y que pasa con ese trozo al cargar de nuevo 
	while (count == 0 )	
	{
		buf = malloc(BUFFER_SIZE+1);
		if (!buf)
			return (NULL);
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read < 0)
		{
			free(buf);
			return (NULL);
		} 
		count=ft_first_sl(buf);

		if (count == 0)
		{	
			tmp =ft_strjoin(buf_ln,buf);
			free(buf);
			if (buf_ln)
				free(buf_ln);
			buf_ln = tmp;
			if (nb_read < BUFFER_SIZE)
				return (buf_ln);
		} 
		else 
		{   
			if (buf_ln == NULL)
			{
				len = 0;
				tmp = ft_strdup(buf); 
			}
			else
			{
				len = ft_strlen(buf_ln);
				tmp = ft_strjoin(buf_ln, buf); 
				if (buf_ln)
					free(buf_ln);
			}
			
			buf_ln = ft_strdup(buf + count+1); 
			tmp[len + count + 1]='\0';
		}
		
	}
	return(tmp); 
}


int main() {
	
	int		fd= 0;		// file descriptor to read
	char	* buffer = NULL;
	int 	count;


	count = 0;
	printf("\n %d \n",10);
	if ((fd) || (buffer))
		return (0);

	fd = open("cat.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	buffer =get_next_line(fd);
	while ((buffer != NULL) && (buffer[0] != '\0'))
	{
		printf("%s",buffer);
		if (buffer)
			free(buffer);
		buffer =get_next_line(fd);
		count++;
	}
	close(fd);
	return (0);
}
