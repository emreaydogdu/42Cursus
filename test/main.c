/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:50:19 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/12 14:08:45 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include "../libft/libft.h"
#include "util.c"
#include <stdio.h>
#include <stdlib.h>

void freeTab(char **tab)
{
	for (int i = 0; tab[i] != NULL; ++i)
		free(tab[i]);
	free(tab);
}

void	t_isalpha(void)
{
	printf("%s\t\t: ", "isalpha");
	ASSERT(isalpha('a' - 1) != 0 == ft_isalpha('a' - 1) != 0)
	ASSERT(isalpha('a') != 0 == ft_isalpha('a') != 0)
	ASSERT(isalpha('z' + 1) != 0 == ft_isalpha('z' + 1) != 0)
	ASSERT(isalpha('z') != 0 == ft_isalpha('z') != 0)
	ASSERT(isalpha('A' - 1) != 0 == ft_isalpha('A' - 1) != 0)
	ASSERT(isalpha('A') != 0 == ft_isalpha('A') != 0)
	ASSERT(isalpha('Z' + 1) != 0 == ft_isalpha('Z' + 1) != 0)
	ASSERT(isalpha('Z') != 0 == ft_isalpha('Z') != 0)
	printf("\n");
}

void	t_isdigit(void)
{
	printf("%s\t\t: ", "isdigit");
	ASSERT(isdigit('0' - 1) != 0 == ft_isdigit('0' - 1) != 0)
	ASSERT(isdigit('0') != 0 == ft_isdigit('0') != 0)
	ASSERT(isdigit('9' + 1) != 0 == ft_isdigit('9' + 1) != 0)
	ASSERT(isdigit('9') != 0 == ft_isdigit('9') != 0)
	printf("\n");
}

void	t_isalnum(void)
{
	printf("%s\t\t: ", "isalnum");
	ASSERT(isalnum('a' - 1) != 0 == ft_isalnum('a' - 1) != 0)
	ASSERT(isalnum('a') != 0 == ft_isalnum('a') != 0)
	ASSERT(isalnum('z' + 1) != 0 == ft_isalnum('z' + 1) != 0)
	ASSERT(isalnum('z') != 0 == ft_isalnum('z') != 0)
	ASSERT(isalnum('A' - 1) != 0 == ft_isalnum('A' - 1) != 0)
	ASSERT(isalnum('A') != 0 == ft_isalnum('A') != 0)
	ASSERT(isalnum('Z' + 1) != 0 == ft_isalnum('Z' + 1) != 0)
	ASSERT(isalnum('Z') != 0 == ft_isalnum('Z') != 0)
	ASSERT(isalnum('0' - 1) != 0 == ft_isalnum('0' - 1) != 0)
	ASSERT(isalnum('0') != 0 == ft_isalnum('0') != 0)
	ASSERT(isalnum('9' + 1) != 0 == ft_isalnum('9' + 1) != 0)
	ASSERT(isalnum('9') != 0 == ft_isalnum('9') != 0)
	printf("\n");
}

void	t_isascii(void)
{
	printf("%s\t\t: ", "isascii");
	ASSERT(isascii(-1) != 0 == ft_isascii(-1) != 0)
	ASSERT(isascii(0) != 0 == ft_isascii(0) != 0)
	ASSERT(isascii(128) != 0 == ft_isascii(128) != 0)
	ASSERT(isascii(127) != 0 == ft_isascii(127) != 0)
	printf("\n");
}

void	t_isprint(void)
{
	printf("%s\t\t: ", "isprint");
	ASSERT(isprint(' ' - 1) != 0 == ft_isprint(' ' - 1) != 0)
	ASSERT(isprint(' ') != 0 == ft_isprint(' ') != 0)
	ASSERT(isprint('~' + 1) != 0 == ft_isprint('~' + 1) != 0)
	ASSERT(isprint('~') != 0 == ft_isprint('~') != 0)
	printf("\n");
}

void	t_strlen(void)
{
	printf("%s\t\t: ", "strlen");
	ASSERT((strlen("123") == 3) == (ft_strlen("123") == 3))
	ASSERT((strlen("") == 0) == (ft_strlen("") == 0))
	ASSERT((strlen("14765872164") == 11) == (ft_strlen("14765872164") == 11))
	printf("\n");
}

