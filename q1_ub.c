/* Q1 Inquiry: count = count++ + 1;  (undefined behaviour - unsequenced modification) */
#include <stdio.h>
int main(void)
{
    int count = 5;
    count = count++ + 1;      /* count is modified twice with no sequence point */
    printf("count = %d\n", count);
    return 0;
}
