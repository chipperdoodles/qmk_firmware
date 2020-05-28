# List of all the board related files.
BOARDSRC = $(BOARD_PATH)/boards/STM_32_F405/board.c

# Required include directories
BOARDINC = $(BOARD_PATH)/boards/STM_32_F405

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