void	t_memset(void)
{
	char	tab[100];
	int		i;

	printf("%s\t\t: ", "memset");
	memset(tab, 0, 100);
	ft_memset(tab, 'A', 0);
	ASSERT(tab[0] == 0)
	ft_memset(tab, 'A', 42);
	for (i = 0; i < 100 && tab[i] == 'A'; ++i) ;
	ASSERT(i == 42 && tab[42] == 0)
	printf("\n");
}

void	t_bzero(void)
{
	char	tab[100];
	int		i;

	printf("%s\t\t: ", "bzero");
	memset(tab, 'A', 100);
	ft_bzero(tab, 0);
	ASSERT(tab[0] == 'A')
	ft_bzero(tab, 42);
	for (i = 0; i < 100 && tab[i] == 0; ++i) ;
	ASSERT(i == 42 && tab[42] == 'A')
	for (i = 0; i < 100 && tab[i] == 0; ++i) ;
	ASSERT(i == 42)
	printf("\n");
}

void	t_memcpy(void)
{
	char	tab[100];
	char	*rtn;
	char	src[] = {0, 0};
	int		i;

	printf("%s\t\t: ", "memcpy");
	memset(tab, 'A', 100);
	ft_memcpy(tab, "coucou", 0);
	ASSERT(tab[0] == 'A')
	rtn = (char *)ft_memcpy(tab, NULL, 0);
	ASSERT(rtn == tab && tab[0] == 'A')
	ft_memcpy(tab, src, 2);
	for (i = 0; i < 100 && tab[i] == 0; ++i) ;
	ASSERT(i == 2 && tab[2] == 'A')
	printf("\n");
}

void	t_memmove(void)
{
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};

	printf("%s\t\t: ", "memmove");
	ASSERT(ft_memmove(s0, s, 7) == s0 && !memcmp(s, s0, 7))
	ASSERT(ft_memmove(s, s + 2, 0) && !memcmp(s, sCpy, 7))
	ASSERT(ft_memmove(s, s + 2, 2) == s && !memcmp(s, sResult, 7))
	ASSERT(ft_memmove(sResult + 1, sResult, 2) == sResult + 1 && !memcmp(sResult, sResult2, 7))
	printf("\n");
}

void	t_strlcpy(void)
{
	char src[] = "coucou";
	char dest[10]; memset(dest, 'A', 10);

	printf("%s\t\t: ", "strlcpy");
	ASSERT(ft_strlcpy(dest, src, 0) == strlen(src) && dest[0] == 'A')
	ASSERT(ft_strlcpy(dest, src, 1) == strlen(src) && dest[0] == 0 && dest[1] == 'A')
	ASSERT(ft_strlcpy(dest, src, 2) == strlen(src) && dest[0] == 'c' && dest[1] == 0  && dest[2] == 'A')
	ASSERT(ft_strlcpy(dest, src, -1) == strlen(src) && !strcmp(src, dest) && dest[strlen(src) + 1] == 'A') memset(dest, 'A', 10);
	ASSERT(ft_strlcpy(dest, src, 6) == strlen(src) && !memcmp(src, dest, 5) && dest[5] == 0) memset(dest, 'A', 10);
	ASSERT(ft_strlcpy(dest, src, 7) == strlen(src) && !memcmp(src, dest, 7)) memset(dest, 'A', 10);
	ASSERT(ft_strlcpy(dest, src, 8) == strlen(src) && !memcmp(src, dest, 7)) memset(dest, 'A', 10);
	ASSERT(ft_strlcpy(dest, "", 42) == 0 && !memcmp("", dest, 1)) memset(dest, 0, 10);
	ASSERT(ft_strlcpy(dest, "1", 0) == 1 && dest[0] == 0) memset(dest, 'A', 10);
	printf("\n");
}

