/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:59:49 by acuadrad          #+#    #+#             */
/*   Updated: 2025/06/14 20:13:58 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_put_pointer(unsigned long p);
int	ft_putnbr(int nbr);
int	ft_put_unsigned_nbr(unsigned int nbr);
int	ft_put_hex(unsigned long nbr);
int	ft_put_mayus_hex(unsigned int nbr);

#endif
