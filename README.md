SA818 VHF/UHF Radio Frequency Switcher with ESP32
=================================================

This project involves using an ESP32 microcontroller and an SA818 radio frequency module to switch between VHF/UHF frequencies. The frequencies are stored in a CSV file on a micro SD card, allowing for easy modification of the frequency channels.

Description
-----------

The SA818 VHF/UHF Radio Frequency Switcher with ESP32 is a project that allows for the selection of VHF/UHF frequencies using an ESP32 microcontroller and an SA818 radio frequency module. The frequency channels are stored in a CSV file on a micro SD card. The user can easily modify the CSV file to add or remove frequency channels.

The SA818 radio frequency module can be configured to operate on both VHF and UHF frequencies, allowing for a wide range of applications. The ESP32 microcontroller communicates with the SA818 module using UART serial communication.

This project is useful for applications that require the selection of multiple frequency channels, such as amateur radio, two-way radios, and wireless communication systems.

Wiring
------

| ESP32 | SA818 |
| --- | --- |
| 3.3V | VCC |
| GND | GND |
| RX2 | TXD |
| TX2 | RXD |

Usage
-----

1.  Insert the micro SD card with the CSV file containing the frequency channels into the micro SD card slot on the ESP32.
2.  Power on the ESP32 using a USB cable or battery.
3.  The ESP32 will automatically read the CSV file and store the frequency channels.
4.  To switch between frequency channels, send a command to the ESP32 using a serial terminal program such as PuTTY or Arduino Serial Monitor. The command format is `FREQ <channel>`, where `<channel>` is the desired frequency channel number.
5.  The ESP32 will send the frequency channel selection to the SA818 module, which will then tune to the selected frequency channel.

CSV File Format
---------------

The CSV file containing the frequency channels must be formatted with the following columns:

1.  Channel Number
2.  Frequency (in MHz)
3.  City
4.  State
5.  Zip Code
6.  Notes

Each row in the CSV file represents a single frequency channel.

Example CSV file:

javascriptCopy code

```
Channel Number,Frequency,City,State,Zip Code,Notes
1,146.5200,Los Angeles,CA,90001,SIMPLEX
2,446.0000,San Francisco,CA,94101,REPEATER, PL TONE 123.0Hz
3,144.3900,New York,NY,10001,APRS
4,441.1000,Miami,FL,33101,SIMPLEX
```



Improvements
------------

-   Add the ability to store more than 10 frequency channels.
-   Add the ability to modify frequency channels on the fly without needing to edit the CSV file.
-   Implement a user interface for selecting frequency channels.

License
-------

This project is licensed under the MIT License. See the `LICENSE` file for details.



Installation
------------

To use this project, you'll need to install the following libraries in the Arduino IDE:

-   SD (included with the Arduino IDE)
-   SoftwareSerial (included with the Arduino IDE)
-   DebounceSwitch (<https://github.com/madleech/Button>)

Download the code from this repository and open it in the Arduino IDE. Modify the `FREQ_FILENAME` constant to the filename of your CSV file containing the frequency channels.

Compile and upload the code to your ESP32 development board.

Usage
-----

1.  Power on the ESP32 development board.
2.  Press the button to switch to the next frequency channel.
3.  The current frequency channel will be displayed on the serial monitor.
4.  To add or remove frequency channels, modify the CSV file on the microSD card.
5.  To change the frequency channel order, modify the CSV file.







SA818 VHF/UHF Transceiver with ESP32
====================================

This project provides a simple way to control a VHF/UHF transceiver (SA818) using an ESP32 microcontroller. The project allows for the storage of an unlimited number of frequency channels on a micro SD card in CSV format. The user can switch between the channels using a push button connected to the ESP32. The project uses the SoftwareSerial library to communicate with the SA818 module.

Table of Contents
-----------------

-   [Requirements](https://chat.openai.com/chat/20759247-b210-45cd-9d3f-188be71a238d#requirements)
-   [Wiring Diagram](https://chat.openai.com/chat/20759247-b210-45cd-9d3f-188be71a238d#wiring-diagram)
-   [Usage](https://chat.openai.com/chat/20759247-b210-45cd-9d3f-188be71a238d#usage)
-   [Contributing](https://chat.openai.com/chat/20759247-b210-45cd-9d3f-188be71a238d#contributing)
-   [License](https://chat.openai.com/chat/20759247-b210-45cd-9d3f-188be71a238d#license)

Requirements
------------

-   SA818 VHF/UHF transceiver module
-   ESP32 microcontroller
-   Micro SD card
-   Push button
-   Micro SD card reader module
-   Breadboard and jumper wires

Wiring Diagram
--------------

makefileCopy code

`TODO: Add wiring diagram`

Usage
-----

1.  Connect the SA818 module to the ESP32 microcontroller according to the wiring diagram.
2.  Connect the push button to the ESP32 microcontroller according to the wiring diagram.
3.  Insert the micro SD card with the CSV file containing the frequency channels into the micro SD card reader module.
4.  Upload the code to the ESP32 microcontroller using the Arduino IDE.
5.  Open the Serial Monitor in the Arduino IDE and set the baud rate to 9600.
6.  Press the push button to switch between the frequency channels.

Contributing
------------

Contributions are welcome! If you find any issues or have any suggestions for improvement, please create a new issue or pull request.

License
-------

This project is licensed under the MIT License - see the [LICENSE](https://chat.openai.com/chat/LICENSE) file for details.
