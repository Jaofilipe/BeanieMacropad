# Beanie

![beanie](imgur.com image)

*A small 10-key macropad ( 4x3 matrix ) with 0.96" OLED Display.*

* Keyboard Maintainer: [Joao Filipe](https://github.com/Jaofilipe)
* Hardware Supported: 
    -Board: Pro Micro (ATmega32U4) ( Purple Board )
    -OLED Display: SSD1306 128×64 Mono 0.96" I2C 
* Hardware Availability: Online hobby/electronics websites, ebay, aliexpress, etc.
* Repository path: keyboards/beanie

Make example for this keyboard (after setting up your build environment):

    make beanie:default

Flashing example for this keyboard:

    make beanie:default:flash

# Compiling

Before flashing the macropad make sure all code is correct by compiling it.

**For Default Macropad (no VIA / VIAL):**
- qmk flash -kb beanie -km default
**For VIA Macropad:**
- qmk flash -kb beanie -km via

# Flashing

**Common Flashing methods:**

Use qmk CLI:
- qmk flash -kb beanie -km default
Use QMK Toolbox:
- Use QMK Toolbox to flash a compiled .hex/.uf2 if you prefer a GUI tool.

Either way you choose to flash, you need to enter bootloader mode:
- On Pro Micro boards with Caterina: press the reset button on the board (or short the reset pads) to enter the bootloader.
- Bootmagic and other reset methods are optionally supported depending on keyboard.json and keymap settings.

**Example:**
1. Compile: qmk compile -kb beanie -km default
2. Flash: qmk flash -kb beanie -km default
Or: 
2. Open QMK Toolbox and load the .hex file, then flash while device is in bootloader mode.

Windows specific
- If drivers are required for your Pro Micro, install appropriate USB drivers or use Zadig for special cases. In most cases the ATmega32U4 enumerates as a COM device automatically.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with the [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader & Recovery

**Supported bootloader**: caterina (typical for Pro Micro / ATmega32U4)

**Enter Bootloader:**
* **Bootmagic reset**: Hold down the Top Right key (2,3) in the matrix and plug in the keyboard
* **Physical reset button**: The case was designed with a hole over RESET Pin - insert grounded metal clip or needle to reset.
**Reset Via / Vial Configurations**
* **Bootmagic EEPROM reset**: Hold down the Top Right key at (2,3) and the Bottom Left (0,0) in the matrix and plug in the keyboard

## Useful Info

Pins layout as in [Pro Micro Pinout](https://imgur.com/wMNx2u6)