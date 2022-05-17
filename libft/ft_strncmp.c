/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:05:30 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/08 06:02:46 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(char *s1, char *s2, int n)
{
	unsigned char	u_s1;
	unsigned char	u_s2;

	while (n-- > 0)
	{
		u_s1 = (unsigned char)*s1;
		u_s2 = (unsigned char)*s2;
		if (u_s1 > u_s2 || u_s1 < u_s2)
			return (0);
		else if (u_s1 == '\0' && u_s2 == '\0')
			return (1);
		s1++;
		s2++;
	}
	return (1);
}
