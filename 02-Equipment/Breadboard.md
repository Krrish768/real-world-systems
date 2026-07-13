# Breadboard

## What It Is

A breadboard is a reusable board used to build circuits without soldering. Components and wires are pushed into holes, which are internally connected in specific patterns to form electrical paths.

## Where and When It Is Used

Used for prototyping — testing a circuit quickly before making it permanent. Every project in this repo uses one to connect the Arduino to components like LEDs, resistors, and push buttons.

## Internal Structure

A breadboard is divided into two types of connected regions:

### 1. Terminal Strips (Main Middle Section)

- The board has a center gap dividing it into a left half and a right half.
- On each half, holes are grouped into short vertical columns (typically 5 holes per column).
- **All 5 holes in one column are internally connected to each other**, but not connected to the next column.
- The center gap breaks the connection between the left and right halves — this is intentionally used to place ICs or separate two independent sections of a circuit.

### 2. Power Rails (Top and Bottom Strips)

- Usually marked with a red line (+) and a blue/black line (−), running horizontally along the top and/or bottom edges.
- All holes along the **red (+) rail** are internally connected to each other across the entire length of the board.
- All holes along the **blue/black (−) rail** are internally connected to each other in the same way.
- These are meant to distribute power (+5V) and ground (GND) to multiple components without wiring each one directly back to the Arduino.

## How Components Get Connected

When you place a component's leg into a hole, it becomes electrically connected to every other hole in that same column (terminal strip) or that same rail (power strip). This is how a resistor in one hole can "reach" an LED placed a few holes away in the same column — they're joined internally by a metal strip under the plastic.

## Common Notes

- Always double-check which column/row a component's leg lands in — placing two unrelated legs in the same column accidentally connects them.
- The center gap is a common mistake point — components placed straight across it are NOT connected to each other on the two sides.