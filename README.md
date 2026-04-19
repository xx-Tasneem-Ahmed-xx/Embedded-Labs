# Embedded Systems Labs

This repository contains the embedded systems laboratory work created for academic purposes at **Cairo University Faculty of Engineering Computer Department**. The labs cover fundamental concepts in embedded systems programming using Arduino.

## Lab Contents

- **Lab 1**
  - **IO Ports** (`lab1/io_ports/io_ports.ino`) - Input/Output port configuration and control
  - **Motor** (`lab1/motor/motor.ino`) - Basic motor control using microcontroller outputs
- **Lab 2**
  - **Interrupt** (`lab2/interrupt/interrupt.ino`) - Hardware interrupt handling and implementation
- **Lab 3**
  - **CTC Timer Mode** (`lab3/ctc/ctc.ino`) - Timer in Clear Timer on Compare Match (CTC) mode
  - **Timer** (`lab3/timer/timer.ino`) - Timer configuration and normal timer operations
- **Lab 4**
  - **ICU** (`lab4/icu/icu.ino`) - Input Capture Unit for measuring time intervals
  - **Timer + 7-Segment** (`lab4/timer_7segment/timer_7segment.ino`) - Timer-driven 7-segment display control
- **Lab 5**
  - **ADC** (`lab5/ADC/ADC.ino`) - Analog-to-Digital Converter basic reading
  - **ADC Interrupt** (`lab5/ADC_INTERRUPT/ADC_INTERRUPT.ino`) - ADC conversion with interrupt-based handling
  - **ADC LEDs** (`lab5/ADC_LEDS/ADC_LEDS.ino`) - ADC-based LED indication/control
- **Lab 6**
  - **SPI** (`lab6/SPI/SPI.ino`) - Serial Peripheral Interface communication basics

## Prerequisites

To run these labs, you will need:

- **Arduino IDE** - Download and install from [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)
- **Arduino Board** - Compatible Arduino hardware (e.g., Arduino Uno, Mega, etc.)
- **USB Cable** - For connecting the Arduino board to your computer

## How to Run

1. **Open a Lab File**
   - Launch Arduino IDE
   - Go to `File` → `Open`
   - Navigate to the desired lab folder (e.g., `lab2/interrupt/`, `lab4/timer_7segment/`, or `lab6/SPI/`)
   - Select the `.ino` file you want to run

2. **Connect Your Arduino Board**
   - Connect your Arduino board to your computer via USB cable
   - In Arduino IDE, go to `Tools` → `Board` and select your Arduino board model
   - Go to `Tools` → `Port` and select the COM port your Arduino is connected to

3. **Upload and Run**
   - Click the **Verify** button (✓) to compile the code
   - Click the **Upload** button (→) to upload the code to your Arduino board
   - Open the Serial Monitor (`Tools` → `Serial Monitor`) if the program uses serial communication

## License

See the [LICENSE](LICENSE) file for details.
