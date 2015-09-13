/* Copyright (c) 2011 Kevin Wells */
/* Ascii Pong may be freely redistributed.  See license for details. */

#ifndef movement_h
#define movement_h

using namespace std;

/**Sets the speed of the ball back to it's starting speed setting. Used each time the ball is reset.*/
void set_speed(){
    if(speed==1)
        real_speed=1000;
    if(speed==2)
        real_speed=1500;
    if(speed==3)
        real_speed=2000;
    if(speed==4)
        real_speed=2500;
    if(speed==5)
        real_speed=5000;
}

/**Resets the ball to its default position after a player scores. Or at the start of the game, of course.*/
void reset_ball(){
    set_speed();
    int x=random_range(0,1);
    ball_x=random_range(35,41);
    switch(x){
        case 0:
        ball_y=1;
        break;
        case 1:
        ball_y=23;
        break;
    }
    /**Ball direction: 1 2 3
                       4   5
                       6 7 8*/
    x=random_range(0,1);
    if(ball_y==1){
        switch(x){
            case 0:
            ball_direction=6;
            break;
            case 1:
            ball_direction=8;
            break;
        }
    }
    if(ball_y==23){
        switch(x){
            case 0:
            ball_direction=1;
            break;
            case 1:
            ball_direction=3;
            break;
        }
    }
}

/**Handles changing of ball speed due to collision with the paddles or walls. Paddles make the ball go faster and wall collisions make it go slightly slower.*/
void speed_change(){
    if(paddle==true && speed==1)
        real_speed=real_speed-200;
    if(paddle==false && speed==1)
        real_speed=real_speed+40;
    if(paddle==true && speed==2)
        real_speed=real_speed-300;
    if(paddle==false && speed==2)
        real_speed=real_speed+60;
    if(paddle==true && speed==3)
        real_speed=real_speed-400;
    if(paddle==false && speed==3)
        real_speed=real_speed+80;
    if(paddle==true && speed==4)
        real_speed=real_speed-500;
    if(paddle==false && speed==4)
        real_speed=real_speed+100;
    if(paddle==true && speed==5)
        real_speed=real_speed-1000;
    if(paddle==false && speed==5)
        real_speed=real_speed+200;
}

void move_up_p1(){
    set_color(true);
    if(p1_y>1){
    p1_y--;
    mvprintw(p1_y+paddle_size,p1_x," ");
    }
    if(p1_y+paddle_size==24)
    mvprintw(24,p1_x,"_");
    set_color(false);
}

void move_down_p1(){
    if(p1_y+paddle_size<25)
    p1_y++;
    set_color(true);
    mvprintw(p1_y-1,p1_x," ");
    set_color(false);
}

void move_up_p2(){
    set_color(true);
    if(p2_y>1){
    p2_y--;
    mvprintw(p2_y+paddle_size,p2_x," ");
    }
    if(p2_y+paddle_size==24)
        mvprintw(24,p2_x,"_");
    set_color(false);
}

void move_down_p2(){
    if(p2_y+paddle_size<25)
    p2_y++;
    set_color(true);
    mvprintw(p2_y-1,p2_x," ");
    set_color(false);
}

void paddle_hit_p1(){
    if(ball_direction==6){
        ball_direction=8;
        mvprintw(ball_y,ball_x," ");
        ball_x++;
        ball_y++;
        paddle=true;
        p1_hits++;
        speed_change();
    }
    if(ball_direction==1){
        ball_direction=3;
        mvprintw(ball_y,ball_x," ");
        ball_x++;
        ball_y--;
        paddle=true;
        p1_hits++;
        speed_change();
    }
}

void paddle_hit_p2(){
    if(ball_direction==8){
        ball_direction=6;
        mvprintw(ball_y,ball_x," ");
        ball_x--;
        ball_y++;
        paddle=true;
        p2_hits++;
        speed_change();
    }
    if(ball_direction==3){
        ball_direction=1;
        mvprintw(ball_y,ball_x," ");
        ball_x--;
        ball_y--;
        paddle=true;
        p2_hits++;
        speed_change();
    }
}

void paddle_check_p1(){
    set_color(true);
    switch(paddle_size){
        case 1:
        if(ball_y==p1_y-1 || ball_y==p1_y || ball_y==p1_y+1)
            paddle_hit_p1();
        break;
        case 2:
        if(ball_y==p1_y-1 || ball_y==p1_y || ball_y==p1_y+1 || ball_y==p1_y+2)
            paddle_hit_p1();
        break;
        case 3:
        if(ball_y==p1_y-1 || ball_y==p1_y || ball_y==p1_y+1 || ball_y==p1_y+2 || ball_y==p1_y+3)
            paddle_hit_p1();
        break;
        case 4:
        if(ball_y==p1_y-1 || ball_y==p1_y || ball_y==p1_y+1 || ball_y==p1_y+2 || ball_y==p1_y+3 || ball_y==p1_y+4)
            paddle_hit_p1();
        break;
        case 5:
        if(ball_y==p1_y-1 || ball_y==p1_y || ball_y==p1_y+1 || ball_y==p1_y+2 || ball_y==p1_y+3 || ball_y==p1_y+4 || ball_y==p1_y+5)
            paddle_hit_p1();
        break;
    }
    set_color(false);
}

