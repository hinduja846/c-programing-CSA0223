#include <stdio.h>
#include <stdint.h>
int main(void) {
    uint32_t household_id = 1001u;
    uint16_t previous = 1200u, current = 1530u;
    uint32_t units = (uint16_t)(current - previous);
    printf("Household: %u\nPrevious: %u\nCurrent: %u\nUnits consumed: %u\n",
           household_id, previous, current, units);
    return 0;
}
