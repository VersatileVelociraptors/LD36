MXE_HOME=/usr/lib/mxe/
CROSS= $(MXE_HOME)usr/bin/i686-w64-mingw32.static-
CC=g++
CFLAGS=-c -std=c++11 -Wall -O3
BIN_DIR=../bin/
WINDOWS_OUTPUT=win32_build/
LINUX_OUTPUT=linux_build/
OUTPUT = $(BIN_DIR)$(LINUX_OUTPUT)
OBJ= main.o
OBJ+= Tile.o Level.o
OBJ+= GameStateManager.o State.o EndState.o MenuState.o PlayState.o
OBJ+= AudioManager.o MusicManager.o SoundManager.o
OBJ+= Entity.o Mob.o Player.o
EXEC_FILE= LD36Test
LINK= -o $(EXEC_FILE) -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all: $(EXEC_FILE)

linux_link:
	cd $(BIN_DIR)$(LINUX_OUTPUT); $(CC) $(OBJ) $(LINK)

pack:
	cd $(BIN_DIR); mkdir -p Linux Windows; \
	 cp -r assets/ Linux; cp -r assets/ Windows; \
	 cp $(LINUX_OUTPUT)$(EXEC_FILE) Linux/; cp $(WINDOWS_OUTPUT)$(EXEC_FILE).exe Windows/; \
	 zip -r $(EXEC_FILE).zip Linux/ Windows/;

win32 : OUTPUT = $(BIN_DIR)$(WINDOWS_OUTPUT)

win32 : CC =$(CROSS)g++

win32 : LD =$(CROSS)ld

win32 : AR =$(CROSS)ar

win32 : PKG_CONFIG =$(CROSS)pkg-config

win32 : CFLAGS+=-D_WIN32

win32 : LINK= -o $(EXEC_FILE).exe -lsfml-main -lsfml-window-s -lsfml-graphics-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lgdi32 -ljpeg -lfreetype -lpng -lbz2 -lharfbuzz -lz -lglib-2.0 -lintl -lws2_32 -liconv -lsndfile -lFLAC -lvorbisfile -lvorbisenc -lvorbis -logg -ldsound -lOpenAL32 -lole32 -lwinmm

win32: $(EXEC_FILE).exe

win32_link:
	cd $(BIN_DIR)$(WINDOWS_OUTPUT); $(CC) $(OBJ) $(LINK)
	
linux_dir:
	mkdir -p $(BIN_DIR)$(LINUX_OUTPUT)

$(EXEC_FILE): linux_dir $(OBJ)
	cd $(BIN_DIR)$(LINUX_OUTPUT); $(CC) $(OBJ) $(LINK)

$(EXEC_FILE).exe: $(OBJ)
	cd $(BIN_DIR)$(WINDOWS_OUTPUT); $(CC) $(OBJ) $(LINK)

main.o:
	$(CC) $(CFLAGS) main.cpp -o $(OUTPUT)$@

Tile.o:
	$(CC) $(CFLAGS) level/Tile.cpp -o $(OUTPUT)$@

Level.o:
	$(CC) $(CFLAGS) level/Level.cpp -o $(OUTPUT)$@

GameStateManager.o:
	$(CC) $(CFLAGS) states/GameStateManager.cpp -o $(OUTPUT)$@

State.o:
	$(CC) $(CFLAGS) states/State.cpp -o $(OUTPUT)$@

EndState.o:
	$(CC) $(CFLAGS) states/EndState.cpp -o $(OUTPUT)$@

MenuState.o:
	$(CC) $(CFLAGS) states/MenuState.cpp -o $(OUTPUT)$@

PlayState.o:
	$(CC) $(CFLAGS) states/PlayState.cpp -o $(OUTPUT)$@

AudioManager.o:
	$(CC) $(CFLAGS) audio/AudioManager.cpp -o $(OUTPUT)$@

MusicManager.o:
	$(CC) $(CFLAGS) audio/MusicManager.cpp -o $(OUTPUT)$@

SoundManager.o:
	$(CC) $(CFLAGS) audio/SoundManager.cpp -o $(OUTPUT)$@
	
Entity.o:
	$(CC) $(CFLAGS) entities/Entity.cpp -o $(OUTPUT)$@
	
Mob.o:
	$(CC) $(CFLAGS) entities/Mob.cpp -o $(OUTPUT)$@
	
Player.o:
	$(CC) $(CFLAGS) entities/Player.cpp -o $(OUTPUT)$@

.PHONY: clean_all
clean_all: clean clean_win32 clean_exec

.PHONY: clean
clean:
	cd $(BIN_DIR)$(LINUX_OUTPUT);	rm -f $(OBJ) $(EXEC_FILE)

.PHONY: clean_win32
clean_win32:
	cd $(BIN_DIR)$(WINDOWS_OUTPUT); rm -f $(OBJ) $(EXEC_FILE).exe

.PHONY: clean_exec
clean_exec:
	cd $(BIN_DIR); rm -rf Linux/; rm -rf Windows/;

.PHONY: run
run:
	cd ..; ./bin/$(LINUX_OUTPUT)$(EXEC_FILE);

.PHONY: run_win32
run_win32:
	cd ..; wine bin/$(WINDOWS_OUTPUT)$(EXEC_FILE).exe
