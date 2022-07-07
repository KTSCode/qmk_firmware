# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = qmk-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
MOUSEKEY_DELAY = 10 				# Reduce default delay(300) for more responsive mouse buttons
MOUSEKEY_INTERVAL = 1       # Reduce time between movements
MOUSEKEY_MAX_SPEED = 10      # Reduce max speed for better control
MOUSEKEY_TIME_TO_MAX = 0    # Reduce time to max speed for better response
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.

SPLIT_KEYBOARD = yes
LAYOUTS = ortho_5x12 ortho_4x12
