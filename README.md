#  14 LED Circular Animation System

An Arduino Nano-based LED animation project featuring 14 red LEDs and a single push button. The system provides multiple lighting patterns and adjustable animation speeds with simple manual control.

##  Features

- 14 individually controlled red LEDs.
- 6 different lighting patterns.
- 4 adjustable speed levels.
- Single push-button control.
- No automatic pattern switching.
- Simple Arduino Nano implementation.

##  Lighting Patterns

| No. | Pattern | Description |
|---|---|---|
| 1 | Running Light | A single LED moves around the circular arrangement. |
| 2 | Alternate Flash | Odd and even LEDs turn on alternately. |
| 3 | Opposite Chase | Two opposite LEDs move together. |
| 4 | Scanner | A light moves forward and backward. |
| 5 | Comet Effect | Three adjacent LEDs move together like a comet. |
| 6 | Heartbeat | All LEDs flash in a double-pulse sequence. |

##  Speed Control

The project supports four speed levels:

| Level | Speed | Delay |
|---|---|---|
| 1 | Slow | 350 ms |
| 2 | Medium | 200 ms |
| 3 | Fast | 100 ms |
| 4 | Very Fast | 50 ms |

##  Button Controls

The project uses one push button for all controls.

- **Short Press:** Switch to the next lighting pattern.
- **Long Press (700 ms):** Change the animation speed.
- After the sixth pattern, the system returns to the first pattern.
- Speed settings cycle back to the slowest level after the fastest level.

All pattern changes are controlled manually.

##  Hardware Requirements

| Component | Quantity |
|---|---:|
| Arduino Nano | 1 |
| Red LEDs | 14 |
| 220Ω–330Ω Resistors | 14 |
| Push Button | 1 |
| Breadboard | 1 |
| Jumper Wires | As needed |
| USB Cable | 1 |



### LED Connections

| LED | Arduino Pin |
|---|---|
| LED 1 | D2 |
| LED 2 | D3 |
| LED 3 | D4 |
| LED 4 | D5 |
| LED 5 | D6 |
| LED 6 | D7 |
| LED 7 | D8 |
| LED 8 | D9 |
| LED 9 | D10 |
| LED 10 | D11 |
| LED 11 | D12 |
| LED 12 | D13 |
| LED 13 | A1 |
| LED 14 | A2 |

### Push Button Connection

| Button Terminal | Arduino Pin |
|---|---|
| Terminal 1 | A0 |
| Terminal 2 | GND |

Each LED must have its own current-limiting resistor connected in series.

The push button uses the Arduino internal pull-up resistor (`INPUT_PULLUP`).

##  Software Requirements

- Arduino IDE
- Arduino Nano board package
- USB connection for programming

##  Installation

1. Download or clone this repository.
2. Open the Arduino sketch in Arduino IDE.
3. Connect the Arduino Nano to your computer.
4. Select **Arduino Nano** from the Boards menu.
5. Select the correct COM port.
6. Upload the code.
7. Enjoy the LED animations!

##  Electrical Safety

- Use a separate resistor for each LED.
- Do not exceed the Arduino Nano GPIO current limits.
- Use suitable transistor drivers and an external regulated 5V supply if the total LED current exceeds safe board limits.
- Connect the external supply ground to Arduino GND.
- Do not connect an external 5V supply directly to the 5V pin while USB power is connected unless the power arrangement is designed to prevent backfeeding.

##  Project Structure

```text
14-LED-Circular-Animation/
│
├── 14_LED_Animation.ino
├── README.md
└── LICENSE
```


This project is open-source and available for educational and personal use.
