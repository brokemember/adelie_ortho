# MCU name
MCU = atmega32u2

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp

TAP_DANCE_ENABLE = yes

BOOTLOADER = atmel-dfu

NKRO_ENABLE 		= yes
EXTRAKEY_ENABLE     = yes

