#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool print(const char* data, size_t len) {
    const unsigned char* bytes = (const unsigned char*) data;
    for (size_t i = 0; i < len; i++) {
        if (putchar(bytes[i]) == EOF) {
            return false;
        }
    }
    return true;
}

int printf(const char* restrict format, ...) {
    va_list parameters;
    va_start(parameters, format);

    int written = 0;

    while (*format != '\0') { // print as long as we are not at the end of what should be printed
        if (format[0] != '%') {
            // plain text, we can just print
            print(format, 1);
            format++;
            written++;
            continue;
        }
        format++; // skip the %
        
        switch (*format) {
            case 'c': { // char specifier
                format++;
                char c = (char) va_arg(parameters, int); // read as int and cast to char because C promotes char to int when passing through ...
                print(&c, 1);
                written++;
                break;
            }
            case 's': { // string specifier
                format++;
                const char* str = va_arg(parameters, const char*);
                size_t len = strlen(str);
                print(str, len);
                written += len;
                break;
            }
            case 'd': { // integer specifier
                format++;
                int value = va_arg(parameters, int);
                if (value < 0) {
                    print("-", 1);
                    written++;
                    value = -value;
                }
                char buf[32];
                int i = 0;
                if (value == 0) {
                    buf[i++] = '0';
                } else {
                    while (value > 0) {
                        buf[i++] = '0' + (value % 10);
                        value /= 10;
                    }
                }

                for (int j = i - 1; j >= 0; j--) {
                    print(&buf[j], 1);
                    written++;
                }
                break;
            }
            case 'x': {
                format++;
                unsigned int value = va_arg(parameters, unsigned int);
                char digits[] = "0123456789abcdef";
                char buf[32];
                int i = 0;
                if (value == 0) {
                    buf[i++] = '0';
                } else {
                    while (value > 0) {
                        buf[i++] = digits[value % 16];
                        value /= 16;
                    }
                }

                for (int j = i-1; j >= 0; j--) {
                    print(&buf[j], 1);
                    written++;
                }
                break;
            }
            case '%': {
                format++;
                print("%", 1);
                written++;
                break;
            }
            default: {
                format--;
                print(format, 2);
                format += 2;
                written += 2;
                break;
            }
        }
    }

    va_end(parameters);
    return written;
}
