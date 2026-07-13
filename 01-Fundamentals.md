# Fundamentals — Physics & Electricity

This file contains my core theoretical notes for the RWS (Real World Systems) project.

The notes are written to build understanding of *why* things work, not to memorize definitions. This file grows continuously as I learn — new material is always added at the end of the relevant module, or as a new module at the bottom of the file.

---

## Module 01 — Electricity

### 1. Atom

Everything around us is made up of atoms.

An atom consists of:

- Proton (+)
- Neutron (0)
- Electron (−)

Protons and neutrons are present inside the nucleus. Electrons are present around the nucleus.

### 2. Electric Charge

Charge is an intrinsic property of matter.

- Proton → Positive Charge
- Electron → Negative Charge
- Neutron → No Charge

Rules:

- Like charges repel each other.
- Unlike charges attract each other.

### 3. Neutral Atom

If Number of Protons = Number of Electrons, then Total Charge = 0. The atom is electrically neutral.

Example: 10 Protons + 10 Electrons → Total Charge = 0

### 4. Conductors and Insulators

Copper is a conductor. Plastic is an insulator.

**Reason:** Copper has free outer electrons which can move easily from one atom to another. Plastic holds its electrons very tightly.

Therefore, copper allows current to flow, while plastic does not.

### 5. Free Electrons

Copper already contains billions of free electrons. These electrons are not created by the battery — they already exist inside the metal.

### 6. Random Motion of Electrons

Even without a battery, free electrons continuously move due to thermal energy. Their movement is completely random.

Since electrons move in every direction, Net Movement = 0, and therefore Current = 0.

### 7. Battery

The battery does **not** create electrons, and it does **not** free electrons. What the battery actually does is create an electric field inside the conductor. This electric field causes the already-free electrons to drift in one direction.

### 8. Electric Field

Electric Field is an invisible influence produced by electric charges. Inside a circuit, the battery establishes an electric field, which applies force on free electrons and causes them to drift.

Chain of cause and effect:

```
Battery → Electric Field → Electron Drift → Current
```

### 9. Voltage (Potential Difference)

Voltage is the difference in electric potential between two points. Think of it like the height difference between two water tanks — greater voltage means a stronger tendency for charges to move.

**Important:** Voltage always exists *between two points*. There is no voltage at a single point.

### 10. Electric Current

Current is the organized movement of electric charge through a conductor. In metals, free electrons are the charge carriers. Without a battery, free electrons move randomly, so net current is zero — a battery creates an electric field that causes electrons to drift in one direction, producing current.

Current is not the electrons themselves; it is a measure of the rate of flow of charge. Note also that the electric field propagates rapidly through the circuit, while individual electrons drift much more slowly than that.

**Formula:**

```
I = Q / t
```

Where:
- I = Current (Ampere)
- Q = Charge (Coulomb)
- t = Time (Second)

**Unit:** SI unit is Ampere (A). 1 A = 1 Coulomb of charge passing a point every second.

**Direction:**
- Electron Flow: Negative → Positive
- Conventional Current: Positive → Negative

### 11. Resistance

Resistance is the property of a material that opposes the flow of electric current.

At the microscopic level, resistance is caused by collisions between free electrons and vibrating positive ion cores in the material. More collisions reduce the drift of electrons, reducing current for a given voltage.

**Factors affecting resistance:**
- Material
- Length (longer wire → higher resistance)
- Cross-sectional area (thicker wire → lower resistance)
- Temperature (for most metals, higher temperature → higher resistance)

**Unit:** Ohm (Ω)

A resistor does not "consume" current — current entering a resistor equals the current leaving it. What happens instead is that electrical energy is often converted into heat due to resistance.

### 12. Ohm's Law

**Physical intuition:** Current depends on two factors — how strongly electrons are pushed (Voltage), and how difficult it is for electrons to move (Resistance).

Increasing voltage increases electron drift. Increasing resistance increases collisions. Therefore:

```
Current ∝ Voltage
Current ∝ 1 / Resistance
```

Combining both:

```
I ∝ V/R  →  I = V/R
```

Equivalent forms:

```
V = IR
R = V/I
```

**Engineering meaning:** Voltage is the push, resistance is the opposition, and current is the resulting flow.

```
Flow = Push / Opposition
```

**Validity:** This law is valid for Ohmic materials, where resistance remains approximately constant.

### 13. Electrical Power (Derivation)

Voltage represents energy supplied per unit charge. Current represents charge flowing per second. Therefore:

```
Power = Energy / Second
      = (Energy / Charge) × (Charge / Second)
      = Voltage × Current

P = VI
```

Using Ohm's Law, this can also be written as:

```
P = V²/R
P = I²R
```

---

## Module 02 — Digital Input

### 1. Input

An input allows information to enter the microcontroller from the outside world. The Arduino observes voltage on an input pin and interprets it as HIGH or LOW. Inputs are used to receive information from sensors, switches, and other external devices.

### 2. Digital Signal

Digital systems operate using two logical states: HIGH and LOW. Voltage is converted into these logical states using voltage thresholds, which makes digital systems resistant to small electrical noise.

### 3. Input Pin

Input pins observe voltage rather than generating it, and they draw extremely small current — behaving similarly to a voltmeter.

### 4. Floating Input

A floating input has no defined electrical connection. This produces unpredictable HIGH and LOW readings, since electrical noise from the environment can change the voltage of a floating pin.

**Rule of thumb:** Input pins should never be left floating.

### 5. Pull-down Resistor

Provides a default connection to Ground, preventing floating inputs.

- Button Released → LOW
- Button Pressed → HIGH

### 6. Pull-up Resistor

Provides a default connection to 5V, preventing floating inputs.

- Button Released → HIGH
- Button Pressed → LOW

### 7. Internal Pull-up Resistor

The Arduino UNO provides an internal pull-up resistor, enabled using:

```cpp
pinMode(pin, INPUT_PULLUP);
```

This eliminates the need for an external pull-up resistor in simple circuits.

### 8. Push Button

A push button is a momentary switch. It simply opens or closes a circuit — it does not generate electricity, and it does not consume electricity.

**Internal connections:**

Without pressing:
- Terminal A internally connected to Terminal B
- Terminal C internally connected to Terminal D

When pressed:
- All four terminals become electrically connected.

### 9. digitalRead()

Reads the logical state of an input pin and returns HIGH or LOW — essentially reading voltage and converting it into digital information.

### 10. Engineering Mindset

While analysing any circuit, always ask:

1. What is connected to what right now?
2. Is there a complete path from the power source, through the components, and back to Ground?

---
