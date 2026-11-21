#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    unsigned int units = 150;
    /* Surprise 1: integer division truncates. */
    printf("150 / 100 as integer = %u\n", units / 100);
    /* Surprise 2: cast before division preserves a fraction. */
    printf("150 / 100 as double = %.2f\n", (double)units / 100.0);
    /* Surprise 3: integer paise prints exact currency. */
    uint64_t paise = 5000u + 50u * 225u;
    printf("Exact charge = Rs %" PRIu64 ".%02" PRIu64 "\n",
           paise / 100u, paise % 100u);
    return 0;
}
