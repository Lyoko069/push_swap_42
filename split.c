/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   split.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/24 19:30:12 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/24 19:30:12 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	ft_word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static char	*ft_word_dup(const char *s, int len)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_free_split(char **words)
{
	int	i;

	if (words == NULL)
		return ;
	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(const char *s, char c)
{
	char	**words;
	int		count;
	int		i;

	count = ft_count_words(s, c);
	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		words[i] = ft_word_dup(s, ft_word_len(s, c));
		if (words[i] == NULL)
		{
			ft_free_split(words);
			return (NULL);
		}
		s += ft_word_len(s, c);
		i++;
	}
	words[i] = NULL;
	return (words);
}
