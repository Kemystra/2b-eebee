.DEFAULT_GOAL := main.out

SOURCES := $(wildcard *.cpp upgrades/*.cpp)

BUILD_FOLDER := build

# For each name in SOURCES (notdir removes the folder name, basename removes the file extension), append .o
OBJECTS := $(foreach x, $(basename $(notdir $(SOURCES))), $(BUILD_FOLDER)/$(x).o)

LIBS := abstractRobot/ upgrades/


%.cpp: %.o
	g++ -Wall -std=c++11 $< -c -o $@

main.out: $(OBJECTS)
	g++ -Wall $(foreach x, $(LIBS), -I $x) $(OBJECTS) -o main.out

# @ before a command to not print the command itself
debug:
	@echo $(SOURCES)
	@echo $(OBJECTS)

$(BUILD_FOLDER):
	mkdir $(BUILD_FOLDER)
