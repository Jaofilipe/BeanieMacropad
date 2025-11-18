# Beanie Macropad
QMK-based Macropad project whith support for VIA & VIAL

<img src="media/Beanies.jpg" alt="Image of Microcontroller" width="400"/>

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
- 3D Printed Case
  
<p align="center">
<img src="media/micro.jpg" alt="Image of Microcontroller" height="200"/>
<img src="media/oled.jpg" alt="Image of OLED" height="200"/>
<img src="media/Assembled.jpg" alt="Image of assembled Macropad" height="200"/>
</p>

---

# Quick start
Familiarity with QMK is advised.
Usage of QMK CLI tool is highly recommended for new users as it installs flashing tools for the Microcontrollers.<br>
See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools)<br>
And the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with the [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).<br>

## Firstly: [QMK](https://qmk.fm/) & [VIA](https://www.caniusevia.com/)
For simple [QMK](https://qmk.fm/) Macropad (where keycodes cannot be changed unless you change them in the code and flash a new firmware);  
Or just [VIA](https://www.caniusevia.com/) compatibility (here you can use the default keycodes or change them using the VIA online tool);  
First [install qmk CLI](https://docs.qmk.fm/#/getting_started_build_tools).<br>
Then copy the [beanie folder](beanie) into the keyboards folder on the QMK repo clone location.<br>
For how to build and flash see the Macropad README notes: [keyboards/beanie/readme.md](beanie/readme.md) or the [CLI Flashing on the Website ](https://docs.qmk.fm/newbs_flashing#flash-your-keyboard-from-the-command-line)<br>

## Secondly: [VIAL](https://get.vial.today/)
For [VIAL](https://get.vial.today/) compatibility (you have similar functionality as to VIA, however there is also an offline software to change keycodes);  
Although it comes with the drawback of a higher memory footprint, I personally prefer using VIAL due to the offline editor. <br>
To be able to compile and flash VIAL you need first to [install qmk CLI](https://docs.qmk.fm/#/getting_started_build_tools).<br>
Then clone [vial-qmk repo](https://github.com/vial-kb/vial-qmk) and copy the [beanie folder](beanie) into the repo keyboards folder.<br>
Finally follow the build guidelines in [VIAL Webpage](https://get.vial.today/docs/porting-to-vial.html)<br>
The VIAL Macropad JSON file is provided in folder VIAL.<br>

 
