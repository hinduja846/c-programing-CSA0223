# CSA02 C Programming – Assignment 3 (Student B)

**Student:** V. Hinduja  
**Register number:** 1912260411  
**Course:** CSA02 – C Programming, CO3  
**Compiler:** GCC (record the exact installed version using `gcc --version`)

## Scope
This repository contains the Student B primary-responsibility sections for Q1–Q7, together with the shared executable code required to demonstrate those sections. It does not claim to contain Student A's separately assigned primary write-ups.

## Folder contents
- `Q1/` – searching experiment and comparison-count program
- `Q2/` – three sorting algorithms and measurement generator
- `Q3/` – descending merge implementation and correctness analysis
- `Q4/` – rainfall computations and row/column traversal benchmark
- `Q5/` – string-library comparison and safe string handling
- `Q6/` – name sorting, duplicate detection and binary search
- `Q7/` – election counting, validation, sorting and tie detection
- `REPORT.md` – consolidated Student B report

## Compile and run
Run each command from its question folder:
- Q1: `gcc -std=c11 -O2 main.c -o q1` then `./q1`
- Q2: `gcc -std=c11 -O2 main.c -o q2` then `./q2 > results.csv`
- Q3: `gcc -std=c11 -O2 main.c -o q3` then `./q3`
- Q4: `gcc -std=c11 -O2 main.c -o q4` then `./q4`; benchmark: `gcc -std=c11 -O2 benchmark.c -o benchmark` then `./benchmark`
- Q5: `gcc -std=c11 -O2 main.c -o q5` then `./q5`
- Q6: `gcc -std=c11 -O2 main.c -o q6` then `./q6`
- Q7: `gcc -std=c11 -O2 main.c -o q7` then `./q7 < sample_input.txt`

## Submission checklist
1. Run `gcc --version` and record the actual version in the report.
2. Execute each program on your own computer and capture terminal screenshots.
3. Save Q1/Q2 CSV measurements and Q4 benchmark timings from your computer.
4. Add the screenshots and measured results to the relevant question folders.
5. Create the GitHub repository `CSA02-1912260411-Assignment3`, upload folders, and commit progressively (at least one commit per question).
6. Add the working repository URL to the report cover page and share it with the faculty.
