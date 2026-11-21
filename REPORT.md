# Assignment Report
## Design, Implement and Validate a Reliable Billing Program for a Rural Electricity Co-operative

**Student:** V. Hinduja  
**Register Number:** 1912260411  
**Course:** C Programming – CO1  
**Compiler:** GCC (version to be recorded from the system)  
**GitHub repository:** `https://github.com/<your-username>/CSA02-1912260411-Assignment1`

## Abstract
This assignment analyses a rural electricity billing system, selects appropriate C data types, implements slab tariffs using integer paise, validates meter rollover and input, and redesigns the application for smart-meter readings and time-of-day tariffs. The original tariff is a ₹50 fixed charge, first 100 units free, units 101–200 at ₹2.25 each, and units above 200 at ₹4.50 each.

## Design assumptions
- A conventional meter register is 16-bit and stores readings from 0 through 65535.
- One rollover between readings is possible; consumption is calculated modulo 65536.
- The rollover formula cannot detect multiple revolutions or a faulty reading by itself.
- Currency is stored as integer paise.
- For the smart-meter demonstration, each input is a watt-hour interval reading and the operator supplies tariff values in paise/kWh at runtime.
- The 35,040 readings/year assumption is 365 × 24 × 4.

## Bill formula
Let `u` be consumed units. Energy charge in paise:
- `0` for `u <= 100`;
- `(u - 100) × 225` for `100 < u <= 200`;
- `100 × 225 + (u - 200) × 450` for `u > 200`.
Add fixed charge `5000` paise.

| Units | Fixed charge | Energy charge | Total |
|---:|---:|---:|---:|
| 0 | ₹50.00 | ₹0.00 | ₹50.00 |
| 100 | ₹50.00 | ₹0.00 | ₹50.00 |
| 150 | ₹50.00 | ₹112.50 | ₹162.50 |
| 200 | ₹50.00 | ₹225.00 | ₹275.00 |
| 350 | ₹50.00 | ₹900.00 | ₹950.00 |

## Data types and scale
Use `uint16_t` for a meter register, `uint32_t` for units and household count, and `uint64_t` for paise totals. The actual sizes must be confirmed with `sizeof` and the compiler version recorded. Integer paise avoids binary floating-point representation and repeated rounding errors. At 800,000 households, aggregate totals should be calculated in 64-bit integer arithmetic and checked for overflow.

## Complexity
For a fixed number of tariff slabs, a single bill is O(1) time and O(1) extra space. For `n` meter readings, annual aggregation is O(n) time and O(1) accumulator space. Storing all interval readings instead would require O(n) memory. Parsing a text reading with `d` digits takes O(d) time and O(d) storage for a string buffer; arithmetic on a fixed-width integer is O(1).

## Macro safety
Function-like macros need parentheses around parameters and the full expression. `SQUARE(x)` must be `((x) * (x))`; even then, `SQUARE(i++)` is unsafe because the argument is evaluated twice. `MAX(a,b)` may also evaluate one argument more than once. Prefer a typed `static inline` function when suitable. `gcc -E` shows preprocessor expansion.

## Compilation process
1. `gcc -E file.c -o file.i` – preprocess.
2. `gcc -S file.c -o file.s` – compile to assembly.
3. `gcc -c file.c -o file.o` – assemble to object code.
4. `gcc file.o -o program` – link.
5. `gcc -Wall -Wextra -Wconversion -std=c11 file.c -o program` – build with useful warnings.

## Test plan
| Case | Input/condition | Expected result |
|---|---|---|
| Zero usage | 0 to 0 | 0 units, ₹50.00 |
| Slab boundary | 0 to 100 | 100 units, ₹50.00 |
| Second boundary | 0 to 200 | 200 units, ₹275.00 |
| Ordinary usage | 1200 to 1530 | 330 units, ₹860.00 |
| Rollover | 65400 to 120 | 256 units, ₹527.00 |
| Invalid text | letters instead of integer | Clear error; no bill |
| Out-of-range reading | greater than 65535 | Reject input |

The expected results above are calculated from the stated tariff. Actual results and screenshots must be captured after compiling and executing on the student's system.

## Task 12 – Day-4 Smart-meter challenge
The new meter reports watt-hours every 15 minutes (35,040 readings in a 365-day year). The design must accumulate yearly watt-hours, classify each interval as peak or off-peak, apply different rates, and permit tariff changes without recompilation. Compile-time `#define` tariff values are no longer appropriate for tariffs intended to be changed by an operator. The Task12 program reads tariff values at runtime and accumulates watt-hours and charges using 64-bit integer variables.

A robust production version should additionally load tariff configuration from a validated file or authenticated management interface, handle leap years/time-zone rules, use timestamps rather than a manually entered peak flag, log corrections, and check every multiplication/addition for overflow. The sample is an educational demonstration and not a production billing system.

## Final recommendation
Retain the simple slab formula but modify the implementation: use fixed-width integer types, integer paise, explicit input validation, a separate billing function, header guards, compiler warnings, and tests. For smart meters, redesign tariff handling around runtime configuration and time-stamped intervals. This is more reliable than merely widening the old variables because the requirements have changed, not just the size of the numbers.

## Evidence to add before submission
- Actual `gcc --version` output.
- Compilation and execution screenshots for every task.
- Exact commands and actual outputs.
- Measurements from the student's system for scale tests.
- UML/activity diagram and any required handwritten/teacher-provided format.
- Final GitHub URL, verified after pushing the repository.
