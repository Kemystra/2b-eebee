# OOPS assignment

## Tasks

1. Printing shit to console  
2. Generic Robot \+ Environment  
3. Parsing input file  
4. Upgrades  
   1. Moving  
      1. HideBot  
      2. JumpBot  
   2. Shooting  
      1. LongShotBot  
      2. ThirtyShotBot  
      3. SemiAutoBot  
   3. Seeing  
      1. ScoutBot  
      2. TrackBot

Task division

Izzmin: GenericRobot (non-upgraded action)  
Jex: Logging \+ respawn queue when ded  
Mikael: Grid map printing \+ action printing \+ call upgrade function when kill  
Hui Yee: Parse input file

## Overall architecture

Trying to make this thing cross-platform, but not using platform macros (cuz if he asked us on that, we’re cooked).

### Robot shit

The Robot class inherited by ThinkingRobot, ShootingRobot, etc.  
GenericRobot inherits from ThinkingRobot, ShootingRobot, etc.

Upgrades are already “implemented” in GenericRobot, but not activated. Only when the robot is allowed to upgrade then it will be activated.

Upgrade variables must be placed in the Robot class with private access. Add public getter methods to get these variables for generic GenericRobot. There should be a setter function so that upgrade variables can be manipulated when it needs to be upgraded.

To show on screen, Robot will have a pure virtual getSymbol() function, to be implemented in GenericRobot. This will return the symbol for this robot. Ensure to also change the symbol after each upgrade.

### Environment

Responsible for giving look() data to robots (have an accessor method here).

Have a queue where dead robots can enter so that they can respawn (limited to 3 times).

### Console UI

A map grid to show the whole map \+ position of each robot  
Robots are represented as a single capital letter.  
Show cardinal direction on the map  
List out latest actions by the current robot besides the map grid

### Input file parsing

Create a new class for this. (ParameterFileReader or something)  
Read the file and get the necessary parameters  
Ensure that the class can process the parameters in any order (so even if the parameter is not in correct order, it can still process. Important if we want to add more custom parameters later).

Return a struct containing the parameters (InitialParameter or something)

### Logging

Prepare a Logger class to write into a log text file.