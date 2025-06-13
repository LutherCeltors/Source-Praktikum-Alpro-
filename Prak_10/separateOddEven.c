#include "listlinier.h"
#include "stdio.h"

#include "listlinier.h"
#include <stdio.h>

void separateOddEven(List *l)
{
    Address p = FIRST(*l);
    Address odd_head = NULL, odd_tail = NULL;
    Address even_head = NULL, even_tail = NULL;

    while (p != NULL) {
        Address next = NEXT(p);
        NEXT(p) = NULL; 

        if (INFO(p) % 2 == 1) { 
            if (odd_head == NULL) {
                odd_head = p;
                odd_tail = p;
            } else {
                NEXT(odd_tail) = p;
                odd_tail = p;
            }
        } else {
            if (even_head == NULL) {
                even_head = p;
                even_tail = p;
            } else {
                NEXT(even_tail) = p;
                even_tail = p;
            }
        }

        p = next;
    }

    if (odd_tail != NULL) {
        NEXT(odd_tail) = even_head;
        FIRST(*l) = odd_head;
    } else {
        FIRST(*l) = even_head;
    }
}
