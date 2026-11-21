#include <stdio.h>
#include "billing.h"

uint64_t compute_bill_paise(uint32_t units)
{
    uint64_t total = FIXED_CHARGE_PAISE;
    if (units > SLAB1_UNITS) {
        uint32_t n = units < SLAB2_UNITS ? units - SLAB1_UNITS : 100u;
        total += (uint64_t)n * RATE2_PAISE;
    }
    if (units > SLAB2_UNITS)
        total += (uint64_t)(units - SLAB2_UNITS) * RATE3_PAISE;
#ifdef DEBUG
    fprintf(stderr, "[DEBUG] units=%u total_paise=%llu\n",
            units, (unsigned long long)total);
#endif
    return total;
}
int main(void)
{
    printf("Bill for 250 units: Rs %llu.%02llu\n",
           (unsigned long long)(compute_bill_paise(250) / 100),
           (unsigned long long)(compute_bill_paise(250) % 100));
    return 0;
}