void	t_strlcat(void)
{
	char dest[30]; memset(dest, 0, 30);
	char * src = (char *)"AAAAAAAAA";

	printf("%s\t\t: ", "strlcat");
	dest[0] = 'B';
	ASSERT(ft_strlcat(dest, src, 0) == strlen(src) && !strcmp(dest, "B"))
	dest[0] = 'B';
	ASSERT(ft_strlcat(dest, src, 1) == 10 && !strcmp(dest, "B"))
	memset(dest, 'B', 4);
	ASSERT(ft_strlcat(dest, src, 3) == 3 + strlen(src) && !strcmp(dest, "BBBB"))
	ASSERT(ft_strlcat(dest, src, 6) == 13 && !strcmp(dest, "BBBBA"))
	memset(dest, 'C', 5);
	ASSERT(ft_strlcat(dest, src, -1) == 14 && !strcmp(dest, "CCCCCAAAAAAAAA"))
	memset(dest, 'C', 15);
	ASSERT(ft_strlcat(dest, src, 17) == 24 && !strcmp(dest, "CCCCCCCCCCCCCCCA"))
	memset(dest, 0, 30);
	ASSERT(ft_strlcat(dest, src, 1) == strlen(src) && !strcmp(dest, ""))
	memset(dest, 0, 30); memset(dest, '1', 10);
	ASSERT(ft_strlcat(dest, src, 5) == strlen(src) + 5 && !strcmp(dest, "1111111111"))
	memset(dest, 0, 30); memset(dest, '1', 10);
	ASSERT(ft_strlcat(dest, src, 5) == strlen(src) + 5 && !strcmp(dest, "1111111111"))
	memset(dest, 0, 30); memset(dest, '1', 10);
	ASSERT(ft_strlcat(dest, "", 15) == 10 && !strcmp(dest, "1111111111"))
	memset(dest, 0, 30);
	ASSERT(ft_strlcat(dest, "", 42) == 0 && !strcmp(dest, ""))
	memset(dest, 0, 30);
	ASSERT(ft_strlcat(dest, "", 0) == 0 && !strcmp(dest, ""))
	memset(dest, 0, 30);
	ASSERT(ft_strlcat(dest, "123", 1) == 3 && !strcmp(dest, ""))
	memset(dest, 0, 30);
	ASSERT(ft_strlcat(dest, "123", 2) == 3 && !strcmp(dest, "1"))
	memset(dest, 0, 30);
	ASSERT(ft_strlcat(dest, "123", 3) == 3 && !strcmp(dest, "12"))
	memset(dest, 0, 30);
	ASSERT(ft_strlcat(dest, "123", 4) == 3 && !strcmp(dest, "123"))
	memset(dest, 0, 30);
	ASSERT(ft_strlcat(dest, "123", 0) == 3 && !strcmp(dest, ""))
	printf("\n");
}

void	t_toupper(void)
{
	printf("%s\t\t: ", "toupper");
	ASSERT(ft_toupper('a' - 1) == 'a' - 1)
	ASSERT(ft_toupper('a') == 'A')
	ASSERT(ft_toupper('z' + 1) == 'z' + 1)
	ASSERT(ft_toupper('z') == 'Z')
	printf("\n");
}

void	t_tolower(void)
{
	printf("%s\t\t: ", "tolower");
	ASSERT(ft_tolower('A' - 1) == 'A' - 1)
	ASSERT(ft_tolower('A') == 'a')
	ASSERT(ft_tolower('Z' + 1) == 'Z' + 1)
	ASSERT(ft_tolower('Z') == 'z')
	printf("\n");
}

void	t_strchr(void)
{
	char s[] = "tripouille";

	printf("%s\t\t: ", "strchr");
	ASSERT(ft_strchr(s, 't') == s)
	ASSERT(ft_strchr(s, 'l') == s + 7)
	ASSERT(ft_strchr(s, 'z') == 0)
	ASSERT(ft_strchr(s, 0) == s + strlen(s))
	ASSERT(ft_strchr(s, 't' + 256) == s)
	printf("\n");
}

void	t_strrchr(void)
{
	char s[] = "tripouille";
	char s2[] = "ltripouiel";

	printf("%s\t\t: ", "strrchr");
	ASSERT(ft_strrchr(s, 't') == s)
	ASSERT(ft_strrchr(s, 'l') == s + 8)
	ASSERT(ft_strrchr(s2, 'l') == s2 + 9)
	ASSERT(ft_strrchr(s, 'z') == NULL)
	ASSERT(ft_strrchr(s, 0) == s + strlen(s))
	ASSERT(ft_strrchr(s, 't' + 256) == s)
	char * empty = (char*)ft_calloc(1, 1);
	ASSERT(ft_strrchr(empty, 'V') == NULL) free(empty); t_leak();
	printf("\n");
}

