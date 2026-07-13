# Push Button

## What It Is

A push button is a simple mechanical switch. It only does one job — open or close a connection when pressed. It doesn't generate or consume electricity; it just controls whether current *can* flow through a path.

## Where and When It Is Used

Used to give digital input to a microcontroller — letting the user trigger an action (turn something on, change a mode, start a sequence).

## Structure and Pins

Most push buttons used in breadboard projects have **4 legs**, but only **2 independent electrical connections** exist inside — the 4 legs are just there for stability and better physical grip on the breadboard.

- Legs on the same side (e.g. A and B) are always internally connected to each other.
- Legs on the opposite side (e.g. C and D) are always internally connected to each other.
- Pressing the button connects the "A-B side" to the "C-D side," completing the circuit across all 4 legs.

So functionally, a 4-leg push button behaves exactly like a simple 2-leg button — just physically more stable when placed on a breadboard (it won't wobble or come loose).

## Internal Working

Inside the button is a small spring-loaded metal dome or contact. When not pressed, this metal piece keeps the two internal sides physically separated (open circuit). Pressing the button physically pushes the metal contact down, bridging the two sides together (closed circuit). Releasing lets the spring push it back up, separating them again.

## Why It Needs a Pull-up or Pull-down Resistor

A button by itself only tells the circuit "connected" or "not connected" — it doesn't define what voltage the pin sees when *not* pressed. Without a pull-up or pull-down resistor, the pin would be left floating when the button isn't pressed, giving unreliable readings.

- **With a pull-up resistor** (or Arduino's internal `INPUT_PULLUP`): pin reads HIGH when not pressed, LOW when pressed.
- **With a pull-down resistor:** pin reads LOW when not pressed, HIGH when pressed.

## Common Notes

- Always check button orientation on a breadboard — placing it across the center gap (not along one side) ensures the two internal sides aren't accidentally shorted together already.