#include "stdio.h"

int printf(const char *formato, ...) {
    return (int) * formato++;
}