void	t_strncmp(void)
{
	printf("%s\t\t: ", "strncmp");
	ASSERT(ft_strncmp("t", "", 0) == 0)
	ASSERT(ft_strncmp("1234", "1235", 3) == 0)
	ASSERT(ft_strncmp("1234", "1235", 4) < 0)
	ASSERT(ft_strncmp("1234", "1235", -1) < 0)
	ASSERT(ft_strncmp("", "", 42) == 0)
	ASSERT(ft_strncmp("Tripouille", "Tripouille", 42) == 0)
	ASSERT(ft_strncmp("Tripouille", "tripouille", 42) < 0)
	ASSERT(ft_strncmp("Tripouille", "TriPouille", 42) > 0)
	ASSERT(ft_strncmp("Tripouille", "TripouillE", 42) > 0)
	ASSERT(ft_strncmp("Tripouille", "TripouilleX", 42) < 0)
	ASSERT(ft_strncmp("Tripouille", "Tripouill", 42) > 0)
	ASSERT(ft_strncmp("", "1", 0) == 0)
	ASSERT(ft_strncmp("1", "", 0) == 0)
	ASSERT(ft_strncmp("", "1", 1) < 0)
	ASSERT(ft_strncmp("1", "", 1) > 0)
	ASSERT(ft_strncmp("", "", 1) == 0)
	printf("\n");
}

void	t_memchr(void)
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};

	printf("%s\t\t: ", "memchr");
	ASSERT(ft_memchr(s, 0, 0) == NULL)
	ASSERT(ft_memchr(s, 0, 1) == s)
	ASSERT(ft_memchr(s, 2, 3) == s + 2)
	ASSERT(ft_memchr(s, 6, 6) == NULL)
	ASSERT(ft_memchr(s, 2 + 256, 3) == s + 2)
	printf("\n");
}

void	t_memcmp(void)
{
	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};

	printf("%s\t\t: ", "memcmp");
	ASSERT(!ft_memcmp(s, sCpy, 4))
	ASSERT(!ft_memcmp(s, s2, 0))
	ASSERT(ft_memcmp(s, s2, 1) > 0)
	ASSERT(ft_memcmp(s2, s, 1) < 0)
	ASSERT(ft_memcmp(s2, s3, 4) != 0)
	printf("\n");
}

void	t_strnstr(void)
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	char * empty = (char*)"";

	printf("%s\t\t: ", "strnstr");
	ASSERT(ft_strnstr(haystack, needle, 0) == 0)
	ASSERT(ft_strnstr(haystack, needle, -1) == haystack + 1)
	ASSERT(ft_strnstr(haystack, "a", -1) == haystack)
	ASSERT(ft_strnstr(haystack, "c", -1) == haystack + 4)
	ASSERT(ft_strnstr(empty, "", -1) == empty)
	ASSERT(ft_strnstr(empty, "", 0) == empty)
	ASSERT(ft_strnstr(empty, "coucou", -1) == 0)
	ASSERT(ft_strnstr(haystack, "aaabc", 5) == haystack)
	ASSERT(ft_strnstr(empty, "12345", 5) == 0)
	ASSERT(ft_strnstr(haystack, "abcd", 9) == haystack + 5)
	ASSERT(ft_strnstr(haystack, "cd", 8) == NULL)
	ASSERT(ft_strnstr(haystack, "a", 1) == haystack)
	ASSERT(ft_strnstr("1", "a", 1) == NULL)
	ASSERT(ft_strnstr("22", "b", 2) == NULL)
	printf("\n");
}

void	t_atoi(void)
{
	printf("%s\t\t: ", "atoi");
	ASSERT(ft_atoi(("1")) == 1)
	ASSERT(ft_atoi(("a1")) == 0)
	ASSERT(ft_atoi(("--1")) == 0)
	ASSERT(ft_atoi(("++1")) == 0)
	ASSERT(ft_atoi(("+1")) == 1)
	ASSERT(ft_atoi(("-1")) == -1)
	ASSERT(ft_atoi("0") == 0)
	ASSERT(ft_atoi("+42lyon") == 42)
	ASSERT(ft_atoi("+101") == 101)
	ASSERT(ft_atoi("2147483647") == 2147483647)
	ASSERT(ft_atoi("2147483648") == atoi("2147483648"))
	ASSERT(ft_atoi("-+42") == 0)
	ASSERT(ft_atoi("+-42") == 0)
	ASSERT(ft_atoi("+ 42")== 0)
	ASSERT(ft_atoi("- 42") == 0)
	ASSERT(ft_atoi("1 42") == 1)
	ASSERT(ft_atoi("-1 42") == -1)
	printf("\n");
}

