# Electronics Notes

This file contains my study notes while learning Electronics in the RWS (Real World Systems) project.

The notes are written for understanding concepts rather than memorizing definitions.

---

# Module 01 - Electricity

## 1. Atom

Everything around us is made up of atoms.

An atom consists of:

- Proton (+)
- Neutron (0)
- Electron (-)

Protons and neutrons are present inside the nucleus.

Electrons are present around the nucleus.

---

## 2. Electric Charge

Charge is an intrinsic property of matter.

- Proton → Positive Charge
- Electron → Negative Charge
- Neutron → No Charge

Rules:

- Like charges repel each other.
- Unlike charges attract each other.

---

## 3. Neutral Atom

If,

Number of Protons = Number of Electrons

then,

Total Charge = 0

The atom is electrically neutral.

Example:

10 Protons + 10 Electrons

Total Charge = 0

---

## 4. Conductors and Insulators

Copper is a conductor.

Plastic is an insulator.

Reason:

Copper has free outer electrons which can move easily from one atom to another.

Plastic holds its electrons very tightly.

Therefore,

Copper allows current to flow.

Plastic does not.

---

## 5. Free Electrons

Copper already contains billions of free electrons.

These electrons are not created by the battery.

They already exist inside the metal.

---

## 6. Random Motion of Electrons

Even without a battery,

free electrons continuously move due to thermal energy.

Their movement is completely random.

Since electrons move in every direction,

Net Movement = 0

Therefore,

Current = 0

---

## 7. Battery

The battery does NOT create electrons.

The battery does NOT free electrons.

The battery creates an electric field inside the conductor.

This electric field causes the already free electrons to drift in one direction.

---

## 8. Electric Field

Electric Field is an invisible influence produced by electric charges.

Inside a circuit,

the battery establishes an electric field.

The electric field applies force on free electrons and causes them to drift.

Battery

↓

Electric Field

↓

Electron Drift

↓

Current

---

## 9. Voltage (Potential Difference)

Voltage is the difference in electric potential between two points.

Think of it like the height difference between two water tanks.

Greater voltage means a stronger tendency for charges to move.

Important:

Voltage always exists between two points.

There is no voltage at a single point.

---

## Engineering Misconceptions

❌ Battery creates electrons.

✔ Battery only creates the electric field.

---

❌ Copper becomes conductive only after connecting the battery.

✔ Copper already contains free electrons.

---

❌ Free electrons stay still inside the wire.

✔ Free electrons continuously move randomly because of thermal energy.

---

❌ Touching every copper wire gives an electric shock.

✔ A shock requires both a potential difference and a complete path through the body.

---

## Summary

Atom

↓

Charge

↓

Free Electrons

↓

Random Motion

↓

Battery

↓

Electric Field

↓

Voltage

↓

(Current - Coming Next)

## Electric Current

- Current is the organized movement of electric charge through a conductor.
- In metals, free electrons are the charge carriers.
- Without a battery, free electrons move randomly, so net current is zero.
- A battery creates an electric field that causes electrons to drift in one direction.
- Current measures the rate of flow of electric charge.

Formula:

I = Q / t

Where:
- I = Current (Ampere)
- Q = Charge (Coulomb)
- t = Time (Second)

### Unit

- SI Unit: Ampere (A)
- 1 A = 1 Coulomb of charge passing a point every second.

### Direction

- Electron Flow: Negative → Positive
- Conventional Current: Positive → Negative

### Important Notes

- A battery does not create electrons.
- Current is not the electrons themselves; it is a measure of charge flow.
- The electric field propagates rapidly through the circuit, while individual electrons drift much more slowly.

## Resistance

- Resistance is the property of a material that opposes the flow of electric current.
- At the microscopic level, resistance is caused by collisions between free electrons and vibrating positive ion cores in the material.
- More collisions reduce the drift of electrons, reducing current for a given voltage.

Factors affecting resistance:
- Material
- Length (longer wire → higher resistance)
- Cross-sectional area (thicker wire → lower resistance)
- Temperature (for most metals, higher temperature → higher resistance)

Unit:
- Ohm (Ω)

Important Notes:
- A resistor does not consume current.
- Current entering a resistor equals the current leaving it.
- Electrical energy is often converted into heat due to resistance.

## Ohm's Law

### Physical Intuition

Current depends on two factors:

- How strongly electrons are pushed (Voltage)
- How difficult it is for electrons to move (Resistance)

Increasing voltage increases electron drift.

Increasing resistance increases collisions.

Therefore,

Current ∝ Voltage

Current ∝ 1 / Resistance

Combining both,

I ∝ V/R

Removing proportionality,

I = V/R

Equivalent forms:

V = IR

R = V/I

Engineering Meaning

Voltage is the push.

Resistance is the opposition.

Current is the resulting flow.

Flow = Push / Opposition

Important Notes

- Valid for Ohmic materials.
- Resistance should remain approximately constant.

### Derivation

Voltage represents energy supplied per unit charge.

Current represents charge flowing per second.

Therefore,

Power

= Energy / Second

= (Energy / Charge) × (Charge / Second)

= Voltage × Current

P = VI

Using Ohm's Law,

P = V²/R

P = I²R

# Digital Input

## Input

- An input allows information to enter the microcontroller from the outside world.
- The Arduino observes voltage on an input pin and interprets it as HIGH or LOW.
- Inputs are used to receive information from sensors, switches and external devices.

---

## Digital Signal

- Digital systems operate using two logical states:
  - HIGH
  - LOW
- Voltage is converted into logical states using voltage thresholds.
- Digital systems are resistant to small electrical noise.

---

## Input Pin

- Input pins observe voltage rather than generating it.
- They draw extremely small current.
- They behave similarly to a voltmeter.

---

## Floating Input

- A floating input has no defined electrical connection.
- Floating inputs produce unpredictable HIGH and LOW readings.
- Electrical noise from the environment can change the voltage of a floating pin.
- Input pins should never be left floating.

---

## Pull-down Resistor

- Provides a default connection to Ground.
- Prevents floating inputs.
- Button Released → LOW
- Button Pressed → HIGH

---

## Pull-up Resistor

- Provides a default connection to 5V.
- Prevents floating inputs.
- Button Released → HIGH
- Button Pressed → LOW

---

## Internal Pull-up Resistor

- Arduino UNO provides an internal pull-up resistor.
- Enabled using:

```cpp
pinMode(pin, INPUT_PULLUP);
```

- Eliminates the need for an external pull-up resistor in simple circuits.

---

## Push Button

- A push button is a momentary switch.
- It simply opens or closes a circuit.
- It does not generate electricity.
- It does not consume electricity.

### Internal Connections

Without pressing:

- A internally connected to B
- C internally connected to D

Pressed:

- All four terminals become electrically connected.

---

## digitalRead()

- Reads the logical state of an input pin.
- Returns HIGH or LOW.
- Reads voltage and converts it into digital information.

---

## Engineering Mindset

While analysing any circuit, always ask:

1. What is connected to what right now?
2. Is there a complete path from the power source, through the components, and back to Ground?