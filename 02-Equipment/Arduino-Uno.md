# Arduino UNO

## What It Is

Arduino UNO is a microcontroller board built around the ATmega328P chip. It's a small computer that can read inputs (button press, sensor value) and control outputs (LED, motor) based on a program you write and upload to it.

## Where and When It Is Used

Used whenever you need to control real-world hardware with code — turning things on/off, reading sensor data, timing events, or making decisions based on physical input. It's the "brain" of almost every project in this repo.

## Pin Structure

- **Digital Pins (0–13):** Can be set as INPUT or OUTPUT. Only understand two states — HIGH (5V) or LOW (0V).
- **Analog Input Pins (A0–A5):** Can read a range of voltages (0–5V), not just HIGH/LOW. Used for sensors that give varying values (like a potentiometer or light sensor).
- **PWM Pins (marked with `~`, e.g. 3, 5, 6, 9, 10, 11):** Digital pins that can simulate an analog output by rapidly switching HIGH/LOW (used for dimming LEDs, controlling motor speed).
- **5V and 3.3V pins:** Provide power to external components.
- **GND pins:** Common ground — every circuit needs a path back to GND to complete the circuit.
- **VIN:** Input for external power supply (e.g. 9V battery) instead of USB.

## What Happens Inside a Pin (Internal Working)

Every digital pin is connected to a piece of internal circuitry with two important registers:

- **DDR (Data Direction Register):** Decides if the pin behaves as INPUT or OUTPUT.
- **PORT Register:** Decides the pin's HIGH/LOW state (if OUTPUT) or enables/disables an internal pull-up resistor (if INPUT).

When you write `pinMode(pin, OUTPUT)`, the chip internally connects that pin to a transistor switch that can pull the pin to 5V (HIGH) or 0V (LOW) — this is what physically drives current out of the pin.

When you write `pinMode(pin, INPUT)`, the pin becomes high-impedance — it just "listens" to voltage without driving current. In this mode, if nothing is connected, the pin is *floating* and gives unpredictable readings.

## Internal Pull-up Resistor

The ATmega328P has a **built-in pull-up resistor** (roughly 20–50 kΩ) for every digital pin. This resistor connects the pin internally to 5V.

- Writing `pinMode(pin, INPUT_PULLUP)` internally connects this resistor between the pin and 5V.
- With nothing pressed/connected, the pin reads HIGH by default (because it's pulled toward 5V).
- When a button connects that pin to GND, the pin reads LOW.

**Important:** Arduino UNO only has an internal **pull-up** resistor — there is no internal pull-down resistor. If you want pull-down behavior (default LOW, goes HIGH when pressed), you must add an external resistor between the pin and GND.

## Common Notes

- The board is powered either via USB (5V) or an external supply through VIN (7–12V recommended, regulated internally to 5V).
- The onboard voltage regulator handles converting external power to the 5V the chip needs.
- Uploading code happens via USB, using the UART (serial) connection built into the board.