# ATmega328P — Architecture Deep Dive

A module-by-module breakdown of what's happening inside the ATmega328P chip itself — how the CPU, memory, and peripherals actually work together.

---

## Module 01 — Architecture Overview
```
+------------------------------------------------------+
|                      ATmega328P                      |
|                                                      |
| +--------------------------------------------------+ |
| |                CPU                               | |
| +--------------------------------------------------+ |
|                                                      |
| +-----------------------+ +------------------------+ |
| |        Flash          | |          SRAM          | |
| +-----------------------+ +------------------------+ |
|                                                      |
| +--------------------------------------------------+ |
| |                     EEPROM                       | |
| +--------------------------------------------------+ |
|                                                      |
| GPIO  Timers  UART  SPI  I2C  ADC  Interrupts        |
|                                                      |
+------------------------------------------------------+
```
### 1. CPU — The Brain

The CPU is the brain of the chip, but it doesn't do everything itself — its real job is **coordinating** the other components so the right thing happens at the right time.

### 2. The CPU Cycle — Fetch → Decode → Execute → Repeat

Every single instruction the CPU runs goes through the same three-step cycle, endlessly:

- **Fetch** — get the next instruction from Flash memory.
- **Decode** — figure out what that instruction actually means/wants done.
- **Execute** — actually perform it:
  - Addition/subtraction/logic → **ALU** does it.
  - Loading a value → data moves from RAM into a register.
  - A jump → the **Program Counter** changes to point elsewhere.
- Then the cycle **repeats** from Fetch, forever, as long as the chip is powered.

The CPU only understands **machine code** (raw binary instructions) — it never reads C/Arduino code directly. The **compiler** is what translates human-written code into machine code before it ever reaches the chip.

### 3. The Three Parts of the CPU

**ALU (Arithmetic Logic Unit)** — the calculator.
- Performs: `+`, `-`, `*` (no direct divide), increment, decrement.
- Logical ops: AND, OR, NOT, XOR, `<`, `>`.
- It only calculates — it does **not** store or remember anything itself.

**Registers** — tiny, extremely fast storage locations inside the CPU itself. ATmega328P has **32 general-purpose registers**. Values are loaded here right before the ALU (or another operation) needs to use them.

**Control Unit** — the manager. It doesn't calculate (that's ALU's job) or store (that's registers'/RAM's job) — it just arranges and coordinates everything else, like the conductor of an orchestra.

### 4. Why Splitting Responsibility Makes CPUs Fast

Instead of one giant component doing everything, the chip divides the work — and each part only ever specializes in one job:

- ALU → computes.
- Registers → hold temporary values.
- Control Unit → coordinates.
- RAM → stores changing data.
- Flash → stores code.

This specialization is exactly why modern CPUs can run so fast — no single part is a bottleneck doing every kind of work.
