#include <stdio.h>
#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE1_PAISE 0
#define RATE2_PAISE 225
#define RATE3_PAISE 450
#define FIXED_CHARGE_PAISE 5000

/* Returns bill in paise. */
long long compute_bill(unsigned int units)
{
    long long paise = FIXED_CHARGE_PAISE;
    if (units > SLAB1_UNITS) {
        unsigned int slab2 = units < SLAB2_UNITS ? units - SLAB1_UNITS
                                                 : SLAB2_UNITS - SLAB1_UNITS;
        paise += (long long)slab2 * RATE2_PAISE;
    }
    if (units > SLAB2_UNITS)
        paise += (long long)(units - SLAB2_UNITS) * RATE3_PAISE;
    return paise;
}
int main(void)
{
    unsigned int tests[] = {0, 100, 150, 200, 350};
    for (size_t i = 0; i < sizeof tests / sizeof tests[0]; ++i) {
        long long p = compute_bill(tests[i]);
        printf("%3u units -> Rs %lld.%02lld\n", tests[i], p / 100, p % 100);
    }
    return 0;
}
