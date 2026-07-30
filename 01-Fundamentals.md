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

---

## Module 03 — Polling, Bouncing & Signal Handling

### 1. Polling

Polling means repeatedly checking the state of something (like an input pin) at regular intervals, instead of waiting for it to notify you.

In Arduino, `digitalRead()` inside `loop()` is polling — the program keeps asking "what is the button's state right now?" over and over, as fast as the loop runs.

**Example:**

If one iteration of `loop()` (including all its code) takes 1 millisecond to execute, then in 3 seconds:
```
3 seconds = 3000 milliseconds
3000 ms / 1 ms per loop = 3000 reads
```

So the button state gets checked 3000 times in 3 seconds. If the loop takes longer (say 10ms per iteration, due to more code or delays), the same 3 seconds would only give 300 reads — polling frequency directly depends on how fast the loop runs.

**Downside:** Polling wastes CPU time checking things that haven't changed, and if the loop is slow, a very quick input change (like a fast button tap) might get missed between reads.

### 2. Mechanical Switch Bouncing

When a physical button or switch is pressed or released, the metal contacts inside don't touch cleanly in one instant. They physically bounce against each other several times within a few milliseconds before settling into a stable HIGH or LOW state.

**When it occurs:** Every single time a mechanical button is pressed or released — it's a physical property of metal contacts, not a code issue.

**Problem it causes:** During this bounce period, `digitalRead()` (if polling fast enough) sees the pin rapidly flicker between HIGH and LOW multiple times, instead of one clean transition. This can make the Arduino think the button was pressed several times for a single physical press — for example, incrementing a counter by 4 or 5 instead of 1.

**Fix (for later):** Software debouncing — ignoring changes for a short time (e.g. 20-50ms) right after detecting a change, until the signal has settled.

### 3. Polling vs Bouncing

These are two different things, often confused because they show up in the same button example:

- **Polling** is a technique — *how* the Arduino checks an input (by repeatedly reading it).
- **Bouncing** is a physical problem — *what* actually happens electrically inside a mechanical switch when pressed.

Polling is something you choose to do in code. Bouncing happens regardless of code, purely due to hardware — polling just happens to be the reason bouncing becomes visible as multiple false reads.

### 4. State vs Event vs Interrupt

Three different ways of thinking about how a program reacts to input:

- **State:** The current condition of something at a given moment (e.g. "button is HIGH right now"). Just a snapshot, no notion of change.
- **Event:** A change from one state to another (e.g. "button just went from HIGH to LOW"). Requires comparing the current reading to the previous one.
- **Interrupt:** A hardware-level mechanism where the microcontroller pauses whatever it's doing immediately when a specific condition occurs (e.g. pin changes state), and jumps to a special function — without needing to poll at all.

Polling using `digitalRead()` only gives you **state**. To detect an **event** (a press, not just "is pressed"), the code must remember the previous state and compare it each loop. **Interrupts** remove the need for polling entirely — the microcontroller reacts instantly and independently of how fast `loop()` is running.

### 5. Why a Single Press Often Registers as Multiple Presses

A press physically causes contact bounce (see Point 2), so the pin doesn't move cleanly from HIGH to LOW once — it flickers through several HIGH/LOW transitions within a few milliseconds before settling. If the code checks for a state change during this unstable window, each flicker looks like a fresh press to the program, even though the user only pressed the button once.

This is why a naive "if state changed, count a press" approach can register 3-5 presses for a single physical tap — the bug isn't in the counting logic, it's in trusting a signal that hasn't settled yet.

### 6. Why Professional Products Always Debounce Their Inputs

Any product with a physical button — a keyboard, a TV remote, an elevator panel — uses the same kind of mechanical switch, so it has the same bounce problem. Without debouncing:

- A single button press could register as multiple actions (e.g. skipping two menu items instead of one).
- Counters, toggles, and state machines driven by button presses would behave unpredictably.

Debouncing is not an optional polish step — it's a baseline requirement for any product that reads a mechanical switch, because bounce happens on every single press/release, on every switch, every time.

### 7. Hardware vs Software Debouncing (Concept Only)

Two different places to solve the same problem:

**Hardware Debouncing** — extra components (commonly a capacitor forming an RC low-pass filter with a resistor, sometimes a dedicated debounce IC) placed in the circuit itself. These physically smooth out the rapid HIGH/LOW glitches before the signal ever reaches the microcontroller pin, so the pin sees one clean transition.

**Software Debouncing** — no extra hardware. The program detects a change, then ignores further changes for a short window (commonly 20-50ms, using `millis()` or `delay()`) until the signal has had time to settle, before trusting the new state.

