#pragma once

#define COM1 0x3F8

int serial_init(void);
void serial_putchar(char c);
void serial_write(char* str);
