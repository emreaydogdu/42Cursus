/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:18:58 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/10 12:34:38 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
# include <dlfcn.h>

int leakNMBR = 0;

#ifdef __APPLE__
void * malloc(size_t size)
#endif
#ifdef __unix__
void * malloc(size_t size) throw()
#endif
{
	void *(*libc_malloc)(size_t) = (void *(*)(size_t))dlsym(RTLD_NEXT, "malloc");
	void * p = libc_malloc(size);
	leakNMBR++;
	return (p);
}

#ifdef __APPLE__
void free(void * p)
#endif
#ifdef __unix__
void free(void * p) throw()
#endif
{
	void (*libc_free)(void*) = (void (*)(void *))dlsym(RTLD_NEXT, "free");
	libc_free(p);
	leakNMBR--;
}

void	t_fail(void);
void	t_succ(void);

#define ASSERT(succes) if (!(succes)) t_fail(); else t_succ();

void	t_fail(void)
{
	printf("%sKO%s  ", "\033[1m\x1B[31m", "\x1B[0m");
}

void	t_succ(void)
{
	printf("%sOK%s  ", "\033[1m\033[32m", "\x1B[0m");
}

void	t_leak(void)
{
	//printf(" #LEAKNMBR: %d  # ", leakNMBR);
	if (leakNMBR != 0)
		printf("%sL.KO%s  ", "\033[1m\x1B[31m", "\x1B[0m");
	else
		printf("%sL.OK%s  ", "\033[1m\033[32m", "\x1B[0m");
	leakNMBR = 0;
}

