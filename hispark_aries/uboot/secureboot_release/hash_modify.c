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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i,j;
	char buffer[0x100];
	unsigned int buf[32];
	int *tmp = buf;
	FILE *fp1 = NULL;
	char *input_file = argv[1];

	printf("==================================================================================\n");
	if (argc != 2) {
		printf("input err!!!!!!!!!!!!!!!! \n");
		printf("usage: %s filename\n",argv[0]);
		exit(-1);
	}
	printf("input_file:%s\n",input_file);

	fp1 = fopen(input_file, "r");
	if (fp1 == NULL) {
		printf("open file failed!\n"); 
		return -1; 
	}

	sprintf(buffer,"cat %s",input_file);
	printf("%s\n",buffer);
	printf("==================================================================================\n");
	system(buffer);
	printf("==================================================================================\n");
	
	fscanf(fp1,"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
			tmp + 0, tmp + 1, tmp + 2, tmp + 3, tmp + 4, tmp + 5, tmp + 6, tmp + 7, tmp + 8, tmp + 9, tmp + 10, tmp + 11,
			tmp + 12, tmp + 13, tmp + 14, tmp + 15);
	tmp += 16;

	fscanf(fp1,"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
			tmp + 0, tmp + 1, tmp + 2, tmp + 3, tmp + 4, tmp + 5, tmp + 6, tmp + 7, tmp + 8, tmp + 9, tmp + 10, tmp + 11,
			tmp + 12, tmp + 13, tmp + 14, tmp + 15);
	printf("==================================================================================\n");
	printf("SHA256:\n");
	for (i = 0; i < 32; i++)
		printf("%02x", buf[i]);
	printf("\n");
	printf("==================================================================================\n");

	printf("==================================================================================\n");
	printf("REG VALUE:\n");
	for (i = 0; i < 8; i++) {
		for (j = 3; j >= 0; j--) {
			if (j == 3)
				printf("rootkey_hash[%0d]=mw 0x100900%02x 0x", i, (i * 4) + 0xc);
			printf("%02x", buf[i * 4 + j]);
			if (j == 0)
				printf("\n");
		}
	}
	printf("==================================================================================\n");
	
	fclose(fp1);
	return 0;
}

