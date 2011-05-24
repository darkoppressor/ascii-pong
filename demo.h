/* Copyright (c) 2011 Kevin Wells */
/* Ascii Pong may be freely redistributed.  See license for details. */

#ifndef demo_h
#define demo_h

using namespace std;

/**Checks to see if there is any input(ch!=ERR) and if demo mode is on. If these are true, turn off demo mode and return to the main menu.*/
void demo_return_to_menu(){
    if(ch!=ERR && demo==true){
        demo=false;
        main_menu();
    }
}

void demo_move_up_ai(){
    set_color(true);
    if(p1_y>1){
    p1_y--;
    mvprintw(p1_y+paddle_size,p1_x," ");
    }
    if(p1_y+paddle_size==24)
    mvprintw(24,p1_x,"_");
    set_color(false);
}

void demo_move_down_ai(){
    set_color(true);
    if(p1_y+paddle_size<25){
    p1_y++;
    mvprintw(p1_y-1,p1_x," ");
    }
    set_color(false);
}

void demo_ai_move_properly(){
    if(p1_y>ball_y)
        demo_move_up_ai();
    if(p1_y+paddle_size-1<ball_y)
        demo_move_down_ai();
}

void demo_ai_move_randomly(){
    int x=random_range(0,1);
    if(x==0)
        demo_move_up_ai();
    if(x==1)
        demo_move_down_ai();
}

void demo_ai_move(){
    int x;
    switch(difficulty){
        /**Very easy mode: There is a 30% chance the ai will move his paddle in the direction of the ball, a 20% chance he will move it randomly, and a 50% chance that he will not move his paddle
        this check.*/
        case 0:
        x=random_range(1,100);
        if(x>=1 && x<=30)
            demo_ai_move_properly();
        if(x>=31 && x<=50)
            demo_ai_move_randomly();
        break;
        /**Easy mode: There is a 35% chance the ai will move his paddle in the direction of the ball, and a 65% chance that he will not move his paddle this check.*/
        case 1:
        x=random_range(1,100);
        if(x>=1 && x<=35)
            demo_ai_move_properly();
        break;
        /**Normal mode: There is a 50% chance the ai will move his paddle in the direction of the ball, and a 50% chance that he will not move his paddle this check.*/
        case 2:
        x=random_range(1,100);
        if(x>=1 && x<=50)
            demo_ai_move_properly();
        break;
        /**Impossible mode: The computer will move his paddle in the direction of the ball every check.*/
        case 3:
        demo_ai_move_properly();
        break;
    }
}

#endif
