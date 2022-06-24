# my_Sokoban
Epitech 1st year project

Sokoban (warehouse keeper in Japanese) is a type of transport puzzle, in which the player pushes boxes or crates around in a warehouse, trying to get them to storage locations. The puzzle is usually implemented as a video game. Sokoban was created in 1981 by Hiroyuki Imabayashi, and published in 1982 by Thinking Rabbit, a software house based in Takarazuka, Japan.

The game is played on a board of squares, where each square is a floor or a wall. Some floor squares contain boxes, and some floor squares are marked as storage locations. The player is confined to the board, and may move horizontally or vertically onto empty squares (never through walls or boxes).
The player can also move into a box, which pushes it into the square beyond. Boxes may not be pushed into other boxes or walls, and they cannot be pulled. The puzzle is solved when all boxes are at storage locations.

This project is a copy of the real game in terminal mode, using the ncurses library.

**RUN**

./my_sokoban map.txt

**MAP**

SPACE: ground  
#: wall  
X: box  
O: storage  
P: player

Example of a valid map:

<img width="90" alt="Capture d’écran 2022-06-23 à 23 26 09" src="https://user-images.githubusercontent.com/72014821/175405196-6384e32a-68ba-416b-a2bf-45c900de4265.png">

A valid map can only contains the characters: SPACE, '\n', '#', 'X', 'O', 'P'.

**AUTHORIZED FUNCTIONS**

Every functions of *ncurses*.

malloc, free, exit  
(f)open, (f)close, (f)read, (f)write  
getline, ioctl, usleep, sigaction, signal  
stat, lstat, fstat  

**KEYBINDS**

Reset the game: SPACE_BAR  
Move the player: LEFT, RIGHT, UP, DOWN
