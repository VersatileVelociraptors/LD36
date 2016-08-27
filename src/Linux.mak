CC=g++
CFLAGS=-c -std=c++11 -Wall -O3
BIN_DIR=../bin/
LINUX_OUTPUT=linux_build/
OUTPUT = $(BIN_DIR)$(LINUX_OUTPUT)
OBJ := $(addprefix $(OUTPUT),$(notdir $(CPP_FILES:.cpp=.o)))
#OBJ= $(OUTPUT)main.o
#OBJ+= $(OUTPUT)Tile.o $(OUTPUT)Level.o
#OBJ+= $(OUTPUT)GameStateManager.o $(OUTPUT)State.o $(OUTPUT)EndState.o $(OUTPUT)MenuState.o $(OUTPUT)PlayState.o
#OBJ+= $(OUTPUT)AudioManager.o $(OUTPUT)MusicManager.o $(OUTPUT)SoundManager.o
#OBJ+= $(OUTPUT)Entity.o $(OUTPUT)Mob.o $(OUTPUT)Player.o
LINK= -o $(OUTPUT)$(EXEC_FILE) -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all: $(BIN_DIR)$(LINUX_OUTPUT)$(EXEC_FILE)

linux_link:
	$(CC) $(OBJ) $(LINK)

linux_dir:
	mkdir -p $(BIN_DIR)$(LINUX_OUTPUT)

$(OUTPUT)$(EXEC_FILE): linux_dir $(OBJ)
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