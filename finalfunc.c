// John Rocha and Paul Dowling
// Functions 

#include <stdio.h>
#include <math.h>
#include "gfx3.h"
#include "finalfunc.h"


int validMove(char direction, char move) {
	switch(direction) {                     // Checks that moves don't go back on themselves
		case 'w':                       // returns 0 if invalid move, 1 is valid
			if (move == 's') 
				return 0;
			break;
		case 'a':
			if (move == 'd')
				return 0;
			break;
		case 's':
			if (move == 'w') 
				return 0;
			break;
		case 'd':
			if (move == 'a')
				return 0;
			break;
		case 'i': 
			if (move == 'k')
				return 0;
			break;
		case 'j':
			if (move == 'l')
				return 0;
			break;
		case 'k':
			if (move == 'i')
				return 0;
			break;
		case 'l':
			if (move == 'j')
				return 0;
			break;
	}
	if (move != 'w' && move != 'a' && move != 's' && move != 'd')           // checks that moves are relevant to control scheme
		if (move != 'i' && move != 'j' && move != 'k' && move != 'l')
			return 0;
	return 1;
}

void moveLeft(int x, int y, int isWall[100][100]) {
	int windowX = 5*y - 5, windowY = 5*x;   // x and y are switched in arrays versus gfx_window
                                                // scales it such that the window is a grid of 5x5 squares
	gfx_fill_rectangle(windowX,windowY,5,5);

	isWall[x][y] = 1;                       // updates isWall to convey that a wall is now placed where the player previously was
}

void moveDown(int x, int y, int isWall[100][100]) {
	int windowX = 5*y, windowY = 5*x + 5;

	gfx_fill_rectangle(windowX,windowY,5,5);

	isWall[x][y] = 1;
}

void moveUp(int x, int y, int isWall[100][100]) {
	int windowX = 5*y, windowY = 5*x - 5;

	gfx_fill_rectangle(windowX,windowY,5,5);

	isWall[x][y] = 1;
}

void moveRight(int x, int y, int isWall[100][100]) {
	int windowX = 5*y + 5, windowY = 5*x;

	gfx_fill_rectangle(windowX,windowY,5,5);

	isWall[x][y] = 1;
}

void display_menu() {
	//Menu outline
	gfx_rectangle(50, 50, 400, 150);
	gfx_rectangle(50, 400, 100, 50);
	gfx_rectangle(350, 400, 100, 50);
	// Menu text
	gfx_text(75, 425, "1 Player");
	gfx_text(375, 425, "2 Player");

	// Big TRON!!!!!
	//T
	gfx_rectangle(75, 75, 74, 20);
	gfx_rectangle(102, 75, 20, 100);
	// R  
	gfx_ellipse( 183 ,100, 30, 25);
	gfx_ellipse(183, 100, 10, 15);
	gfx_color(0,0,0);
	gfx_fill_rectangle(150, 75, 37, 100);
	gfx_color(255,255,255);    
	gfx_rectangle(166, 75, 20,  100);
	gfx_line(210, 175, 230, 175);
	gfx_line(186, 151, 210, 175);
	gfx_line(186, 131, 230, 175);
	// O
	gfx_ellipse(288, 125, 37, 50);
	gfx_ellipse(288, 125, 17, 30);
	// N
	gfx_rectangle(339, 75, 20, 100);
	gfx_rectangle(407, 75, 20, 100);
	gfx_line(359, 115, 407, 175);
	gfx_line(359, 75, 407, 135);
}	
int difficulty_menu(char mander, int difficulty /* Add this in main */){
	int xmenu, ymenu;
	gfx_rectangle(50, 50, 400, 150);
	gfx_rectangle(50, 400, 100, 50);
	gfx_rectangle(350, 400, 100, 50);
	// Menu text
	gfx_text(75, 425, "Easy");
	gfx_text(375, 425, "Hard");
	// Big TRON!!!!!
	//T
	gfx_rectangle(75, 75, 74, 20);
	gfx_rectangle(102, 75, 20, 100);
	// R  
	gfx_ellipse( 183 ,100, 30, 25);
	gfx_ellipse(183, 100, 10, 15);
	gfx_color(0,0,0);
	gfx_fill_rectangle(150, 75, 37, 100);
	gfx_color(255,255,255);    
	gfx_rectangle(166, 75, 20,  100);
	gfx_line(210, 175, 230, 175);
	gfx_line(186, 151, 210, 175);
	gfx_line(186, 131, 230, 175);
	// O
	gfx_ellipse(288, 125, 37, 50);
	gfx_ellipse(288, 125, 17, 30);
	// N
	gfx_rectangle(339, 75, 20, 100);
	gfx_rectangle(407, 75, 20, 100);
	gfx_line(359, 115, 407, 175);
	gfx_line(359, 75, 407, 135);

	while(difficulty == 0){         // waits until a difficulty is actually chosen
		mander = gfx_wait();
		if(mander == 1){
			xmenu = gfx_xpos();
			ymenu = gfx_ypos();
			if(xmenu >= 50 && xmenu <= 150 && ymenu >= 400 && ymenu <= 450){
				difficulty = 1;
				return difficulty;
			}
			else if(xmenu >= 350 && xmenu <= 450 && ymenu >= 400 && ymenu <= 450){
				difficulty = 3;
				return difficulty;
			}


		}
	}
}

