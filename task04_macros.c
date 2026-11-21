#include <stdio.h>
#define RUPEES_TO_PAISE(r) ((long long)(r) * 100LL)
#define SQUARE(x) ((x) * (x))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

static inline long long square_ll(long long x) { return x * x; }
int main(void)
{
    printf("Rs 50 in paise = %lld\n", RUPEES_TO_PAISE(50));
    printf("SQUARE(1+2) = %d\n", SQUARE(1 + 2));
    printf("MAX(4,7) = %d\n", MAX(4, 7));
    printf("inline square(3) = %lld\n", square_ll(3));
    return 0;
}
