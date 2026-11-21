#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define METER_MAX 65535u
#define FIXED_PAISE 5000u
#define RATE2_PAISE 225u
#define RATE3_PAISE 450u

static uint32_t usage(uint32_t previous, uint32_t current)
{
    return (uint16_t)((uint16_t)current - (uint16_t)previous);
}
static uint64_t bill_paise(uint32_t units)
{
    uint64_t total = FIXED_PAISE;
    if (units > 100u) {
        uint32_t n = units < 200u ? units - 100u : 100u;
        total += (uint64_t)n * RATE2_PAISE;
    }
    if (units > 200u) total += (uint64_t)(units - 200u) * RATE3_PAISE;
    return total;
}
static void print_bill(uint32_t previous, uint32_t current)
{
    uint32_t units = usage(previous, current);
    uint64_t p = bill_paise(units);
    printf("%5u -> %5u : %u units, Rs %" PRIu64 ".%02" PRIu64 "\n",
           previous, current, units, p / 100u, p % 100u);
}
int main(void)
{
    puts("Boundary and rollover tests:");
    print_bill(0, 0);
    print_bill(0, 100);
    print_bill(0, 200);
    print_bill(1200, 1530);
    print_bill(65400, 120);
    return 0;
}
