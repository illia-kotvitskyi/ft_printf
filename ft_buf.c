/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikotvits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:45:21 by ikotvits          #+#    #+#             */
/*   Updated: 2018/05/09 14:45:22 by ikotvits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_buf_add_numb(t_pf *s, unsigned char symbol)
{
	if (!symbol)
	{
		if (s->width > s->prec)
			s->i += s->width - s->prec;
		ft_strcpy(s->buf, (char *)N_STR);
		s->i += 6;
	}
	if (symbol)
		s->buf[s->i++] = symbol;
}

void	ft_buf_add_str(t_pf *s, unsigned char *str)
{
	if (!str)
	{
		if (s->width > s->prec && s->prec != 0)
			s->i += s->width - s->prec;
		str = (unsigned char *)N_STR;
	}
	while (str && *str && s->prec > 0)
	{
		if ((s->prec + s->i) > BUFF_SIZE)
			ft_buf_print(s);
		s->buf[s->i++] = *str++;
		s->prec--;
	}
}

void	ft_buf_print(t_pf *s)
{
	while (s->buf[s->i] != '\0')
		s->i++;
	s->sum += s->i;
	write(1, s->buf, s->i);
	s->i = 0;
	ft_bzero(s->buf, BUFF_SIZE);
}