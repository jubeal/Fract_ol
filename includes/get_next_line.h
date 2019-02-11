/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:12:22 by jubeal            #+#    #+#             */
/*   Updated: 2019/02/08 12:24:18 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define BUFF_SIZE 2048

typedef struct			s_list_fd
{
	char				*rest;
	int					fd;
	struct s_list_fd	*next;
}						t_list_fd;

int						get_next_line(const int fd, char **line);
#endif
