# Arduino Robot Arm


<img width="4000" height="3000" alt="IMG_20201123_133804" src="https://github.com/user-attachments/assets/58fb33c2-b547-4789-bcd2-c83c981a74b7" />

![Arduino Robot Arm/Demo.gif](./Demo.gif)


# Components

- Breadboard
- Potentiometers - resistance value is not critical, 2x10kΩ are used here
- Analog joystick module
- 4x generic servo motors - SG90 mirco servos are used here
- wooden sticks or cardboard
- microcontroller board Arduino Uno R3

# Wiring & Circuit Diagram

- 5V connection to the breadboard to supply power to the potentiometers, joystick module, and servos
- Red wire for positive voltage (+), connected to the lower horizontal power rail on the breadboard
- Black wire for ground (GND), connected to the row directly above it
- Yellow/Blue wires for signal connections -> the potentiometers and joystick module are connected to analog input pins
- Servos are connected to digital pins for output signals

  <img width="2286" height="1122" alt="Screenshot 2026-10-11 131920" src="https://github.com/user-attachments/assets/5d17366f-1cd4-46cc-879d-3bafe643659e" />
