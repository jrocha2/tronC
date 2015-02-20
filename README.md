# tronC
by John Rocha and Paul Dowling  
CSE 20211 - December 2014  



![Demo](gifs/tronM.gif?raw=true)  

## Project Goal:
Two man project to recreate the classic Tron arcade game using only the C-language and the provided gfx graphics library. Implementing the basic rules of the game seemed too simple, so we challenged ourselves to make a moderately difficult computer player.

## The GFX Library  
The gfx library was created by an instructor and only contains basic functions on the pixel level using X11. The unfortunate inefficency in the gfx library can be seen in the large amounts of code spent drawing lines and the difficulty in making any rounded or aesthetically pleasing menus. Luckily, Tron places more emphasis on the gameplay itself, so we too spent minimal time on the menus, etc. and spent a majority of the time on the gameplay.  

## Running the Program
Use of the X11 libraries vary from system to system and you may need to look into programs such as Xquartz or Xming before you can properly compile the code. 
To compile, simply use the Makefile by using the command `$ make`
Once again, any errors at this point are most likely issues with your installation and use of the X11 library

## Gameplay
#### How to play:
Each player has control of a constantly moving light-cycle represented by neon blocks.  
The light-cycles can only move up, right, left, or down using the following controls:  

1st Player (Blue):  
* w = up   
* a = left   
* d = right    
* s = down      

2nd Player (Yellow):  
* i = up   
* j = left   
* l = right    
* k = down   

Upon movement, each player leaves their trail of light behind them which remains until the end of the game. Along with the boundaries of the window and scoreboard, these walls of light are solid and upon crashing into one, a player will lose.  
#### How to Win:
Survive longer than your opponent.

