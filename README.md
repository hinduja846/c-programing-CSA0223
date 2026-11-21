# CSA02-1912260411-Assignment2

- Student name: V. Hinduja
- Register number: 1912260411
- Course: CSA02 C Programming - Assignment 2 (CO2): operators, decision making and loops
- Compiler and version: gcc (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0
- Compile flags used everywhere: `-Wall -Wextra -std=c11 -O0` (add `-lm` for Q1 and Q6)

## Folders

| Folder | Task | Marks |
|---|---|---|
| Q1 | Precedence, Associativity and the Discount Bug | 6 |
| Q2 | When Does Short-Circuit Evaluation Matter? | 4 |
| Q3 | Device-Status Register with Bitwise Operators | 6 |
| Q4 | else-if Ladder or switch? | 6 |
| Q5 | Count the Work Done by a Loop (Prime Checking) | 7 |
| Q6 | Loops That Must Terminate: Loan Repayment Schedule | 8 |
| Q7 | Day-4 Design Challenge: Diagnose, Redesign and Validate | 13 |

Each folder contains the C source, captured outputs, `screenshots/`, a `README.md` (exact compile command, run steps, result note) and `observations.md` (predictions, counts, complexity analysis).

## Result of each question

- **Q1** - All 4 hand predictions matched the program. The original expression is wrong because GST is charged on the undiscounted amount and integer division drops paise (errors +4.50, +1.83, +11.25, -0.75). Corrected with intermediate variables and brackets. count = count++ + 1 is undefined behaviour (gcc -Wall warns).
- **Q2** - Short-circuit && / || skipped the right operand exactly when the left decided the result; & and | never skip. Slow-call counts for 1,000 passengers: 902 (short-circuit, cheap first), 1000 (slow first, or & |); 210 vs 1000 when the slow call sits inside an &&. Audit log changes the recommendation.
- **Q3** - TODO 1-4 completed with only bitwise operators; output matches the expected 00000101 / 00000110 / AC is ON, PUMP is OFF. All 9 predicted register values matched. Precedence and signed char pitfalls demonstrated. 1 byte vs 8 bytes per home.
- **Q4** - Ladder, switch and lookup table agree on all 15 boundary tests and the 141-value sweep; the unguarded switch is wrong for 40 values. Removing a return/case changes 100:S 95:S to 100:A 95:A etc. Scholarship rule implemented with a 6x4 table and checked against nested if on 909 combinations.
- **Q5** - Complete-the-code output matches exactly (8, 1, 87, 999 divisions). Naive loop needs 1,000,001 divisions for 1,000,003; improved loop 999. do-while fails for n=2 without a guard; i*i wraps at i=65536 for 32-bit values.
- **Q6** - Loan of Rs 10,000 at 2% with Rs 2,000 repayments clears in 6 months, total interest Rs 645.38, matching the hand schedule. Loop uses while (balance > 0.005) with a 360-month safety limit; repayment <= interest is reported instead of looping forever.
- **Q7** - Redesigned the Q5 prime checker. Predictions held exactly. Total divisions for tickets 0..1,000,003: 67,741,504 (original) -> 23,713,457 (wheel, -65.0%) -> 13,927,597 (prime table, -79.4%), zero wrong answers, 672 bytes extra memory.

## Running a program

```
cd Q5
gcc -Wall -Wextra -std=c11 -O0 -o q5_analysis q5_analysis.c
./q5_analysis
```
