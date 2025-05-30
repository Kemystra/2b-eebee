.DEFAULT_GOAL := main.out
.PHONY: main.out

BUILD_FOLDER := build

SOURCES := $(wildcard *.cpp upgrades/*.cpp)
# For each name in SOURCES (notdir removes the folder name, basename removes the file extension), append .o
OBJECTS := $(foreach x, $(basename $(notdir $(SOURCES))), $(BUILD_FOLDER)/$(x).o)

LIBS := abstractRobot/ upgrades/

FLAGS := -std=c++11 -g


$(BUILD_FOLDER)/%.o: %.cpp
	g++ $(FLAGS) $< -c -o $@

$(BUILD_FOLDER)/%.o: upgrades/%.cpp
	g++ $(FLAGS) $< -c -o $@

main.out: $(OBJECTS)
	g++ $(FLAGS) $(foreach x, $(LIBS), -I $x) $(OBJECTS) -o main.out

# @ before a command to not print the command itself
debug:
	@echo $(LIBS)
	@echo $(SOURCES)
	@echo $(OBJECTS)

$(BUILD_FOLDER):
	mkdir $(BUILD_FOLDER)
