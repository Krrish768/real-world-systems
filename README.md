# RWS — Real World Systems

> Building engineering systems from first principles.

This is **not** an Arduino tutorial.

RWS is a long-term learning project where I study Electronics, Embedded Systems, Sensors, and Robotics from first principles — by building real hardware, one concept at a time — with the eventual goal of building an autonomous indoor car/robot.

---

## Learning Philosophy

Every topic follows the same workflow:

**Understand → Build → Debug → Document → Commit → Push**

Theory is always learned before implementation. The goal isn't just to make hardware work — it's to understand *why* it works.

---

## Repository Structure

```
real-world-systems/
├── README.md              → you are here (overview + structure)
├── INDEX.md                → full navigation map (find anything instantly)
├── LICENSE
├── images/                  → misc/general images (non project-specific)
│
├── 01-Fundamentals.md       → core physics & electricity theory
│
├── 02-Equipment/            → one file per component/device used
│   ├── Arduino-Uno.md
│   ├── Breadboard.md
│   ├── LED.md
│   └── ...
│
└── 03-Projects/             → every hands-on project
    └── RWS-ELE-XXX-Name/
        ├── README.md         → objective, theory, circuit, learnings
        ├── code/              → source code (.ino files)
        └── images/            → project-specific images
```

- **`01-Fundamentals.md`** — all core physics & electricity concepts in one place, no need to hunt across multiple notes.
- **`02-Equipment/`** — one file per device/component, named after the device itself, so it's instantly findable.
- **`03-Projects/`** — each project is self-contained: a `README.md` with full write-up, a `code/` folder, and an `images/` folder. Nothing else needed inside.
- **`INDEX.md`** — a clickable master list linking to every fundamentals file, equipment file, and project.

---

## Final Goal

An autonomous indoor car/robot capable of:

- Indoor Mapping & Localization
- Dynamic Path Planning & Obstacle Avoidance
- Voice Commands & Gesture Control
- AI-based Perception

Every concept learned in this repo feeds directly into building this final system.

---

## Roadmap

- ✅ Level 00 — Foundations
- 🚧 Level 01 — Electronics
- ⏳ Level 02 — Embedded Systems
- ⏳ Level 03 — Sensors
- ⏳ Level 04 — Communication
- ⏳ Level 05 — Control Systems
- ⏳ Level 06 — Mini Systems
- ⏳ Level 07 — Robotics
- ⏳ Level 08 — Computer Vision
- ⏳ Level 09 — Autonomous Systems
- ⏳ Level 10 — AI Integration

---

## Current Status

**Level:** Level 01 — Electronics (In Progress)
**Module:** Digital Input

**Projects completed:**
- ✅ RWS-ELE-001 — First Light
- ✅ RWS-ELE-002 — Blink
- ✅ RWS-ELE-003 — Push Button Input

---

## License

This project is licensed under the [MIT License](LICENSE).