void startBoard(int x1, int y1, int x2, int y2, int p1_score, int p2_score, int player_num) {
	int windowX1 = 5*y1, windowY1 = 5*x1, windowX2 = 5*y2, windowY2 = 5*x2;
	gfx_color(0, 191, 255);
	gfx_fill_rectangle(windowX1,windowY1,5,5);      // places players on starting tiles and intiates a countdown before game start
	gfx_color(243, 243, 21);
	gfx_fill_rectangle(windowX2,windowY2,5,5);
	gfx_line(0, 500, 500, 500);
        if (player_num == 1)                            // slightly changes scoreboard depending on player number
	    scoreboard_p1(p1_score, p2_score); 
        else 
            scoreboard_p2(p1_score, p2_score);
	gfx_text(250,150, "3");                 // 3
	gfx_flush();    
	usleep(500000);
	gfx_clear();

	gfx_color(0, 191, 255);
	gfx_fill_rectangle(windowX1,windowY1,5,5);
	gfx_color(243, 243, 21);
	gfx_fill_rectangle(windowX2,windowY2,5,5);
	gfx_line(0, 500, 500, 500);
        if (player_num == 1) 
	    scoreboard_p1(p1_score, p2_score); 
        else 
            scoreboard_p2(p1_score, p2_score);
	gfx_text(250,150, "2");                 // 2
	gfx_flush();    
	usleep(500000);
	gfx_clear();

	gfx_color(0, 191, 255);
	gfx_fill_rectangle(windowX1,windowY1,5,5);
	gfx_color(243, 243, 21);
	gfx_fill_rectangle(windowX2,windowY2,5,5);
	gfx_line(0, 500, 500, 500);
        if (player_num == 1) 
	    scoreboard_p1(p1_score, p2_score); 
        else 
            scoreboard_p2(p1_score, p2_score);
	gfx_text(250,150, "1");                 // 1
	gfx_flush();
	usleep(500000);
	gfx_clear();	

	gfx_color(0, 191, 255);
	gfx_fill_rectangle(windowX1,windowY1,5,5);
	gfx_color(243, 243, 21);                // Clear 1 then begin game
	gfx_fill_rectangle(windowX2,windowY2,5,5);
	gfx_line(0, 500, 500, 500);
        if (player_num == 1) 
	    scoreboard_p1(p1_score, p2_score); 
        else 
            scoreboard_p2(p1_score, p2_score);

}    
void end_menu_p1(int gameover, int p1_score, int p2_score)
{
	gfx_color(0,0,0);
	gfx_fill_rectangle(100, 200, 300, 100);
	gfx_color(255,255,255);
	gfx_rectangle(100, 200, 300, 100);
	if(gameover == 1){                      // gameover variable determined by main tells to display who won
		gfx_text(225, 225, "Computer Wins!");
	}
	else if(gameover == 2){
		gfx_text(225, 230, "P1 Wins!");
	}
	else
		gfx_text(225, 230, "Tie");
	gfx_text(140, 250, "Press Space to Play Again");
	gfx_text(140, 270, "Press q to exit");   



}
void end_menu_p2(int gameover, int p1_score, int p2_score)
{
	gfx_color(0,0,0);
	gfx_fill_rectangle(100, 200, 300, 100);
	gfx_color(255,255,255);
	gfx_rectangle(100, 200, 300, 100);              // same as above with P2 instead of Computer
	if(gameover == 1){
		gfx_text(225, 230, "P2 Wins!");
	}                                       
	else if(gameover == 2){
		gfx_text(225, 230, "P1 Wins!");

	}
	else	gfx_text(225, 230, "Tie");

	gfx_text(140, 250, "Press Space to Play Again");
	gfx_text(140, 270, "Press q to exit");   



}
void clear_board(int isWall[100][100])
{                                               // sets isWall all equal to 0 again
	int i,j;
	for( i = 0; i < 100; i++)
		for(j = 0; j < 100; j++)
			isWall[i][j] = 0;
}
void scoreboard_p1(int p1_score, int p2_score)
{
	gfx_color(0, 191, 255);
	gfx_text(50, 550, "Player 1: ");        // displays scores at bottom of the screen with P1 and Computer
	gfx_text(100, 550, num2str(p1_score));
	gfx_color(243, 243, 21);
	gfx_text(400, 550, "Computer: ");
	gfx_text(450, 550, num2str(p2_score));

}
void scoreboard_p2(int p1_score, int p2_score)
{
	gfx_color(0, 191, 255);
	gfx_text(50, 550, "Player 1: ");        // Same as above with P1 and P2
	gfx_text(100, 550, num2str(p1_score));
	gfx_color(243,243,21);
	gfx_text(400, 550, "Player 2: ");
	gfx_text(450, 550, num2str(p2_score));

}
int is_tie(int x1, int y1, int x2, int y2)
{
	if(x1 == x2 && y1 == y2)        // if heads are on same postion it is a draw
	return 1;
	else return 0;

}
char *num2str(int n)
{
	static char a[4];
	sprintf(a, " %d", n);
	return (char*) a;
}

