# List of all the board related files.
BOARDSRC = $(BOARD_PATH)/boards/1BITSY_STM32_F415/board.c

# Required include directories
BOARDINC = $(BOARD_PATH)/boards/1BITSY_STM32_F415

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