**Trade-off:**
- Hardware debouncing frees the microcontroller from timing logic but costs extra components and wiring per input.
- Software debouncing needs no extra parts but adds a small delay and a bit of code complexity to every input that needs it.

**Preventive measure used going forward in this repo:** software debouncing, since it needs no extra hardware and is flexible per-button.

### 8. Conditional Statements — if / else if / else

The core building block for software decision-making (Sense → Decide → Act):

```cpp
if (condition) {
  // runs only if condition is true
} else if (anotherCondition) {
  // runs only if the first condition was false AND this one is true
} else {
  // runs only if none of the above conditions were true
}
```

- `if` always checks its condition first; if true, its block runs and every `else if`/`else` after it is skipped.
- `else if` is checked only if everything above it was false — there can be any number of these.
- `else` has no condition — it's the fallback, and runs only when nothing above it matched.
- Only ever one block among an if / else if / else chain executes per pass through the code.

### 9. Detecting a State Change (Edge Detection) in Code

Point 4 established the difference between **state** (current condition) and **event** (a change between states). Reading a pin with `digitalRead()` only ever gives state — to turn that into an event, the code has to remember the previous reading and compare it to the current one, every loop:

```cpp
if (previousButtonState == HIGH && currentButtonState == LOW) {
  // this only runs on the exact loop where the button just got pressed
}
previousButtonState = currentButtonState;
```

