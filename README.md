
14-LED Circular Animation System
A manually controlled LED animation project built with an Arduino
Nano, 14 red LEDs, and one push button.

The project provides six lighting patterns and four selectable speeds. A
single button controls both pattern selection and speed adjustment.
Patterns do not change automatically.

Features
14 individually controlled LEDs arranged in a circular layout.
6 selectable animation patterns:
Circular Running Light
Alternate Flash
Opposite Chase
Scanner (back and forth)
Comet Effect
Heartbeat-style flash
4 speed levels.
One-button control.
Manual pattern selection; no automatic pattern switching.
Button debounce to reduce accidental multiple presses.
Components
Arduino Nano
14 red LEDs
14 resistors (220--330 Ω, one for each LED)
1 momentary push button
Breadboard and jumper wires
USB cable or suitable regulated 5 V supply
Wiring
LED connections
Connect each LED in series with its own resistor. The LED's anode (long
leg) connects to the Arduino pin through the resistor. The cathode
(short leg) connects to GND.

LED Arduino Nano pin
  1 D2
  2 D3
  3 D4
  4 D5
  5 D6
  6 D7
  7 D8
  8 D9
  9 D10
 10 D11
 11 D12
 12 D13
 13 A1
 14 A2
The order in the leds[] array must match the physical order of the
LEDs around the ring. If the animation runs in the wrong direction,
reverse the array order.

Push button
Button terminal Arduino Nano

One terminal A0
Other terminal GND

The sketch uses INPUT_PULLUP, so an external pull-up resistor is not
required. The button input is LOW while pressed.

Button controls
Button action Result

Power on / reset Starts with Pattern 1 at the slowest speed
Short press (less than 700 ms) Selects the next pattern
Long press (700 ms or longer) Selects the next speed
Repeated short presses Cycles through all 6 patterns
Repeated long presses Cycles through all 4 speeds

A long press changes the speed once. Releasing the button does not also
change the pattern.

Patterns
Circular Running Light --- one LED moves around the ring.
Alternate Flash --- alternating LED groups switch on and off.
Opposite Chase --- two LEDs opposite each other move around the
ring.
Scanner --- one LED moves forward and backward.
Comet Effect --- three adjacent LEDs move together around the
ring.
Heartbeat-style Flash --- all LEDs produce two flashes followed
by a pause.
Speed settings
The speed is controlled by the delay between animation steps.

Speed level Delay

Slow (default) 350 ms
Medium 200 ms
Fast 100 ms
Very fast 50 ms

These values can be changed in the speeds[] array in the Arduino
sketch.

Uploading the sketch
Install the Arduino IDE.
Connect the Arduino Nano to your computer using USB.
Open the project .ino sketch.
In Tools → Board, select Arduino Nano.
In Tools → Processor, select the processor option that matches
your Nano (many classic Nano boards use ATmega328P; some older
clones may require ATmega328P (Old Bootloader)).
In Tools → Port, select the correct serial port.
Click Upload.
Electrical and safety notes
Use one current-limiting resistor for each LED. Do not connect
an LED directly to an Arduino output pin.
Do not assume the Nano can safely supply the combined current of all
14 LEDs. Keep within the board and microcontroller pin-current
limits.
If the total LED current is too high, use suitable transistor or
MOSFET driver circuitry and a regulated external 5 V supply. Connect
the external supply ground to Arduino GND (common ground).
Do not connect an external 5 V supply and USB power in a way that
causes the supplies to drive each other.
Check LED polarity before powering the circuit.
Project structure
A simple GitHub repository can use this structure:

14-LED-Circular-Animation/
├── README.md
└── 14_LED_Circular_Animation/
    └── 14_LED_Circular_Animation.ino
Customization
Change LED order: edit the leds[] array.
Change speed: edit the values in the speeds[] array.
Change long-press duration: edit longPressTime.
Change patterns: edit the pattern functions and PATTERN_COUNT
together.
terms.

