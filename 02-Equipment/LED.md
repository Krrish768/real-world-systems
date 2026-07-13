# LED (Light Emitting Diode)

## What It Is

An LED is a component that emits light when current flows through it in one specific direction. Unlike a normal wire, it only allows current to flow one way — this is called being **polarized**.

## Where and When It Is Used

Used as a simple visual output — to indicate a state (ON/OFF), show status, or as a basic building block before moving to more complex outputs like displays or motors.

## Structure and Pins

An LED has exactly two legs (no GPIO — it's a passive output component, not a pin-configurable device like Arduino):

- **Anode (+):** The longer leg. Must be connected toward the positive/higher voltage side of the circuit.
- **Cathode (−):** The shorter leg. Also often identified by a flat edge on the LED's plastic casing. Must be connected toward GND.

## Internal Working

Inside an LED is a semiconductor junction (a diode). When current flows from anode to cathode, electrons crossing this junction release energy in the form of light (this is why it only lights up when connected the correct way around).

If connected backward, the LED simply does not light up — it blocks current in that direction (in normal low-voltage circuits, it won't get damaged either, it just stays off).

## Why a Resistor Is Always Needed

An LED has very little internal resistance. If connected directly to 5V with no resistor, it will draw too much current and burn out almost instantly. A resistor in series with the LED limits the current to a safe level (commonly 220Ω–330Ω for a standard 5mm LED at 5V).

## Common Notes

- LED color depends on the semiconductor material used — this also slightly changes the voltage drop across it (typically 1.8V–2.2V for red, slightly higher for blue/white).
- Connecting both LED legs into the same breadboard row shorts it out — no current will flow through the intended path.