# Beanie Macropad
QMK-based Macropad project whith support for VIA & VIAL

A small 10-key macropad (4x3 matrix) with a 0.96" SSD1306 I2C OLED.  
This repository contains the hardware files and instructions to build, compile and flash the Beanie firmware using QMK.


## Features
- 4x3 switch matrix (10 keys)
- Supports simple QMK, VIA & VIAL
- SSD1306 128×64 I2C OLED display
- Pro Micro (ATmega32U4) with Caterina bootloader


## Hardware
- Controller: Pro Micro (ATmega32U4)
- Display: SSD1306 128×64 Mono (I2C)
- Switches: Outemo Browns
- Miscellaneous parts: diodes, wires
- Case: 3D Printed


# Quick start
Familiarity with QMK is advised.
Usage of QMK CLI tool is highly recommended for new users as it installs flashing tools for the Microcontrollers.
See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools)
And the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with the [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Firstly: QMK & VIA
For simple QMK Macropad or just VIA compatibility, first [install qmk CLI](https://docs.qmk.fm/#/getting_started_build_tools).
Then copy the [beanie folder](beanie) into the keyboards folder on the QMK repo clone location.
For how to build and flash see the Macropad README notes: [keyboards/beanie/readme.md](beanie/readme.md) or the [CLI Flashing on the Website ](https://docs.qmk.fm/newbs_flashing#flash-your-keyboard-from-the-command-line)

## Secondly: VIAL
Although it comes with the drawback of a higher memory footprint, I personally prefer using VIAL due to the offline editor. 
To be able to compile and flash VIAL you need first to [install qmk CLI](https://docs.qmk.fm/#/getting_started_build_tools).
Then clone [vial-qmk repo](https://github.com/vial-kb/vial-qmk) and copy the [beanie folder](beanie) into the repo keyboards folder.
Finally follow the build guidelines in [VIAL Webpage](https://get.vial.today/docs/porting-to-vial.html)
The VIAL Macropad JSON file is provided in folder VIAL.

 