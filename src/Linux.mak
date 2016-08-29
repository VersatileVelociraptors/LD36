CC=g++
CFLAGS=-g -c -std=c++11 -Wall -O3
BIN_DIR=../bin/
LINUX_OUTPUT=linux_build/
OUTPUT = $(BIN_DIR)$(LINUX_OUTPUT)
OBJ := $(addprefix $(OUTPUT),$(notdir $(CPP_FILES:.cpp=.o)))
LINK= -o $(OUTPUT)$(EXEC_FILE) -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all: $(BIN_DIR)$(LINUX_OUTPUT)$(EXEC_FILE)

linux_link:
	$(CC) $(OBJ) $(LINK)

linux_dir:
	mkdir -p $(BIN_DIR)$(LINUX_OUTPUT)

$(OUTPUT)$(EXEC_FILE): linux_dir $(OBJ)
	$(CC) $(OBJ) $(LINK)

$(OUTPUT)main.o: main.cpp
	$(CC) $(CFLAGS) $< -o $@

$(OUTPUT)Tile.o: level/Tile.cpp
	$(CC) $(CFLAGS) $< -o$@

$(OUTPUT)Level.o: level/Level.cpp
	$(CC) $(CFLAGS) $< -o $@

$(OUTPUT)GameStateManager.o: states/GameStateManager.cpp
	$(CC) $(CFLAGS) $< -o $@

$(OUTPUT)State.o: states/State.cpp
	$(CC) $(CFLAGS) $< -o $@

$(OUTPUT)EndState.o: states/EndState.cpp
	$(CC) $(CFLAGS) $< -o $@

$(OUTPUT)MenuState.o: states/MenuState.cpp
	$(CC) $(CFLAGS) $< -o $@

$(OUTPUT)PlayState.o: states/PlayState.cpp
	$(CC) $(CFLAGS) $< -o $@

$(OUTPUT)AudioManager.o: audio/AudioManager.cpp
	$(CC) $(CFLAGS) $< -o $@

$(OUTPUT)MusicManager.o: audio/MusicManager.cpp
	$(CC) $(CFLAGS) $< -o $@

$(OUTPUT)SoundManager.o: audio/SoundManager.cpp
	$(CC) $(CFLAGS) $< -o $@
	
$(OUTPUT)Entity.o: entities/Entity.cpp
	$(CC) $(CFLAGS) $< -o $@
	
$(OUTPUT)Mob.o: entities/Mob.cpp
	$(CC) $(CFLAGS) $< -o $@
	
$(OUTPUT)Player.o: entities/Player.cpp
	$(CC) $(CFLAGS) $< -o $@

$(OUTPUT)Button.o: ui/Button.cpp
	$(CC) $(CFLAGS) $< -o $@

$(OUTPUT)StartButton.o: ui/StartButton.cpp
	$(CC) $(CFLAGS) $< -o $@

$(OUTPUT)ExitButton.o: ui/ExitButton.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf $(OUTPUT);
