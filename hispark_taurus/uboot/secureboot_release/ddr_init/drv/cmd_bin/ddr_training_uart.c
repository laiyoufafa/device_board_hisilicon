/*
 * Copyright (C) 2021 HiSilicon (Shanghai) Technologies CO., LIMITED.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "ddr_training_custom.h"

#define UART_PL01x_DR				   0x00	 /*  Data read or written from the interface. */
#define UART_PL01x_FR				   0x18	 /*  Flag register (Read only). */
#define UART_PL01x_FR_TXFF			  0x20

#define IO_WRITE(addr, val) (*(volatile unsigned int *)(addr) = (val))
#define IO_READ(addr) (*(volatile unsigned int *)(addr))

void uart_early_putc(const char c)
{
	/* Wait until there is space in the FIFO */
	while (IO_READ (DDR_REG_BASE_UART0 + UART_PL01x_FR) & UART_PL01x_FR_TXFF);

	/* Send the character */
	IO_WRITE (DDR_REG_BASE_UART0 + UART_PL01x_DR, c);
}

void uart_early_puts(const char *s)
{
	if (s == NULL)
		return;
	while (*s)
		uart_early_putc (*s++);
}

void uart_early_put_hex(const unsigned int hex)
{
	int i;
	char c;

	for (i = 28; i >= 0; i -= 4) {
		c = (hex >> (unsigned int)i) & 0x0F;
		if (c < 10)
			c += '0';
		else
			c += 'A' - 10;
		uart_early_putc(c);
	}
}
