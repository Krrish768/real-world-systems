# RWS-ELE-003 — Push Button Input

## Objective

Learn how a microcontroller receives digital input from the real world and makes decisions based on that input using a push button and an LED.

---

## Components Used

- Arduino UNO
- Breadboard
- Push Button
- LED
- 220Ω Resistor
- Jumper Wires
- USB Cable

---

## Theory Covered

- Digital Input
- Input Pin
- Push Button
- INPUT_PULLUP
- digitalRead()
- if Statement
- Software Decision Making
- Sense → Decide → Act

---

## Circuit Connections

### LED

| Arduino | Component |
|----------|-----------|
| D2 | 220Ω Resistor |
| Resistor | LED Anode |
| LED Cathode | GND |

### Push Button

| Arduino | Component |
|----------|-----------|
| D8 | Push Button |
| Push Button | GND |

Arduino internal pull-up resistor is enabled using `INPUT_PULLUP`.

No external pull-up resistor is required.

---

## Working Principle

The push button is connected between the Arduino input pin and Ground.

The Arduino enables its internal pull-up resistor, keeping the input HIGH when the button is released.

When the button is pressed, the input pin becomes connected to Ground and reads LOW.

The program continuously checks the button state using `digitalRead()`.

If the button is pressed, the Arduino turns the LED ON.

When the button is released, the LED turns OFF.

---

## Program Logic

Start

↓

Configure LED pin as OUTPUT

↓

Configure Button pin as INPUT_PULLUP

↓

Read Button State

↓

Button Pressed?

├── Yes → Turn LED ON

└── No → Turn LED OFF

↓

Repeat Forever

---

## Learning Outcomes

- Understood digital input.
- Learned how `digitalRead()` works.
- Learned why floating inputs are unreliable.
- Learned the purpose of pull-up resistors.
- Used Arduino's internal pull-up resistor.
- Built the first interactive embedded system.
- Implemented software decision making using `if`.

---

## Common Mistakes

- Incorrect push button orientation.
- Forgetting `INPUT_PULLUP`.
- Assuming HIGH always means button pressed.
- Leaving an input pin floating.
- Connecting the LED through the push button instead of controlling it through software.

---

## Output

- Button Released → LED OFF
- Button Pressed → LED ON

---

## Future Improvements

- Toggle LED on each button press.
- Add software debouncing.
- Interface multiple buttons.
- Control multiple outputs using button input.