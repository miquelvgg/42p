/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvives-s <mvives-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:51:09 by mvives-s          #+#    #+#             */
/*   Updated: 2024/10/17 13:52:19 by mvives-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h> 

int		ft_print_string(char *str);
int		ft_print_pointer(void *ptr);
int		ft_print_decimal(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, char spec);
int		ft_print_percent(void);
char	*ft_utoa(unsigned int n);
char	*ft_itoa_base(unsigned long n, int base);
void	ft_strtoupper(char *str);
int		ft_islower(int c);
int		ft_printf(char const *format, ...);
#endif
