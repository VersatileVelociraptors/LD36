MXE_HOME=/usr/lib/mxe/
CROSS= $(MXE_HOME)usr/bin/i686-w64-mingw32.static-
CC=g++
CFLAGS=-c -std=c++11 -Wall -O3
BIN_DIR=../bin/
WINDOWS_OUTPUT=win32_build/
LINUX_OUTPUT=linux_build/
OUTPUT = $(BIN_DIR)$(LINUX_OUTPUT)
OBJ= $(OUTPUT)main.o
OBJ+= $(OUTPUT)Tile.o $(OUTPUT)Level.o
OBJ+= $(OUTPUT)GameStateManager.o $(OUTPUT)State.o $(OUTPUT)EndState.o $(OUTPUT)MenuState.o $(OUTPUT)PlayState.o
OBJ+= $(OUTPUT)AudioManager.o $(OUTPUT)MusicManager.o $(OUTPUT)SoundManager.o
OBJ+= $(OUTPUT)Entity.o $(OUTPUT)Mob.o $(OUTPUT)Player.o
EXEC_FILE= LD36Test
LINK= -o $(OUTPUT)$(EXEC_FILE) -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all: $(BIN_DIR)$(LINUX_OUTPUT)$(EXEC_FILE)

linux_link:
	$(CC) $(OBJ) $(LINK)

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

$(OUTPUT)$(EXEC_FILE): linux_dir $(OBJ)
	$(CC) $(OBJ) $(LINK)

$(EXEC_FILE).exe: $(OBJ)
	cd $(BIN_DIR)$(WINDOWS_OUTPUT); $(CC) $(OBJ) $(LINK)

$(OUTPUT)main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o $@

$(OUTPUT)Tile.o: level/Tile.cpp
	$(CC) $(CFLAGS) level/Tile.cpp -o$@

$(OUTPUT)Level.o: level/Level.cpp
	$(CC) $(CFLAGS) level/Level.cpp -o $@

$(OUTPUT)GameStateManager.o: states/GameStateManager.cpp
	$(CC) $(CFLAGS) states/GameStateManager.cpp -o $@

$(OUTPUT)State.o: states/State.cpp
	$(CC) $(CFLAGS) states/State.cpp -o $@

$(OUTPUT)EndState.o: states/EndState.cpp
	$(CC) $(CFLAGS) states/EndState.cpp -o $@

$(OUTPUT)MenuState.o: states/MenuState.cpp
	$(CC) $(CFLAGS) states/MenuState.cpp -o $@

$(OUTPUT)PlayState.o: states/PlayState.cpp
	$(CC) $(CFLAGS) states/PlayState.cpp -o $@

$(OUTPUT)AudioManager.o: audio/AudioManager.cpp
	$(CC) $(CFLAGS) audio/AudioManager.cpp -o $@

$(OUTPUT)MusicManager.o: audio/MusicManager.cpp
	$(CC) $(CFLAGS) audio/MusicManager.cpp -o $@

$(OUTPUT)SoundManager.o: audio/SoundManager.cpp
	$(CC) $(CFLAGS) audio/SoundManager.cpp -o $@
	
$(OUTPUT)Entity.o: entities/Entity.cpp
	$(CC) $(CFLAGS) entities/Entity.cpp -o $@
	
$(OUTPUT)Mob.o: entities/Mob.cpp
	$(CC) $(CFLAGS) entities/Mob.cpp -o $@
	
$(OUTPUT)Player.o: entities/Player.cpp
	$(CC) $(CFLAGS) entities/Player.cpp -o $@

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
