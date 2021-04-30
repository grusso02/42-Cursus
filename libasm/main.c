#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char * dst, const char * src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);

int main()
{
	char a[11] = "Ciao";
	char b[3000];

	//printf("%zu", ft_strlen(a));

	//printf("%s", ft_strcpy(b, a));

	//printf("%d\n", ft_strcmp(a, b));
	//printf("%d", strcmp(a, b));

	//ft_write(1, a, 1);

	//int fd = open("text.txt", O_RDONLY);
	//ft_read(fd, b, 3000);
	//printf("%s\n", b);
}