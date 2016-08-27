MXE_HOME=/usr/lib/mxe/
CROSS= $(MXE_HOME)usr/bin/i686-w64-mingw32.static-
CC= $(CROSS)g++
LD= $(CROSS)ld
AR= $(CROSS)ar
PKG_CONFIG= $(CROSS)pkg-config
CFLAGS=-c -std=c++11 -Wall -O3 -D_WIN32
BIN_DIR=../bin/
WINDOWS_OUTPUT=win32_build/
OUTPUT = $(BIN_DIR)$(WINDOWS_OUTPUT)
OBJ := $(addprefix $(OUTPUT),$(notdir $(CPP_FILES:.cpp=.o)))
LINK= -o $(OUTPUT)$(EXEC_FILE).exe -lsfml-main -lsfml-window-s -lsfml-graphics-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lgdi32 -ljpeg -lfreetype -lpng -lbz2 -lharfbuzz -lz -lglib-2.0 -lintl -lws2_32 -liconv -lsndfile -lFLAC -lvorbisfile -lvorbisenc -lvorbis -logg -ldsound -lOpenAL32 -lole32 -lwinmm 

all: $(OUTPUT)$(EXEC_FILE).exe

win32_dir:
	mkdir -p $(BIN_DIR)$(WINDOWS_OUTPUT)

$(OUTPUT)$(EXEC_FILE).exe: win32_dir $(OBJ)
	$(CC) $(OBJ) $(LINK)

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

.PHONY: clean
clean:
	rm -rf $(OUTPUT);