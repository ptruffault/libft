#include "../includes/libft.h"

char		*get_next_word(char *str)
{
	char	*word;
	int		j;

	j = 0;
	word = NULL;
	while (!(IS_SPACE(str[j])) && str[j] != '\0')
		j++;
	if (str[j] != '\0')
	{
		if (!(word = ft_strnew(j)))
		{
			error("allocation failed", "ft_strsplit_whitespace");
			return (NULL);
		}
		word = ft_strncpy(word, str, j);
	}
	return (word);
} 
