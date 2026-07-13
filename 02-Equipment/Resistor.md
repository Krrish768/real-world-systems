# Resistor

## What It Is

A resistor is a passive component that opposes (resists) the flow of electric current. It's used to control how much current flows through a part of a circuit.

## Where and When It Is Used

Used almost everywhere — to protect components like LEDs from excess current, to create pull-up/pull-down configurations for input pins, and to control voltage/current levels in a circuit.

## Structure and Pins

A resistor has two legs, and it is **not polarized** — it works the same no matter which way around you connect it. There is no "correct direction" like an LED.

## Internal Working

Inside a resistor is a material (often a carbon film or metal film) that has natural opposition to electron flow — free electrons moving through it collide with the material's structure, losing energy as heat. This opposition is what limits current, following Ohm's Law (V = IR).

## Reading Resistor Values (Color Coding)

Resistors use colored bands printed on the body to indicate their resistance value, since the number is too small to print directly.

A standard 4-band resistor works like this:

- **Band 1:** First digit
- **Band 2:** Second digit
- **Band 3:** Multiplier (how many zeros to add)
- **Band 4:** Tolerance (accuracy, usually gold = ±5%)

Example: A resistor commonly used with LEDs has bands **Red - Red - Brown - Gold**, which reads as 2, 2, ×10 → 220Ω, ±5% tolerance.

## Common Values Used in This Project

- 220Ω — current limiting for LEDs at 5V
- 10kΩ — commonly used for external pull-down/pull-up configurations

## Common Notes

- Resistors don't "use up" current — the same current that enters one leg exits the other. It converts electrical energy into heat, not consuming charge.