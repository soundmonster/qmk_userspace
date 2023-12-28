BOOTLOADER = qmk-dfu

RGBLIGHT_ENABLE    = no
RGB_MATRIX_ENABLE  = yes
RGB_MATRIX_DRIVER  = ws2812
MOUSEKEY_ENABLE    = no
NKRO_ENABLE        = yes
OLED_ENABLE        = yes
OLED_DRIVER        = ssd1306
LTO_ENABLE         = yes
COMBO_ENABLE       = yes
# CONSOLE_ENABLE     = yes

SRC += features/achordion.c
