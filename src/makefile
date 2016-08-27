MXE_HOME=/usr/lib/mxe/
CROSS= $(MXE_HOME)usr/bin/i686-w64-mingw32.static-
CC=g++
CFLAGS=-c -std=c++11 -Wall -O3
BIN_DIR=../bin/
WINDOWS_OUTPUT=win32_build/
LINUX_OUTPUT=linux_build/
OUTPUT = $(BIN_DIR)$(LINUX_OUTPUT)
CPP_FILES := $(shell find -type f -name '*.cpp')
#OBJ= $(OUTPUT)main.o
#OBJ+= $(OUTPUT)Tile.o $(OUTPUT)Level.o
#OBJ+= $(OUTPUT)GameStateManager.o $(OUTPUT)State.o $(OUTPUT)EndState.o $(OUTPUT)MenuState.o $(OUTPUT)PlayState.o
#OBJ+= $(OUTPUT)AudioManager.o $(OUTPUT)MusicManager.o $(OUTPUT)SoundManager.o
#OBJ+= $(OUTPUT)Entity.o $(OUTPUT)Mob.o $(OUTPUT)Player.o
EXEC_FILE= LD36Test
LINK= -o $(OUTPUT)$(EXEC_FILE) -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
MAKE= make -f

export EXEC_FILE
export CPP_FILES

all: linux win32

linux:
	$(MAKE) Linux.mak

win32:
	$(MAKE) Windows.mak

.PHONY: clean_all
clean_all: clean clean_win32 clean_exec

.PHONY: clean
clean: clean_linux clean_win32

clean_linux:
	$(MAKE) Linux.mak clean

clean_win32:
	$(MAKE) Windows.mak clean

.PHONY: clean_exec
clean_exec:
	cd $(BIN_DIR); rm -rf Linux/; rm -rf Windows/;

.PHONY: run
run:
	cd ..; ./bin/$(LINUX_OUTPUT)$(EXEC_FILE);

.PHONY: run_win32
run_win32:
	cd ..; wine bin/$(WINDOWS_OUTPUT)$(EXEC_FILE).exe
