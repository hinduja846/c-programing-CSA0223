#include <stdio.h>
#include <stdint.h>

int main(void)
{
    unsigned int previous, current;
    printf("Enter previous and current readings (0..65535): ");
    if (scanf("%u %u", &previous, &current) != 2) {
        fprintf(stderr, "Error: enter two integer readings.\\n");
        return 1;
    }
    if (previous > 65535u || current > 65535u) {
        fprintf(stderr, "Error: readings must be in the range 0..65535.\\n");
        return 1;
    }
    uint32_t units = (uint16_t)((uint16_t)current - (uint16_t)previous);
    uint64_t paise = 5000u;
    if (units > 100u) {
        uint32_t n = units < 200u ? units - 100u : 100u;
        paise += (uint64_t)n * 225u;
    }
    if (units > 200u) paise += (uint64_t)(units - 200u) * 450u;
    printf("Units consumed: %u\\nBill: Rs %llu.%02llu\\n", units,
           (unsigned long long)(paise / 100u),
           (unsigned long long)(paise % 100u));
    return 0;
}
