#include "cycle.h"

Address findCycleEntryPoint(List l) {
    Address slow = FIRST(l);
    Address fast = FIRST(l);

    while (fast != NULL && NEXT(fast) != NULL) {
        slow = NEXT(slow);          
        fast = NEXT(NEXT(fast));   

        if (slow == fast) {
            Address start = FIRST(l);
            while (start != slow) {
                start = NEXT(start);
                slow = NEXT(slow);
            }
            return start;
        }
    }

    return NULL;
}
