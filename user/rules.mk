STENO_ENABLE = no
COMMAND_ENABLE  = no   # Disable shift combination, which conflicts with shift-parens
CONSOLE_ENABLE  = no
MIDI_ENABLE     = no
TAP_DANCE_ENABLE = yes

SRC += my.c
SRC += my_tapdance.c

# SRC += my_leader.c
# SRC += my_leader_dictionary.c

ifneq ("$(wildcard $(USER_PATH)/private.h)", "")
  OPT_DEFS += -DPRIVATE_MACROS
endif