char getFarthestMove(int x1, int y1, int x2, int y2, char direction, int isWall[100][100]) {
    float distance = 0, farthest = 0;
    char move;
    if (!isWall[x2-1][y2] && validMove(direction,'i') && x2-1 > 0) {    // checks given direction to make sure if valid
        distance = sqrt(abs(x2-x1) * abs(x2-x1) + abs(y2-y1) * abs(y2-y1));     // then determine how far it would put computer from player
        if (distance > farthest) {
            farthest = distance;
            move = 'i';
        }
    }   
    if (!isWall[x2+1][y2] && validMove(direction,'k') && x2+1 < 99) {
        distance = sqrt(abs(x2-x1) * abs(x2-x1) + abs(y2-y1) * abs(y2-y1));
        if (distance > farthest) {
            farthest = distance;
            move = 'k';
        }
    }
    if (!isWall[x2][y2-1] && validMove(direction,'j') && y2 - 1 > 0) {
        distance = sqrt(abs(x2-x1) * abs(x2-x1) + abs(y2-y1) * abs(y2-y1));
        if (distance > farthest) {
            farthest = distance;
            move = 'j';
        }
    }
    if (!isWall[x2][y2+1] && validMove(direction,'l') && y2 + 1 < 99) {
        distance = sqrt(abs(x2-x1) * abs(x2-x1) + abs(y2-y1) * abs(y2-y1));
        if (distance > farthest) {
            farthest = distance;
            move = 'l';
        }
    }
    
    if (farthest == 0) return direction;        // returns the current direction if it is trapped
    else return move;                           // otherwise return direction farthest from opponent
}

char findSpace(int x, int y, char direction, int isWall[100][100]) {
    int space[4][2] = {{0}}, mostSpace = 0, mostSecondarySpace = 0, i = x, j = y;
    char move, possibleMoves[4] = {'i', 'j', 'k', 'l'};
    // Check Up
    while (!isWall[i-1][j] && i-1 > 0)  // checks upward path
        space[0][0]++, i--;
    while (!isWall[i][j-1] && j-1 > 0) // and then the paths branching from the end of that previous path
        space[0][1]++, j--;
    while (!isWall[i][j+1] && j+1 < 99) 
        space[0][1]++, j++;
    i = x, j = y;                       // reset i and j to starting coordinates 
    // Check Left
    while (!isWall[i][j-1] && j-1 > 0) 
        space[1][0]++, j--;
    while (!isWall[i+1][j] && i+1 < 99) 
        space[1][1]++, i++;
    while (!isWall[i-1][j] && i-1 > 0) 
        space[1][1]++, i--;
    i = x, j = y;
    // Check Down
    while (!isWall[i+1][j] && i+1 < 99) 
        space[2][0]++, i++;
    while (!isWall[i][j+1] && j+1 < 99) 
        space[2][1]++, j++;
    while (!isWall[i][j-1] && j-1 < 0) 
        space[2][1]++, j--;
    i = x, j = y;
    // Check Right
    while (!isWall[i][j+1] && j+1 < 99) 
        space[3][0]++, j++;
    while (!isWall[i-1][j] && i-1 > 0) 
        space[3][1]++, i--;
    while (!isWall[i+1][j] && i+1 < 99) 
        space[3][1]++, i++;

    for (i = 0; i < 4; i++) {
        if (validMove(direction, possibleMoves[i]) && space[i][0] > mostSpace) {        // if validMove and longest path, choose it as direction
            mostSpace = space[i][0];                                                    // set move equal to that direction, update new farthest path length
            mostSecondarySpace = space[i][1];                                           // and update tiebreaking secondary path length
            move = possibleMoves[i];
        } else if (validMove(direction, possibleMoves[i]) && space[i][0] == mostSpace) {
            if (space[i][1] > mostSecondarySpace) {                                     // checks secondary path lengths in case of a tie to send computer
                mostSpace = space[i][0];                                                // down the path with the longer secondary paths
                mostSecondarySpace = space[i][1];
                move = possibleMoves[i];
            }
        }
    }
    
    if (mostSpace == 0)         // returns current direction if trapped
        return direction;
    else 
        return move;            // else returns path with most open space immediately available
}

