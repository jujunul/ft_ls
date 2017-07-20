#include "libft.h"

char *ft_strcat_path(char *s1, char *s2)
{
		return (ft_strcat(ft_strcat(s1, "/"), s2));
}

int main(void)
{
	char *c;

	c = malloc(sizeof(char) * 1000);
	c[0] = '.';
	ft_putstr(ft_strcat_path(c, "bonjour"));
	return (0);
}
