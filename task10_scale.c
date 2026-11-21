#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

static uint64_t bill_paise(uint32_t units)
{
    uint64_t p = 5000u;
    if (units > 100u) {
        uint32_t n = units < 200u ? units - 100u : 100u;
        p += (uint64_t)n * 225u;
    }
    if (units > 200u) p += (uint64_t)(units - 200u) * 450u;
    return p;
}
int main(void)
{
    const uint64_t counts[] = {4000u, 60000u, 800000u};
    const uint32_t units_each = 250u;
    for (size_t i = 0; i < sizeof counts / sizeof counts[0]; ++i) {
        uint64_t total = counts[i] * bill_paise(units_each);
        printf("%" PRIu64 " bills: total = Rs %" PRIu64 ".%02" PRIu64 "\n",
               counts[i], total / 100u, total % 100u);
    }
    return 0;
}
