/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_funcs1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:55:38 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/26 17:49:50 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Duplicates a string.
 *
 * @param s1	String to be duplicated.
 * @return Pointer to the beginning of a dynamically allocated string.
 */
char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*newstr;

	i = 0;
	len = ft_strlen(s1);
	newstr = malloc(len + 1);
	if (!newstr)
		return (0);
	while (i < (len + 1))
	{
		newstr[i] = s1[i];
		i++;
	}
	return (newstr);
}

/**
 * @brief Concatenates a string onto the end of another string, whilst
 * maintaining memory safety.
 * @param dst		Destination string.
 * @param src		Source string.
 * @param dstsize	Maximum possible size of the destination string.
 * @return Total length of the string that we attempted to create. Makes
 * truncation detection easy.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	i;
	size_t	j;

	dstlen = ft_strlen(dst);
	if (dstlen >= dstsize)
		return (dstsize + ft_strlen(src));
	if (!dstsize)
		return (dstlen + ft_strlen(src));
	i = dstlen;
	j = 0;
	while (j < (dstsize - dstlen - 1) && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (dstlen + ft_strlen(src));
}

/**
 * @brief Copies a string onto another string. Whilst maintaining memory safety.
 *
 * @param dst		Destination string.
 * @param src		Source string.
 * @param dstsize	Maximum possible size of the destination string.
 * @return Total length of the string that we attempted to create. Makes
 * truncation detection easy.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

/**
 * @brief Compares two strings lexicographically up to a certain point.
 *
 * @param s1	First string to be compared.
 * @param s2	Second string to be compared.
 * @param n		Maximum number of bytes to compare.
 * @return The difference of the two strings, a positive number if s1 is
 * greater, a negative if s2 is greater, and zero if they're equivalent strings
 * up to n bytes.
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((t_byte)s1[i] - (t_byte)s2[i]);
}

/**
 * @brief Searches for the first occurence of a given string within another
 * string.
 * @param haystack	String to be searched through.
 * @param needle	String to be searched for.
 * @param len		Length of the haystack.
 * @return Pointer to the first occurence of the needle inside the haystack.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i[2];
	long long int	startpos;

	if (haystack == needle || !*needle)
		return ((char *)haystack);
	else if (!*haystack)
		return (0);
	i[0] = 0;
	i[1] = 0;
	startpos = -1;
	while ((i[0] < len) && needle[i[1]] && haystack[i[0]])
	{
		if (haystack[i[0]] == needle[i[1]])
		{
			i[1]++;
			if (startpos == -1)
				startpos = i[0];
		}
		else if (i[1])
			reset(&i[1], &i[0], &startpos);
		i[0]++;
	}
	if (!needle[i[1]])
		return ((char *)(haystack + i[0] - ft_strlen(needle)));
	return (0);
}
