#include "listlinier.h"
#include <stdio.h>

void removeAll(List *l, ElType val) {
    Address p = *l;
    Address prev = NULL;

    while (p != NULL) {
        if (INFO(p) == val) {
            Address temp = p;
            if (prev == NULL) {
                *l = NEXT(p);
                p = *l;
            } else {
                NEXT(prev) = NEXT(p);
                p = NEXT(p);
            }
        } else {
            prev = p;
            p = NEXT(p);
        }
    }
}
