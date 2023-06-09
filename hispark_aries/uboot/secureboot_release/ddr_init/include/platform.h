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

#ifndef __HI_CHIP_REGS_H__
#define __HI_CHIP_REGS_H__

//#define CONFIG_DDR_TRAINING_V2

#define BIT(nr)			(1 << (nr))

#define RAM_START_ADRS			0x04010500
#define STACK_TRAINING			0x04018000

#define DDR_DDRT_REG_BASE		0x11330000
#define TIMER0_REG_BASE			0x12000000
#define TIMER1_REG_BASE			0x12000020
#define TIMER2_REG_BASE			0x12001000
#define TIMER3_REG_BASE			0x12001020
#define REG_TIMER_RELOAD		0x0
#define REG_TIMER_VALUE			0x4
#define REG_TIMER_CONTROL		0x8

#define CRG_REG_BASE			0x12010000

#define SYS_CTRL_REG_BASE		0x12020000
#define REG_BASE_SCTL			SYS_CTRL_REG_BASE
#define REG_SC_CTRL				0
#define REMAPCLEAR				BIT(8)
#define REMAPCLEAR_SHIFT		8
#define TIME0_CLK_SEL			BIT(16)
#define TIME0_CLK_SEL_SHIFT		16
#define TIME0_CLK_SEL_3M		0x0
#define TIME0_CLK_SEL_APB		0x1

#define REG_SC_SYSRES		0x4
#define REG_SYSSTAT			0x008C
#define REG_SC_GEN0			0x0138
#define REG_SC_GEN1			0x013c
#define REG_SC_GEN2			0x0140
#define REG_SC_GEN3			0x0144
#define REG_SC_GEN4			0x0148
#define REG_SC_GEN5			0x014c
#define REG_SC_GEN7			0x0154

#define MISC_REG_BASE			0x12028000
#define DDRC0_REG_BASE			0x11330000
#define UART0_REG_BASE			0x12040000
#define FMC_MEM_BASE			0x14000000
#define DDR_MEM_BASE			0x40000000

#define _HI3516EV200			(0x003516e200LL)
#define _HI3516EV200_MASK		(0xFFFFFFFFFFLL)
#endif /* End of __HI_CHIP_REGS_H__ */
