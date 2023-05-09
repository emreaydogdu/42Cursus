/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:50:19 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/09 16:39:58 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ctype.h>
#include <string.h>
#include "../libft.h"
#include "util.c"

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
/*
void	t_memset(void){
	char	str1[20] = "42 Berlin";
	char	str2[20] = "42 Berlin";

	ft_memset(str1, '*', 19);
	memset(str2, '*', 19);
	//printf("%s\n", str1);
	//printf("%s\n", str2);
	ASSERT(!strcmp(str1, str2), "memset()");
}
void	t_bzero(void){
	char	str1[20] = "42 Berlin";
	char	str2[20] = "42 Berlin";

	bzero(str1, 3);
	ft_bzero(str2, 3);
	//printf("%s\n", str1+3);
	//printf("%s\n", str2+3);
	ASSERT(!strcmp(str1+3, str2+3), "bzero()");
}
void	t_toupper(char c){
	ASSERT(toupper(c) == ft_toupper(c), "toupper()");
}
void	t_tolower(char c){
	ASSERT(tolower(c) == ft_tolower(c), "tolower()");
}
void	t_strnstr(void){
	char *big = "42 Berlin";
	char *little = "Berlin";

	//printf("%s\n", strnstr(big, little, 6));
	//printf("%s\n", ft_strnstr(big, little, 6));
	ASSERT(strnstr(big, little, 9) == ft_strnstr(big, little, 9), "strnstr()");
}
void	t_strncmp(void){
	char *s1 = "42 Berlin";
	char *s2 = "42 Berlin";

	//printf("%d\n", strncmp(s1, s2, 9));
	//printf("%d\n", ft_strncmp(s1, s2, 9));
	ASSERT(strncmp(s1, s2, 9) == ft_strncmp(s1, s2, 9), "strncmp()");
}
void	t_strchr(void){
	char *s1 = "42 Berlin";
	char *s2 = "42 Berlin";
	char c = 'B';

	//printf("%s\n", strchr(s1, c));
	//printf("%s\n", ft_strchr(s2, c));
	ASSERT(strchr(s1, c) == ft_strchr(s2, c), "strchr()");
}
void	t_strrchr(void){
	char *s1 = "42 BerBlin";
	char *s2 = "42 BerBlin";
	char c = 'B';

	//printf("%s\n", strrchr(s1, c));
	//printf("%s\n", ft_strrchr(s2, c));
	ASSERT(strrchr(s1, c) == ft_strrchr(s2, c), "strchr()");
}
void	t_strlcpy(void){
	char s1[20] = "42 Berlin";
	char s2[20] = "42 Berlin";
	char d1[20] = "99 Bremen";
	char d2[20] = "99 Bremen";

	//printf("%lu\n", strlcpy(d1, s1, sizeof(d1)));
	//printf("%lu\n", strlcpy(d2, s2, sizeof(d2)));
	ASSERT(strlcpy(d1, s1, sizeof(d1)) == ft_strlcpy(d2, s2, sizeof(d2)), "strlcpy()");
}
void	t_strlcat(void){
	char s1[20] = "42 Berlin";
	char s2[20] = "42 Berlin";
	char d1[20] = "99 Bremen";
	char d2[20] = "99 Bremen";

	//printf("%lu\n", strlcat(d1, s1, sizeof(d1)));
	//printf("%lu\n", ft_strlcat(d2, s2, sizeof(d2)));
	//printf("%s\n", d1);
	//printf("%s\n", d2);
	ASSERT(strlcat(d1, s1, sizeof(d1)) == ft_strlcat(d2, s2, sizeof(d2)), "strlcat()");

}
void	t_atoi(void){

	//printf("%d\n", atoi("45"));
	//printf("%d\n", ft_atoi("45"));
	ASSERT(atoi("45") == ft_atoi("45"), "atoi()");

}




void	t_memcpy(void){
	char	str1[21] = "a shiny white sphere";
	char	str2[21] = "a shiny white sphere";

	memcpy(str1+8, str1+2, 12);
	ft_memcpy(str2+8, str2+2, 12);
	printf("%s\n", str1);
	printf("%s\n", str2);
	ASSERT(!strcmp(str1, str2), "memcpy()");
}
void	t_memmove(void){
	char	str1[21] = "a shiny white sphere";
	char	str2[21] = "a shiny white sphere";

	memmove(str1+8, str1+2, 12);
	ft_memmove(str2+8, str2+2, 12);
	printf("%s\n", str1);
	printf("%s\n", str2);
	ASSERT(!strcmp(str1, str2), "memmove()");
}
 */

int	main(void)
{
	/*
t_memset();
t_bzero();
t_memcpy();
t_memmove();
t_strlcpy();
t_strlcat();
	t_toupper('c');
	t_tolower('C');
	t_strchr();
	t_strrchr();

	t_memcpy();
t_strncmp();
t_strnstr();
	t_atoi();

	*/
	t_isalpha();
	t_isdigit();
	t_isalnum();
	t_isascii();
	t_isprint();
	t_strlen();
	return (0);
}