void paddle_check_p2(){
    set_color(true);
    switch(paddle_size){
        case 1:
        if(ball_y==p2_y-1 || ball_y==p2_y || ball_y==p2_y+1)
            paddle_hit_p2();
        break;
        case 2:
        if(ball_y==p2_y-1 || ball_y==p2_y || ball_y==p2_y+1 || ball_y==p2_y+2)
            paddle_hit_p2();
        break;
        case 3:
        if(ball_y==p2_y-1 || ball_y==p2_y || ball_y==p2_y+1 || ball_y==p2_y+2 || ball_y==p2_y+3)
            paddle_hit_p2();
        break;
        case 4:
        if(ball_y==p2_y-1 || ball_y==p2_y || ball_y==p2_y+1 || ball_y==p2_y+2 || ball_y==p2_y+3 || ball_y==p2_y+4)
            paddle_hit_p2();
        break;
        case 5:
        if(ball_y==p2_y-1 || ball_y==p2_y || ball_y==p2_y+1 || ball_y==p2_y+2 || ball_y==p2_y+3 || ball_y==p2_y+4 || ball_y==p2_y+5)
            paddle_hit_p2();
        break;
    }
    set_color(false);
}

void move_ball(){
    set_color(true);
    /**The ball is moving up and left.*/
    if(ball_direction==1){
        /**The ball has reached the top of the screen.*/
        if(ball_y<2){
            speed_change();
            ball_direction=6;
            mvprintw(ball_y,ball_x," ");
            check_for_net();
            /**This if statement handles the rare cases when the ball was paddled "into the wall" on the last paddle check.*/
            if(ball_y<1)
                mvprintw(ball_y,ball_x,"_");
            ball_x--;
            ball_y++;
        }
        else{
            mvprintw(ball_y,ball_x," ");
            check_for_net();
            /**This if statement handles the rare cases when the ball was paddled "into the wall" on the last paddle check.*/
            if(ball_y>23)
                mvprintw(ball_y,ball_x,"_");
            ball_x--;
            ball_y--;
        }
    }
    /**The ball is moving up and right.*/
    if(ball_direction==3){
        /**The ball has reached the top of the screen.*/
        if(ball_y<2){
            speed_change();
            ball_direction=8;
            mvprintw(ball_y,ball_x," ");
            check_for_net();
            /**This if statement handles the rare cases when the ball was paddled "into the wall" on the last paddle check.*/
            if(ball_y<1)
                mvprintw(ball_y,ball_x,"_");
            ball_x++;
            ball_y++;
        }
        else{
            mvprintw(ball_y,ball_x," ");
            check_for_net();
            /**This if statement handles the rare cases when the ball was paddled "into the wall" on the last paddle check.*/
            if(ball_y>23)
                mvprintw(ball_y,ball_x,"_");
            ball_x++;
            ball_y--;
        }
    }
    /**The ball is moving down and left.*/
    if(ball_direction==6){
        /**The ball has reached the bottom of the screen.*/
        if(ball_y>23){
            speed_change();
            ball_direction=1;
            mvprintw(ball_y,ball_x,"_");
            check_for_net();
            ball_x--;
            ball_y--;
        }
        else{
            mvprintw(ball_y,ball_x," ");
            check_for_net();
            ball_x--;
            ball_y++;
        }
    }
    /**The ball is moving down and right.*/
    if(ball_direction==8){
        /**The ball has reached the bottom of the screen.*/
        if(ball_y>23){
            speed_change();
            ball_direction=3;
            mvprintw(ball_y,ball_x,"_");
            check_for_net();
            ball_x++;
            ball_y--;
        }
        else{
            mvprintw(ball_y,ball_x," ");
            check_for_net();
            ball_x++;
            ball_y++;
        }
    }
    /**If the ball is one space from scoring on player 1, check for his paddle.*/
    if(ball_x==0){
        paddle_check_p1();
        /**paddle_check_p1() sets paddle equal to true if the paddle has hit the ball. If not, then the following if statement is executed.*/
        if(paddle==false){
            if(ball_direction==1){
                ball_x--;
                ball_y--;
            }
            if(ball_direction==6){
                ball_x--;
                ball_y++;
            }
        }
        paddle=false;
    }
    /**If the ball is one space from scoring on player 2, check for his paddle.*/
    if(ball_x==79){
        paddle_check_p2();
        /**paddle_check_p2() sets paddle equal to true if the paddle has hit the ball. If not, then the following if statement is executed.*/
        if(paddle==false){
            if(ball_direction==3){
                ball_x++;
                ball_y--;
            }
            if(ball_direction==8){
                ball_x++;
                ball_y++;
            }
        }
        paddle=false;
    }
    /**Player 2 scores!*/
    if(ball_x==-1){
        p2_score++;
        p1_misses++;
        reset_ball();
    }
    /**Player 1 scores!*/
    if(ball_x==80){
        p1_score++;
        p2_misses++;
        reset_ball();
    }
    set_color(false);
}

#endif
