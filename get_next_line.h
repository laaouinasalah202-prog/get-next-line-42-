/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-08 20:19:52 by slaaouin          #+#    #+#             */
/*   Updated: 2025-11-08 20:19:52 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

int	ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char *get_next_line(int fd);

#endif
