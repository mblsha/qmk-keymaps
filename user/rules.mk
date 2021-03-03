STENO_ENABLE = no
COMMAND_ENABLE  = no   # Disable shift combination, which conflicts with shift-parens
CONSOLE_ENABLE  = no   # required to make printf work
MIDI_ENABLE     = no
TAP_DANCE_ENABLE = yes

# mblsha: Maybe this will fix the USB_USB not working and requiring a re-plug
# every now and then.
NO_USB_STARTUP_CHECK = yes # Disables usb suspend check after keyboard startup

SRC += my.c
SRC += my_tapdance.c

# SRC += my_leader.c
# SRC += my_leader_dictionary.c

ifneq ("$(wildcard $(USER_PATH)/private.h)", "")
  OPT_DEFS += -DPRIVATE_MACROS
endif

# EXTRAKEY_ENABLE = yes # Used for audio control and system control keys
# COMBO_ENABLE = yes # Used to allow chording of keys to trigger an action
LTO_ENABLE = yes # Reduces the compiled firmware size
