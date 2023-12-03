#include <iostream>
//#include <conio.h>
#include <windows.h>  
#include <ncurses/ncurses.h>


int maxY, maxX;
int x, y;
int score = 0;

bool game = true;

void Char(){
	mvprintw(((maxY-2)-4)+y, x, "    0    ");
    mvprintw(((maxY-2)-3)+y, x, " 0 000 0 ");
    mvprintw(((maxY-2)-2)+y, x, "000000000");
    mvprintw(((maxY-2)-1)+y, x, "  00000  ");
    mvprintw((maxY-2)+y, x,     "000000000");
    refresh();
}

void Enemy(){
	
	char c = (int) ' ';
	WINDOW *win = newwin(maxY, (maxX/2)-16, 0, (maxX/2)-30);
    
    refresh();
    box(win, c, c);
    wrefresh(win);
    int acak;
    int acaak = rand() % 35;
	acak = rand() % 35;
	int v = 0;
    int h = (maxX/3)-9;
    int k = (maxX/2)+5;
    
    
	for(int i=0 ; i <maxY+10;i++){
	mvprintw(-1+i, h+acak, "         ");	
	mvprintw(0+i, h+acak, "ooooooooo");
    mvprintw(1+i, h+acak, "  ooooo  ");
    mvprintw(2+i, h+acak, "ooooooooo");
    mvprintw(3+i, h+acak, " o ooo o ");																				
    mvprintw(4+i, h+acak, "    o    ");
    
    mvprintw(-8+i, k-acaak, "         ");	
	mvprintw(-7+i, k-acaak, "ooooooooo");
    mvprintw(-6+i, k-acaak, "  ooooo  ");
    mvprintw(-5+i, k-acaak, "ooooooooo");
    mvprintw(-4+i, k-acaak, " o ooo o ");																				
    mvprintw(-3+i, k-acaak, "    o    ");
	
	refresh();
    Sleep(50);
	}
	
	
	
	
    
	
}

void Draw() {

    clear();

    for(int i=0;i<(maxX/2)-30;i++){
    	for (int j=0;j<maxY;j++){
    	mvprintw(j,i,"*");
    	}
	}
    
    for(int i=maxX-20; i>(maxX/2)+13;i--){
    	for(int j=0 ; j<maxY ; j++){
    		mvprintw(j,i,"*");
		}
	}
    
    mvprintw(5,maxX-16,"  Control   ");
    mvprintw(6,maxX-16,"------------");
    mvprintw(7,maxX-16,"W Key - Up");
    mvprintw(8,maxX-16,"A Key - Left");
    mvprintw(9,maxX-16,"S Key - Down");
    mvprintw(10,maxX-16,"D Key - Right");
    
    mvprintw(14,maxX-16,"   Score   ");
    mvprintw(15,maxX-16,"------------");
    mvprintw(16,maxX-17,"Your score : %d",score);
    
    
//    Enemy();
	}
	
void Console() {
    switch (getch()) {
        case 'a': 
        	if(x>(maxX/2)-26){
					x-=4;
			}
			break;
			
        case 'w': 
			if(((maxY-2)-4)+y>1)
			y--;
			break;
			
        case 's': 
		 	if((maxY-2)+y<maxY-1)
			y++;
			break;
        case 'd':
			if(x<(maxX/2)+4){
				x+=4;
			}
			break;
        }
}

void Play(){
	
	Draw();
	Char();
	Console();
	
}

int main() {
    initscr(); // Initialize ncurses
    noecho();  // Don't display typed characters
    curs_set(0);  // Hide the cursor

    getmaxyx(stdscr, maxY, maxX);

    y = 0;
    x = (maxX/2)-12;
    
	
	
	
	
	do{   
	Play();
	
	}while(game);
    
    refresh();
    getch();

    return 0;
}

