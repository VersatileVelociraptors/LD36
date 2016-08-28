MXE_HOME=/usr/lib/mxe/
CROSS= $(MXE_HOME)usr/bin/i686-w64-mingw32.static-
CC=g++
CFLAGS=-c -std=c++11 -Wall -O3
BIN_DIR=../bin/
WINDOWS_OUTPUT=win32_build/
LINUX_OUTPUT=linux_build/
OUTPUT = $(BIN_DIR)$(LINUX_OUTPUT)
CPP_FILES := $(shell find -type f -name '*.cpp')
EXEC_FILE= LD36Test
LINK= -o $(OUTPUT)$(EXEC_FILE) -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
MAKE= make -f

export EXEC_FILE
export CPP_FILES


linux:
	$(MAKE) Linux.mak

all: linux win32

win32:
	$(MAKE) Windows.mak


pack: linux win32
	cd $(BIN_DIR); mkdir -p Linux Windows; \
	 cp -r ../assets/ Linux; cp -r ../assets/ Windows; \
	 cp $(LINUX_OUTPUT)$(EXEC_FILE) Linux/; cp $(WINDOWS_OUTPUT)$(EXEC_FILE).exe Windows/; \
	 zip -r $(EXEC_FILE).zip Linux/ Windows/;

.PHONY: clean
clean: clean_linux clean_win32 clean_exec

clean_linux:
	$(MAKE) Linux.mak clean

clean_win32:
	$(MAKE) Windows.mak clean

.PHONY: clean_exec
clean_exec:
	cd $(BIN_DIR); rm -rf Linux/; rm -rf Windows/; rm -f $(EXEC_FILE).zip;

.PHONY: run
run:
	cd ..; ./bin/$(LINUX_OUTPUT)$(EXEC_FILE);

.PHONY: run_win32
run_win32:
	cd ..; wine bin/$(WINDOWS_OUTPUT)$(EXEC_FILE).exe
