/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:04:47 by akalican          #+#    #+#             */
/*   Updated: 2024/05/06 12:30:38 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./error.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int error(int code)
{
    if (code == bad_args)
    {
        write(1,"bad args\n",9);
    }
    exit(-1);
}