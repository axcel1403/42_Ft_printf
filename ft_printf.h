/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:13:00 by jmiranda          #+#    #+#             */
/*   Updated: 2022/07/26 14:01:09 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define HEX_LO "0123456789abcdef"
# define HEX_HI "0123456789ABCDEF"

int	ft_printf(const char *fmt, ...);

#endif