void	t_calloc(void)
{
	printf("\n%s\t\t: ", "calloc");
	void * p = ft_calloc(2, 2);
	char e[] = {0, 0, 0, 0};
	ASSERT(!memcmp(p, e, 4))
	free(p); t_leak();
	ASSERT(ft_calloc(SIZE_MAX, SIZE_MAX) == NULL)
	printf("\n");
}

void	t_strdup(void)
{
	printf("%s\t\t: ", "strdup");
	char * s = ft_strdup((char*)"coucou");
	ASSERT(!strcmp(s, "coucou")) free(s); t_leak();
	s = ft_strdup((char*)"");
	ASSERT(!strcmp(s, "")) free(s); t_leak();
	printf("\n");
}

void	t_substr(void)
{
	printf("\n%s\t\t: ", "substr");
	char * s = ft_substr("tripouille", 0, 42000);
	ASSERT(!strcmp(s, "tripouille")) free(s); t_leak();
	s = ft_substr("tripouille", 1, 1);
	ASSERT(!strcmp(s, "r")) free(s); t_leak();
	s = ft_substr("tripouille", 100, 1);
	ASSERT(!strcmp(s, "")) free(s); t_leak();
	char * str = ft_strdup("1");
	s = ft_substr(str, 42, 42000000);
	ASSERT(!strcmp(s, "")) free(s); free(str); t_leak();
	str = ft_strdup("0123456789");
	s = ft_substr(str, 9, 10);
	ASSERT(!strcmp(s, "9")) free(s); free(str); t_leak();
	s = ft_substr("42", 0, 0);
	ASSERT(!strcmp(s, "")) free(s); t_leak();
	s = ft_substr("BONJOUR LES HARICOTS !", 8, 14);
	ASSERT(!strcmp(s, "LES HARICOTS !")) free(s); t_leak();
	s = ft_substr("test", 1, 2);
	ASSERT(!strcmp(s, "es")) free(s); t_leak();
	printf("\n");
}

void	t_strjoin(void)
{
	printf("%s\t\t: ", "strjoin");
	char * s = ft_strjoin("tripouille", "42");
	ASSERT(!strcmp(s, "tripouille42")) free(s); t_leak();
	s = ft_strjoin("", "42");
	ASSERT(!strcmp(s, "42")) free(s); t_leak();
	s = ft_strjoin("42", "");
	ASSERT(!strcmp(s, "42")) free(s); t_leak();
	char * str = ft_strdup("1");
	s = ft_strjoin("", "");
	ASSERT(!strcmp(s, "")) free(s); free(str); t_leak();
	printf("\n");
}

void	t_strtrim(void)
{
	printf("%s\t\t: ", "strtrim");
	char * s = ft_strtrim("   xxxtripouille", " x");
	ASSERT(!strcmp(s, "tripouille")) free(s); t_leak();
	s = ft_strtrim("tripouille   xxx", " x");
	ASSERT(!strcmp(s, "tripouille")) free(s); t_leak();
	s = ft_strtrim("   xxxtripouille   xxx", " x");
	ASSERT(!strcmp(s, "tripouille")) free(s); t_leak();
	char * str = ft_strdup("1");
	s = ft_strtrim("   xxx   xxx", " x");
	ASSERT(!strcmp(s, "")) free(s); free(str); t_leak();
	s = ft_strtrim("", "123");
	ASSERT(!strcmp(s, "")) free(s); t_leak();
	s = ft_strtrim("123", "");
	ASSERT(!strcmp(s, "123")) free(s); t_leak();
	s = ft_strtrim("", "");
	ASSERT(!strcmp(s, "")) free(s); t_leak();
	s = ft_strtrim("abcdba", "acb");
	ASSERT(!strcmp(s, "d")) free(s); t_leak();
	printf("\n");
}

