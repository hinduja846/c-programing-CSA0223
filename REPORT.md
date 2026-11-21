# C Programming Assignment 3 – CO3
## Student B Individual Report

**Student name:** V. Hinduja  
**Register number:** 1912260411  
**Course code:** CSA02  
**Course:** C Programming  
**Compiler:** GCC – exact version to be filled after running `gcc --version`  
**GitHub repository:** Add the working repository URL here

## Scope and contribution
This report documents the Student B primary responsibilities in Q1–Q7, with the shared implementations needed to execute and validate each question. The source assignment is pair-work in its original PDF; this submission is organised as requested into Student B sections only. The source PDF also states that every student must understand and execute every question, so the student should be prepared to explain all submitted code.

## Q1 – Searching a Library Catalogue (Student B: Experimental Investigation)
The program compares linear and binary search for 1,000, 10,000 and 100,000 accession numbers. It records successful and unsuccessful comparison counts as CSV. Linear search is O(n); binary search is O(log n) and requires sorted input. For 100,000 entries, binary search needs roughly 17 iterations in the worst case, while linear search may inspect all 100,000 elements. Run the program and preserve its CSV output as experimental evidence. Binary search is worthwhile when frequent searches justify maintaining sorted order; update frequency and insertion cost must be considered.

## Q2 – Sorting the Examination Hall Seating Register (Student B: Comparative Measurement)
The implementation measures comparisons, swaps and shifts for bubble, selection and insertion sort over sorted, nearly sorted, reverse and random data at n=100, 1,000 and 10,000. The program prints a CSV suitable for graphs. Insertion sort is recommended for a list that is sorted except for a small number of late entries because it is adaptive and typically performs close to linear work when disorder is limited. Selection sort retains quadratic comparisons even for sorted input. Bubble sort benefits from its early-exit flag on already sorted data. Bubble and insertion are stable in the supplied forms; selection sort is generally unstable.

## Q3 – Merging Two Merit Lists (Student B: Merge Design and Correctness)
The merge program combines descending arrays in O(m+n) time using a third array. At each step, it compares the current unconsumed scores and emits the larger. Each comparison consumes one element, so there are at most m+n-1 comparisons when both arrays are nonempty. Remaining elements are copied after one list ends. The `>=` condition preserves campus A before campus B for equal scores. Extra output storage is O(m+n). Concatenate-and-qsort is O((m+n)log(m+n)); a simple in-place merge can require O(m*n) shifts.

## Q4 – Two-Dimensional Arrays: District Rainfall Records (Student B: Implementation and Verification)
Four separate functions compute row totals, column averages, maximum rainfall and deficient rows. The 3×4 test matrix is:
```
10 20 30 40
 5 10 15 20
50 60 70 80
```
Expected row totals: 100, 50, 260. Column averages: 21.67, 30.00, 38.33, 46.67. Overall average: 34.17. Maximum: 80 at row 2, column 3. Deficient row: index 1. The benchmark compares row-wise and column-wise traversal of a 2,000×2,000 array. Row-wise traversal is expected to be faster because C stores 2-D arrays in row-major order and adjacent elements are contiguous. Insert actual measured times from your computer.

## Q5 – Processing Text Without the Library (Student B: Library Functions and Safety)
The implementation demonstrates word counting, palindrome checking, upper-case conversion, reversal and bounded copying. `strcpy` is unsafe if the destination is too small because it does not check capacity. `snprintf` limits output to the destination size; `fgets` is preferred for bounded input. `gets` was removed because it cannot prevent buffer overflow. The custom word counter handles spaces, tabs, newlines and carriage returns. Loop-based processing is O(n); repeatedly calling `strlen` in a loop condition can make the total O(n²). Recursive reversal uses O(n) stack space; iterative reversal uses O(1).

## Q6 – A Directory of Names: Sorting and Searching Strings (Student B: Design and Correctness)
`strcmp` compares character codes and is case-sensitive, so differently capitalised names can have different sort positions. Case-insensitive comparison can compare `tolower((unsigned char)c)` values. The program reads names with `fgets`, removes the newline, sorts names, detects adjacent duplicates and searches with binary search. The fixed-width storage supports 30 visible characters plus the null terminator; longer input is truncated. Sorting pointers or indices reduces swap work from copying O(L) characters to O(1) pointer/index movement, at the cost of O(n) extra storage and indirection.

## Q7 – Election Counting Program (Student B: Implementation and Measurement)
The program validates candidate IDs, counts valid and invalid votes, sorts candidate totals descending, identifies the winner and detects a tie. The sample input has 3 candidates and 8 votes: `1 2 2 3 0 -1 4 1`. Expected valid votes=6, invalid votes=2; candidate 1=2, candidate 2=2, candidate 3=1; candidates 1 and 2 tie. Counting is O(v), and selection-sorting candidate totals is O(c²), giving O(v+c²) overall. The program supports 500,000 votes for the required large experiment. Run it with generated 5,000- and 500,000-vote input files and record the displayed time.

## Experimental evidence to complete on the student's computer
| Question | Evidence to save |
|---|---|
| Q1 | CSV comparisons for all three sizes and successful/unsuccessful searches |
| Q2 | `results.csv`; graphs of comparisons and movements by algorithm/input order |
| Q4 | Actual row-wise and column-wise traversal times |
| Q6 | Test names including 29-, 30- and over-30-character cases; present/missing searches |
| Q7 | Timing runs for 5,000 and 500,000 votes; small hand-checked test |

Do not invent timing measurements or screenshots. Run the programs on the target laptop/compiler and paste the actual results into this report. Add one screenshot per question showing successful compilation and execution.

## Final recommendation
Use binary search for frequently queried sorted numeric data, insertion sort for nearly sorted registers, linear merge for already sorted merit lists, row-major 2-D arrays with row-wise traversal, bounded string input/copy functions, and a count array for election totals. These choices reduce unnecessary work while keeping the implementation understandable and testable.
