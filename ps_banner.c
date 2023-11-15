/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_banner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:05:26 by misargsy          #+#    #+#             */
/*   Updated: 2023/10/31 01:28:07 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ps_frame(void)
{
	write(1, "\x1b[32m", 5);
	write(1, "####################################", 35);
	write(1, "##############################################\n", 47);
	write(1, "\x1b[0m", 4);
}

static void	ps_banner(void)
{
	write(1, "\x1b[33m", 5);
	write(1, "                        __         ", 35);
	write(1, "                                              \n", 47);
	write(1, "                       /\\ \\        ", 35);
	write(1, "                                              \n", 47);
	write(1, " _____   __  __    ____\\ \\ \\___    ", 35);
	write(1, "          ____  __  __  __     __     _____   \n", 47);
	write(1, "/\\ '__`\\/\\ \\/\\ \\  /',__\\\\ \\  _ `\\  ", 35);
	write(1, "         /',__\\/\\ \\/\\ \\/\\ \\  /'__`\\  /\\ '__`\\ \n", 47);
	write(1, "\\ \\ \\L\\ \\ \\ \\_\\ \\/\\__, `\\\\ \\ \\ \\ \\ ", 35);
	write(1, "        /\\__, `\\ \\ \\_/ \\_/ \\/\\ \\L\\.\\_\\ \\ \\L\\ \\\n", 47);
	write(1, " \\ \\ ,__/\\ \\____/\\/\\____/ \\ \\_\\ \\_\\", 35);
	write(1, "        \\/\\____/\\ \\___x___/'\\ \\__/.\\_\\\\ \\ ,__/\n", 47);
	write(1, "  \\ \\ \\/  \\/___/  \\/___/   \\/_/\\/_/", 35);
	write(1, "  _______\\/___/  \\/__//__/   \\/__/\\/_/ \\ \\ \\/ \n", 47);
	write(1, "   \\ \\_\\                           ", 35);
	write(1, " /\\______\\                              \\ \\_\\ \n", 47);
	write(1, "    \\/_/                           ", 35);
	write(1, " \\/______/                               \\/_/ \n\n", 48);
	write(1, "\x1b[0m", 4);
}

static void	ps_usage(void)
{
	write(1, "Usage:	   ./push_swap <numbers>\n", 32);
	write(1, "	   ./push_swap <numbers> | ./checker <numbers>\n", 49);
	write(1, "	   ARG=\"<numbers>\"; ./push_swap $ARG | ./checker $ARG\n", 56);
	write(1, "	   ARG=\"<numbers>\"; ./push_swap $ARG | wc -l\n\n", 48);
	write(1, "	   Numbers out of range of int will result in error.\n", 55);
	write(1, "	   No duplicate numbers are allowed.\n", 39);
}

int	main(void)
{
	ps_frame();
	ps_banner();
	ps_frame();
	ps_usage();
	return (0);
}