void	t_split(void)
{
	printf("%s\t\t: ", "split");
	char **tab = ft_split("  tripouille  42  ", ' ');
	ASSERT(!strcmp(tab[0], "tripouille"))
	ASSERT(!strcmp(tab[1], "42"))
	ASSERT(tab[2] == NULL) freeTab(tab); t_leak();

	tab = ft_split("tripouille", 0);
	ASSERT(!strcmp(tab[0], "tripouille"))
	ASSERT(tab[1] == NULL) freeTab(tab); t_leak();

	tab = ft_split("     ", ' ');
	ASSERT(tab[0] == NULL) freeTab(tab); t_leak();

	tab = ft_split("chinimala", ' ');
	ASSERT(!strcmp(tab[0], "chinimala"))
	ASSERT(tab[1] == NULL) freeTab(tab); t_leak();

	tab = ft_split("", ' ');
	ASSERT(tab[0] == NULL) freeTab(tab); t_leak();

	char * splitme = ft_strdup("Tripouille");
	tab = ft_split(splitme, ' ');
	ASSERT(!strcmp(tab[0], "Tripouille"))
	ASSERT(tab[1] == NULL) free(splitme); freeTab(tab); t_leak();

	splitme = ft_strdup("Tripouille ");
	tab = ft_split(splitme, ' ');
	ASSERT(!strcmp(tab[0], "Tripouille"))
	ASSERT(tab[1] == NULL) free(splitme); freeTab(tab); t_leak();

	splitme = ft_strdup(" Tripouille");
	tab = ft_split(splitme, ' ');
	ASSERT(!strcmp(tab[0], "Tripouille"))
	ASSERT(tab[1] == NULL) free(splitme); freeTab(tab); t_leak();

	splitme = ft_strdup(" Tripouille ");
	tab = ft_split(splitme, ' ');
	ASSERT(!strcmp(tab[0], "Tripouille"))
	ASSERT(tab[1] == NULL) free(splitme); freeTab(tab); t_leak();

	splitme = ft_strdup("--1-2--3---4----5-----42");
	tab = ft_split(splitme, '-');
	ASSERT(!strcmp(tab[0], "1"))
	ASSERT(!strcmp(tab[1], "2"))
	ASSERT(!strcmp(tab[2], "3"))
	ASSERT(!strcmp(tab[3], "4"))
	ASSERT(!strcmp(tab[4], "5"))
	ASSERT(!strcmp(tab[5], "42"))
	ASSERT(tab[6] == NULL) free(splitme); freeTab(tab); t_leak();
	printf("\n");
}

void	t_itoa(void)
{
	printf("%s\t\t: ", "itoa");
	char *s = ft_itoa(INT_MAX);
	ASSERT(!strcmp(s, "2147483647")) free(s); t_leak();

	s = ft_itoa(INT_MIN);
	ASSERT(!strcmp(s, "-2147483648")) free(s); t_leak();
	printf("\n");
}

int	main(void)
{
	/*
	t_isalpha();
	t_isdigit();
	t_isalnum();
	t_isascii();
	t_isprint();
	t_strlen();
	t_memset();
	t_bzero();
	t_memcpy();
	t_memmove();
	t_strlcpy();
	t_strlcat();
	t_toupper();
	t_tolower();
	t_strchr();
	t_strrchr();
	t_strncmp();
	t_memchr();
	t_memcmp();
	t_strnstr();
	t_atoi();

	t_calloc();
	t_strdup();

	t_substr();
	t_strjoin();
	t_strtrim();
	t_split();
	t_itoa();

	char	**tabstr;
	if (!(tabstr = ft_split(0, 0)))
		printf("NULL\n");
	else
	if (!tabstr[0])
		printf("OK\n");
	/
	char	**tabstr;
	int i = 0;
	if (!(tabstr = ft_split("", 'z')))
		printf("NULL\n");
	else
	if (!tabstr[0])
		printf("OK\n");

	i = 0;
	if (!(tabstr = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')))
		printf("NULL\n");
	else
	{
		while (tabstr[i] != NULL)
		{
			printf("%s\n", tabstr[i]);
			i++;
		}

		*/


	printf("%s\n", ft_split("Hallo!", ' '));
	return (0);
}
