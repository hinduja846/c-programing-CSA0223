#include <stdio.h>
#ifndef MUT
#define MUT 0
#endif
/* MUT=0 original, MUT=1 'return' removed from case 9, MUT=2 'return' removed from case 8,
   MUT=3 'case 10:' label removed, MUT=4 'return' removed from case 5 (D falls into default) */
char grade(int marks)
{
    if (marks < 0 || marks > 100) return '?';
    switch (marks / 10) {
#if MUT != 3
        case 10:
#endif
        case 9:
#if MUT == 1
            'S';
#else
            return 'S';
#endif
        case 8:
#if MUT == 2
            'A';
#else
            return 'A';
#endif
        case 7:  return 'B';
        case 6:  return 'C';
        case 5:
#if MUT == 4
            'D';
#else
            return 'D';
#endif
        default: return 'F';
    }
}
int main(void)
{
    int marks[] = {100, 95, 83, 50, 49, -5};
    for (int i = 0; i < 6; i++) printf("%d:%c ", marks[i], grade(marks[i]));
    printf("\n");
    return 0;
}
