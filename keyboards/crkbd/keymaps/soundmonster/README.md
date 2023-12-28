# A 3x5 layout for the Corne keyboard

### Features

* Modern OLED support (many thanks to @drashna):
  * Proper orientation
  * Graphic layer indicator ↑ ↓
  * Graphic modifier indicator ⌘ ⇧ ⌥  ⌃
* Home-row modifiers, heavily inspired by [Miryoku](https://github.com/manna-harbour/miryoku/blob/master/README.org)
* VIm friendly, Mac friendly
* Full per-key RGB Matrix support out of the box (you still have to go through the nightmare of soldering yourself though 😉)

### Build instructions

* `make crkbd:soundmonster:dfu` to build and flash the left half
* `make crkbd:soundmonster:dfu RGB_MATRIX_SPLIT_RIGHT=yes` to build and flash the right half
* This keymap uses `EE_HANDS` to assign the handedness of the left and right side of the keyboard.
  This allows to plug the USB cable into any half without mirroring the keymap.
  Flash the appropriate flags to each half with `make crkbd:soundmonster:dfu-split-left` and `make crkbd:soundmonster:dfu-split-right` respectively.
* This keymap expects a DFU bootloader on the ProMicros in your Corne. While DFU is supposedly better, you may just as well stick to the Catarina bootloader that is installed on most promicros by default: change the `BOOTLADER` setting to `catarina` in `rules.mk`.
  * The Elite-C controllers run DFU by default

### Flashing the bootloader

* Get an ISP, e.g. another ProMicro
* Follow the [QMK docs on ISP flashing](https://docs.qmk.fm/#/isp_flashing_guide?id=isp-flashing-guide) for details on how to wire up the ISP to your controller
* `make crkbd:soundmonster:production`
* `avrdude -c avrisp -P /dev/tty.usbmodem123451 -p atmega32u4 -U flash:w:crkbd_rev1_legacy_soundmonster_bootloader.hex:i -U lfuse:w:0x5E:m -U hfuse:w:0x99:m -U efuse:w:0xC3:m`
