/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:22:02 by dicanez           #+#    #+#             */
/*   Updated: 2019/01/27 11:15:27 by dicanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int				ft_atoi(char *str);

void			ft_putchar(char c);

void			ft_putnbr(int nb);

void			ft_putstr(char *str);

int				ft_strcmp(char *s1, char *s2);

char			*ft_strcpy(char *dest, char *src);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int				ft_strlen(char *str);

char			*ft_strncpy(char *dest, char *src, unsigned int n);

char			*ft_strstr(char *str, char *to_find);

void			ft_swap(int *a, int *b);

int				ft_is_num(char c);

int				ft_is_delimiter(char c);

#endif