This pattern is called **edge detection** — specifically a **falling edge** here, since it fires only on the HIGH→LOW transition (with `INPUT_PULLUP`, that's the moment of pressing). Without storing `previousButtonState`, the code would only ever know "is the button pressed right now," not "did it just get pressed" — the second one is what makes a toggle (as opposed to a follow-along ON-while-held behavior) possible.

## Module 04 — Timing, Clock Cycles, and delay()

### 1. Why a Microcontroller Has No Built-In Sense of Time

An Arduino doesn't "know" what a second is the way a wall clock does. It has no calendar, no internal notion of seconds or minutes — all it can actually do is count electrical pulses. Every concept of "time" on a microcontroller is built entirely on top of counting how many pulses have occurred, because pulses are the only thing the hardware natively produces at a fixed, predictable rate.

### 2. What a Clock Signal Is

Every Arduino has a **crystal oscillator** on the board — a small crystal that vibrates at an extremely precise, fixed rate when powered, producing a continuous stream of electrical pulses (HIGH-LOW-HIGH-LOW...). This stream is called the **clock signal**. It doesn't do any computation itself — its only job is to act as a metronome: every single pulse is one "tick," and the CPU synchronizes all its internal operations to these ticks.

'''
Clock signal (simplified):
HIGH ─┐ ┌─┐ ┌─┐ ┌─┐ ┌─
│ │ │ │ │ │ │ │
LOW └───┘ └───┘ └───┘ └───┘
↑cycle↑cycle↑cycle↑cycle
'''

### 3. What 16MHz Actually Means

- **Hz (Hertz)** = number of cycles per second. 1Hz = 1 cycle happens every second.
- **M (Mega)** = 1,000,000.
- So **16MHz = 16,000,000 cycles (pulses) every single second.**

This means one full pulse (one HIGH-LOW cycle) takes:
'''
1 second / 16,000,000 cycles = 0.0000000625 seconds per cycle
= 62.5 nanoseconds per cycle
'''
The CPU uses these 16 million ticks per second as its fundamental unit of time — everything it does is measured in "how many clock cycles did this take," not in seconds directly.

### 4. How the Arduino Turns Pulse-Counting Into Milliseconds

Since the clock produces a known, fixed number of pulses every second (16,000,000 for a 16MHz board), the microcontroller can work out real time purely by **counting pulses**:

- It knows 16,000,000 cycles = 1 real second.
- So 16,000 cycles ≈ 1 millisecond (16,000,000 ÷ 1000).
- A hardware **timer** inside the chip keeps incrementing a counter once per clock cycle. When that counter reaches the number of cycles equal to 1ms, an internal millisecond-counter is bumped up by one.

This is the entire mechanism `millis()` and `delay()` are built on underneath — there is no separate "time module," it's all pulse-counting.

### 5. What `delay(1000)` Actually Does Internally

`delay(1000)` does **not** mean "wait one second" in some magical sense — it means:

> "Keep checking the internal cycle-counter in a loop, doing nothing else, until it has counted enough clock cycles to equal 1000 milliseconds."

```cpp
// conceptually, this is what delay(1000) is doing internally:
unsigned long startTime = millis();     // note the current pulse-count-derived time
while (millis() - startTime < 1000) {
  // do literally nothing, just keep re-checking
}
// only once 1000ms worth of clock cycles have passed, execution continues below
```

During this entire window, the CPU is **busy-waiting** — actively spinning in this empty loop — not sleeping, not doing anything else, not reading any sensor or pin. It is simply burning cycles until the count target is hit.

### 6. Why `delay()` Is Rarely Used in Real Products

Because `delay()` is **blocking**, the CPU cannot do anything else — including reading buttons, checking sensors, or responding to a critical input — for the entire duration of the delay. Effectively, the microcontroller "ignores the world" for that window.

This is harmless in a simple LED blink project, but becomes dangerous in any system where missing an event even for a few hundred milliseconds matters:

- **Medical devices** (e.g. a patient monitor or ventilator) — if the code is stuck inside a `delay()`, it cannot detect an emergency-stop button press or a sensor threshold being crossed during that window.
- **Safety-critical systems** (industrial machinery, automotive braking, elevator doors) — an obstacle sensor or emergency input triggered during a `delay()` simply will not be seen until the delay finishes, which could directly cause an accident.
- **Any responsive system** (robotics, multi-sensor projects) — every `delay()` call is a period where the entire rest of the program is frozen, not just the LED/component being timed.

This is why real-world embedded code almost always replaces `delay()` with **non-blocking timing** (comparing `millis()` against a stored start-time inside the normal loop, without ever pausing execution) — so the CPU stays free to keep sensing and reacting the entire time. *(Non-blocking timing with `millis()` will be covered in a later module.)*

## Module 05 — Instructions, Interrupts, Race Conditions & Memory

### 1. What an "Instruction" Actually Is

A single line like `digitalWrite(ledPin, HIGH)` looks like one step, but it is not a single instruction to the CPU — it's a function that expands into many underlying instructions:

- Look up which physical port the given pin number belongs to
- Read the current value of that port's output register
- Modify only the bit corresponding to that pin (set it HIGH, leave the rest untouched)
- Write the modified value back to the port register

Each of these smaller steps is closer to what the CPU actually executes one at a time. The CPU only ever does one instruction at a time, in sequence — "high level" function calls are just convenient names for a bundle of these low-level instructions.

### 2. What an Interrupt Is

An interrupt is a signal that says: **"Interrupt whatever you're doing right now."**

Normally the CPU executes code top to bottom, instruction by instruction, in the order the program lays them out. An interrupt breaks that order — when it arrives, the CPU pauses the currently running instruction sequence, goes and runs a separate small function (the **Interrupt Service Routine**, or ISR), and only then returns to exactly where it left off.

### 3. Why Interrupts Are Required

Without interrupts, the CPU can only ever notice something (like a button press or sensor change) if it happens to be checking that pin at that exact moment in the loop — this is **polling** (Module 03). If the CPU is busy elsewhere (inside a long calculation, a `delay()`, or another task) when the event happens, it simply misses it.

An interrupt removes this dependency on "was the CPU checking right now" — the hardware itself notices the event and forces the CPU to respond, regardless of what it was doing.

### 4. Interrupt ≠ Faster — It Means Higher Priority

An interrupt does not make the CPU execute anything faster. The CPU still runs at the same clock speed either way. What an interrupt changes is **priority** — it forces whatever is happening right now to pause so something more urgent gets handled first. Speed of execution is unchanged; order of execution is what interrupts control.

### 5. The Interrupt Flow
'''
Current Instruction
↓
Interrupt Arrives
↓
Save Current Position
↓
Jump to Interrupt Function
↓
Execute Interrupt Function
↓
Restore Saved Position
↓
Continue Normal Program
'''

Every interrupt follows this exact sequence, no matter what triggered it — a button, a timer, a sensor. The CPU never "forgets" what it was doing; it always returns to precisely where it paused.

### 6. Program Counter — The CPU's Bookmark

The **Program Counter (PC)** is a register inside the CPU that always holds the memory address of the *next* instruction to execute. It's what makes "Save Current Position" and "Restore Saved Position" (Point 5) possible:

- When an interrupt arrives, the CPU saves the current Program Counter value (its bookmark) before jumping into the ISR.
- Once the ISR finishes, the CPU loads that saved value back into the Program Counter — this is exactly how it knows where to resume, instruction-for-instruction, as if nothing happened.

Without a Program Counter, the CPU would have no way to know where it was, and interrupts would be impossible to return from correctly.

### 7. Race Condition

A **race condition** happens when the normal program and an interrupt both access the same variable, and the timing of *when* the interrupt happens changes the final result — even though the code looks correct on its own.

Take `x = x + 1`. This single line is actually multiple low-level steps:
'''
Step 1: Read x from memory into a register
Step 2: Add 1 to the value in the register
Step 3: Write the register's value back to x in memory
'''
Now suppose the normal program is running `x = x + 1`, and right after **Step 1** (x has been read as, say, 5, but not yet written back), an interrupt fires. The ISR sets `x = 100` directly and finishes. Control returns to Step 2 and Step 3 of the original instruction — but those steps are still working with the *old* value it read in Step 1 (5), not the interrupt's new value (100):
'''
Normal program reads x (x = 5) → Step 1
↓ [interrupt fires here]
ISR sets x = 100 → x is now 100 in memory
↓ [interrupt finishes, resumes normal program]
Normal program adds 1 to its old copy (5 + 1 = 6) → Step 2
Normal program writes 6 back to x → Step 3
Final value of x = 6 (the ISR's 100 is silently lost)
'''
The bug isn't in the math or the logic — it's that both the main program and the ISR touched the same variable, and the exact moment the interrupt happened determined which value survived. This is why shared variables between an ISR and the main program are a classic source of subtle, hard-to-reproduce bugs.

### 8. `volatile` — "Don't Assume This Variable Stays the Same"

`volatile` tells the compiler: **"Don't assume this variable stays the same. Someone outside the normal program may change it at any time."**

Normally, compilers optimize code by assuming a variable won't change unless the current code changes it — so they may cache its value in a CPU register instead of re-reading it from RAM every time, for speed. This optimization is exactly wrong for a variable an ISR can modify:
'''
Main program sets a value, expecting to check it later
↓
Compiler optimizes: caches that value in a register for speed
↓
ISR changes the actual variable in RAM
↓
Main program checks the variable — but reads the stale cached
register value, not the updated RAM value — and never sees the change
'''
Marking the variable `volatile` forces the compiler to always re-read it fresh from RAM on every access, never trust a cached register copy — guaranteeing the main program actually sees changes an ISR makes.

### 9. What Should (and Shouldn't) Go Inside an ISR

An ISR pauses the entire normal program while it runs, so it must be as short as possible. Checklist:

**Does it execute quickly?**
✅ Good.

**Does it wait for something?**
❌ Bad.

**Does it allocate memory?**
❌ Bad.

**Does it print to Serial?**
❌ Usually bad.

**Does it use `delay()`?**
❌ Never.

**Does it simply set a flag?**
✅ Excellent.

The standard pattern: the ISR does the absolute minimum (usually just flipping a `volatile` flag or variable), and the main `loop()` checks that flag and does the real work — keeping the interrupt itself fast, and the heavy logic back in normal, interruptible program flow.

### 10. Flash Memory, RAM, and Registers — What Lives Where

A microcontroller has three different kinds of storage, each with a different job:

| | Flash Memory | RAM | Registers |
|---|---|---|---|
| **Stores** | The program code itself (the compiled sketch) | Variables that change while the program runs | The single value a CPU instruction is actively working on |
| **Volatile?** | Non-volatile (survives power-off) | Volatile (wiped on power-off) | Volatile |
| **Size** | Large (e.g. 32KB on an UNO) | Small (e.g. 2KB on an UNO) | Extremely small (a handful of bytes total) |
| **Speed** | Slower | Fast | Fastest |
| **Read/write endurance** | Limited — designed for occasional writes (flashing new code) | Designed for millions to billions of read/write cycles | Designed for constant read/write, every single clock cycle |

**Why the size difference:** code doesn't change while running, so it can sit in large, non-volatile Flash. Variables change constantly during execution, so they need a fast, freely-rewritable space — that's RAM. Registers are kept extremely small and extremely fast on purpose, because the CPU touches them on literally every instruction.

**The flow when a variable is updated:**
'''
Flash Memory (program code, fixed)
↓ Arduino executes instructions directly from Flash
CPU needs a variable's value
↓ fetch from RAM
Register (loaded with that value to work on it)
↓ CPU performs the operation (e.g. add 1)
Register now holds the updated value
↓ written back
RAM (variable's stored value is updated)
'''

Unlike the code itself, an Arduino does **not** copy variables into RAM once and forget them — every time a variable is read or written during `loop()`, this Flash-stays-put, RAM-holds-current-value, register-does-the-work cycle repeats. This is also exactly why `volatile` (Point 8) matters: it forces every one of these RAM fetches to actually happen, instead of letting the compiler skip the fetch and reuse a stale register copy.

---
