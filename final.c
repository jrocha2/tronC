// John Rocha and Paul Dowling
// Final Project


#include <stdio.h>
#include "gfx3.h"
#include "finalfunc.h"

int main() {
	int isWall[100][100] = {{0}}, gameover = 0, x1 = 50, y1 = 15, x2 = 50, y2 = 85,  player_num = 0, difficulty = 0;
	int xmenu, ymenu, p1_score = 0, p2_score = 0;
	char mander, direction1 = 'd', move, direction2 = 'j';

	gfx_open(500,600, "TRON");

	while(player_num == 0) {        // Displays menu until option chosen
		display_menu();
		mander = gfx_wait();
		if(mander == 1){
			xmenu = gfx_xpos();
			ymenu = gfx_ypos();
			if( xmenu >= 50 && xmenu <= 150 && ymenu >= 400 && ymenu <= 450)        // represent coordinates of choice boxes
				player_num = 1;
			else if( xmenu >= 350 && xmenu <= 450 && ymenu >= 400 && ymenu <= 450)
				player_num = 2;
		}
	}

	gfx_clear();        // Clear Initial Menu

	// Game starts 1 player
	if(player_num == 1) {
		difficulty = difficulty_menu(mander,difficulty);
		mander = ' ';
		
		while(mander != 'q'){           // This initializes board at beginning of games
			if(mander == ' '){
			gfx_clear();
			clear_board(isWall);
			gameover = 0;
			move = 'd';
			x1 = 50;
			y1 = 15;
			x2 = 50;
                        direction1 ='d';
                        direction2 = 'j';
			y2 = 85;
			startBoard(x1,y1,x2,y2, p1_score, p2_score,player_num);
			while(!gameover) {

				if (gfx_event_waiting())        // allows program to keep running
					move = gfx_wait();

				if (validMove(direction1, move))        // makes sure move is for player alone
                                    if(direction1 == 'w' || direction1 == 'a' || direction1 == 's' || direction1 == 'd')
					direction1 = move;

				switch (direction1) {
					case 'w':
                                                gfx_color(0,191,255);   // color of player
						moveUp(x1,y1,isWall);   // moves player up one square, also updates isWall
						if (isWall[x1-1][y1] || x1-1 < 0){      // checks that player hasn't crashed
                                                    p2_score++;                         // p2 wins if p1 crashed
						    gameover = 1;                       
                                                }
						else
							x1--;           // if game didn't end, their coordinates successfully updated
						break;
					case 'a':
                                                gfx_color(0,191,255);
						moveLeft(x1,y1,isWall);
						if (isWall[x1][y1-1] || y1-1 < 0){
                                                    p2_score++;
					            gameover = 1;
                                                }
						else
							y1--;
						break;
					case 's':
                                                gfx_color(0,191,255);
						moveDown(x1,y1,isWall);
						if (isWall[x1+1][y1] || x1+1 >  99){
                                                    p2_score++;
						    gameover = 1;
                                                }
						else
							x1++;
						break;
					case 'd':
                                                gfx_color(0,191,255);
						moveRight(x1,y1,isWall);
						if (isWall[x1][y1+1] || y1+1 > 99){
                                                    p2_score++;
						    gameover = 1;
                                                }
						else
							y1++;
						break;
				}

	        		if(difficulty == 1)     // EASY
                                    direction2 = getFarthestMove(x1,y1,x2,y2,direction2,isWall);        
                                else                    // HARD
                                    direction2 = findSpace(x2,y2,direction2,isWall);

                                switch (direction2) {
		    			case 'i':
                                                gfx_color(243,243,21);  // color of computer 
                                                moveUp(x2,y2,isWall);   // sends computer coordinates to move function
    						if (isWall[x2-1][y2] || x2-1 < 0){
                                                    p1_score++;         // if computer dies, p1 wins
                                                    gameover = 2;
                                                }    
                                                else
                                                    x2--;
                                                break;
                                        case 'j':
                                                gfx_color(243,243,21);
                                                moveLeft(x2,y2,isWall);
                                                if (isWall[x2][y2-1] || y2-1 < 0){
                                                    p1_score++;
                                                    gameover = 2;
                                                }
                                                else
                                                    y2--;
                                                break;
                                        case 'k':
                                                gfx_color(243,243,21);
                                                moveDown(x2,y2,isWall);
                                                if (isWall[x2+1][y2] || x2+1 >  99){
                                                    p1_score++;
                                                    gameover = 2;
                                                }
                                                else
                                                    x2++;
                                                break;
                                        case 'l':
                                                gfx_color(243,243,21);
                                                moveRight(x2,y2,isWall);
                                                if (isWall[x2][y2+1] || y2+1 > 99){
                                                    p1_score++;
                                                    gameover = 2;
                                                }
                                                else
                                                    y2++;
                                                break;
                                }
                                if(is_tie(x1,y1,x2,y2)) // checks that heads didn't hit each other
                                        gameover = 3;
				gfx_flush();
				usleep(50000);

			}
                        gfx_clear();
			end_menu_p1(gameover, p1_score, p2_score);      // gameover == True so display menu
                        scoreboard_p1(p1_score, p2_score);              // still show scoreboard
                        }
                        
                    mander = gfx_wait();        // waits of space to play again or q to quit as seen at top

			
		}

		// Game Starts 2 Players
	}else{
		mander = ' ';
		while(mander != 'q'){
			if(mander == ' '){ 
				clear_board(isWall);
				x1 = 50;
				y1 = 15;
				x2 = 50;
				y2 = 85;
				gameover = 0;
				move = 'd';
				direction1 = 'd';
				direction2 = 'j';
				startBoard(x1,y1,x2,y2, p1_score, p2_score, player_num);
				while(!gameover) {

					if (gfx_event_waiting())        // takes inputs for both players
						move = gfx_wait();

					if (validMove(direction1, move) && validMove(direction2,move)) {
						if (move == 'w' || move == 'a' || move == 's' || move == 'd')   // checks that it is valid and applies to correct player
							direction1 = move;
						else if(move == 'i' || move == 'j' || move == 'k' || move == 'l')
							direction2 = move;
					}

					switch (direction1) {   // Player 1's cases same as above
						case 'w':
						gfx_color(0,191,255);
							moveUp(x1,y1,isWall);
							if (isWall[x1-1][y1] || x1-1 < 0){
								gameover = 1;
								p2_score++;
							}
							else
								x1--;
							break;
						case 'a':
						gfx_color(0,191,255);
							moveLeft(x1,y1,isWall);
							if (isWall[x1][y1-1] || y1-1 < 0){
								gameover = 1;
								p2_score++;
							}
							else
								y1--;
							break;
						case 's':
						gfx_color(0,191,255);
							moveDown(x1,y1,isWall);
							if (isWall[x1+1][y1] || x1+1 >  99){
  								gameover = 1;
								p2_score++;
							}
							else
								x1++;
							break;
						case 'd':
						gfx_color(0,191,255);
							moveRight(x1,y1,isWall);
							if (isWall[x1][y1+1] || y1+1 > 99){
								gameover = 1;
								p2_score++;
							}
							else
								y1++;
							break;
					}
					switch (direction2) {   // Player 2's cases same as above
						
						case 'i':
						gfx_color(243,243,21);
							moveUp(x2,y2,isWall);
							if (isWall[x2-1][y2] || x2-1 < 0){
								gameover = 2;
								p1_score++;
							}
							else
								x2--;
							break;
						case 'j':
						gfx_color(243,243,21);
							moveLeft(x2,y2,isWall);
							if (isWall[x2][y2-1] || y2-1 < 0){
								gameover = 2;
								p1_score++;
							}
							else
								y2--;
							break;
						case 'k':
						gfx_color(243,243,21);
							moveDown(x2,y2,isWall);
							if (isWall[x2+1][y2] || x2+1 >  99){
								gameover = 2;
								p1_score++;
							}
							else
								x2++;
							break;
						case 'l':
						gfx_color(243,243,21);
							moveRight(x2,y2,isWall);
							if (isWall[x2][y2+1] || y2+1 > 99){
								gameover = 2;
								p1_score++;
							}
							else
								y2++;
							break;

					}
					if (is_tie(x1,y1,x2,y2))
						gameover = 3;
					
					gfx_flush();
					usleep(50000);
				}
				gfx_clear();				
				end_menu_p2(gameover, p1_score, p2_score);      // updated menus that display player 2 instead of "computer"
				scoreboard_p2(p1_score, p2_score);
                        }
                        mander = gfx_wait();
			
		}
	}
}
