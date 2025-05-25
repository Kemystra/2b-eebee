# 2b-eebee
robot go boom boom

## Compiling

For basic compiling:
```cmd
g++ -I abstractRobot/ *.cpp -I upgrades/ *.h -o main.exe
```

As more folder is added, you have to specify multiple `-I <folder_name>` in the compiler command.

## Robot Upgrades
### Base Upgrades :
<ol>
  <li>
    #### Moving Type
    <ul>
      <li>HideBot</li>
      <li>JumpBot</li>
    </ul>
  </li>
  <li>
    #### Shooting Type
    <ul>
      <li>LongShotBot</li>
      <li>SemiAutoBot</li>
      <li>ThirtyShotBot</li>
      <li>LandmineBot</li>
      <li>BombBot</li>
      <li>LaserBot</li>
    </ul>
  </li>
  <li>
    #### Seeing Type
    <ul>
      <li>ScoutBot</li>
      <li>TrackBot</li>
    </ul>
  </li>
</ol>