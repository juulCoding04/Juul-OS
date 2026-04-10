#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

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
        }
    }

    va_end(parameters);
    return written;
}
