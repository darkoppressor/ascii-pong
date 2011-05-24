/* Copyright (c) 2011 Kevin Wells */
/* Ascii Pong may be freely redistributed.  See license for details. */

#ifndef game_h
#define game_h

using namespace std;

void game();
void reset_ball();

void save_options(){
    ofstream options_file ("options.cfg");
    if(options_file.is_open()){
        if(singleplayer==false)
            options_file << "0";
        if(singleplayer==true)
            options_file << "1";
        if(difficulty==0)
            options_file << "0";
        if(difficulty==1)
            options_file << "1";
        if(difficulty==2)
            options_file << "2";
        if(difficulty==3)
            options_file << "3";
        if(theme==0)
            options_file << "0";
        if(theme==1)
            options_file << "1";
        if(theme==2)
            options_file << "2";
        if(theme==3)
            options_file << "3";
        if(theme==4)
            options_file << "4";
        if(speed==1)
            options_file << "1";
        if(speed==2)
            options_file << "2";
        if(speed==3)
            options_file << "3";
        if(speed==4)
            options_file << "4";
        if(speed==5)
            options_file << "5";
        if(paddle_size==1)
            options_file << "1";
        if(paddle_size==2)
            options_file << "2";
        if(paddle_size==3)
            options_file << "3";
        if(paddle_size==4)
            options_file << "4";
        if(paddle_size==5)
            options_file << "5";
        if(gametype==0)
            options_file << "0";
        if(gametype==1)
            options_file << "1";
        if(gametype==2)
            options_file << "2";
        options_file.close();
    }
}

void quitgame(){
    erase();
    timeout(-1);
    set_color(true);
    color_fill();
    mvprintw(11,31,"Be seeing you...");
    getch();
    set_color(false);
    erase();
    endwin();
    exit(EXIT_SUCCESS);
}

void game_end(){
    erase();
    timeout(-1);
    set_color(true);
    color_fill();
    set_color(false);
    set_highlight(true);
    mvprintw(0,0,"                                   Game Over                                    ");
    set_highlight(false);
    set_color(true);
    mvprintw(3,33,"Winner: ");
    if(p1_score<p2_score)
    mvprintw(3,42,"Player 2");
    if(p1_score>p2_score)
    mvprintw(3,42,"Player 1");
    if(p1_score==p2_score)
    mvprintw(3,42,"Tie");
    set_color(false);
    set_highlight(true);
    mvprintw(5,19,"Player 1");
    mvprintw(5,49,"Player 2");
    set_highlight(false);
    set_color(true);
    mvprintw(7,19,"Score: %d",p1_score);
    mvprintw(7,49,"Score: %d",p2_score);
    mvprintw(9,19,"Hits: %d",p1_hits);
    mvprintw(9,49,"Hits: %d",p2_hits);
    mvprintw(11,19,"Misses: %d",p1_misses);
    mvprintw(11,49,"Misses: %d",p2_misses);
    set_color(false);
    getch();
    timeout(0);
    quitgame();
}

void credits(){
    erase();
    timeout(-1);
    set_color(true);
    color_fill();
    set_color(false);
    set_highlight(true);
    mvprintw(0,0,"                                   Credits                                      ");
    mvprintw(2,30,"   Programming   ");
    set_highlight(false);
    set_color(true);
    mvprintw(4,33,"Kevin Wells");
    set_color(false);
    set_highlight(true);
    mvprintw(6,30,"   Playtesters   ");
    set_highlight(false);
    set_color(true);
    mvprintw(8,32,"Aneissa Wells");
    mvprintw(10,33,"Kevin Wells");
    mvprintw(23,26,"Press any key to continue.");
    getch();
    set_color(false);
    timeout(0);
    erase();
}

void newgame(){
    timer=0;
    timer_minutes=0;
    timer_seconds=0;
    max_timer=2;
    max_score=10;
    p1_score=0;
    p2_score=0;
    p1_hits=0;
    p2_hits=0;
    p1_misses=0;
    p2_misses=0;
    p1_x=0;
    p1_y=1;
    p2_x=79;
    p2_y=1;
    reset_ball();
    game();
}

void draw_main_menu(){
    set_color(true);
    color_fill();
    go_to_xy(35,0);
    mvprintw(print_y,print_x,"Ascii Pong");
    go_to_xy(29,2);
    mvprintw(print_y,print_x,"Created by: Kevin Wells");
    if(menu_item!=0){
        go_to_xy(33,8);
        mvprintw(print_y,print_x,"Start New Game");
    }
    if(menu_item!=1){
        go_to_xy(33,10);
        mvprintw(print_y,print_x,"Options");
    }
    if(menu_item!=2){
        go_to_xy(33,12);
        mvprintw(print_y,print_x,"Credits");
    }
    if(menu_item!=3){
        go_to_xy(33,14);
        mvprintw(print_y,print_x,"Quit");
    }
    set_color(false);
    set_highlight(true);
    if(menu_item==0){
        go_to_xy(33,8);
        mvprintw(print_y,print_x,"Start New Game");
    }
    if(menu_item==1){
        go_to_xy(33,10);
        mvprintw(print_y,print_x,"Options");
    }
    if(menu_item==2){
        go_to_xy(33,12);
        mvprintw(print_y,print_x,"Credits");
    }
    if(menu_item==3){
        go_to_xy(33,14);
        mvprintw(print_y,print_x,"Quit");
    }
    set_highlight(false);
}

void draw_options_menu(){
    set_color(true);
    color_fill();
    go_to_xy(36,0);
    mvprintw(print_y,print_x,"Options");
    if(options_menu_item!=0){
        go_to_xy(24,6);
        mvprintw(print_y,print_x,"Game Type: ");
        if(gametype==0)
            printw("Standard");
        if(gametype==1)
            printw("Timed");
        if(gametype==2)
            printw("Unending Fun");
    }
    if(options_menu_item!=1){
        go_to_xy(24,8);
        mvprintw(print_y,print_x,"Human Players: ");
        if(singleplayer==false)
            printw("Two");
        if(singleplayer==true)
            printw("One");
    }
    if(options_menu_item!=2){
        go_to_xy(24,10);
        mvprintw(print_y,print_x,"AI Personality: ");
        if(difficulty==0)
            printw("Slow and stupid (Very easy)");
        if(difficulty==1)
            printw("Slow to react (Easy)");
        if(difficulty==2)
            printw("A worthy opponent (Normal)");
        if(difficulty==3)
            printw("You will not win (Impossible)");
    }
    if(options_menu_item!=3){
        go_to_xy(24,12);
        mvprintw(print_y,print_x,"Starting Speed: ");
        if(speed==1)
            printw("Use the force (Fastest)");
        if(speed==2)
            printw("Test your reflexes (Faster)");
        if(speed==3)
            printw("Speeding up (Fast)");
        if(speed==4)
            printw("Default speed (A reasonable speed)");
        if(speed==5)
            printw("Slow as molasses (Slow)");
    }
    if(options_menu_item!=4){
        go_to_xy(24,14);
        mvprintw(print_y,print_x,"Paddle Size: ");
        if(paddle_size==1)
            printw("What are you trying to prove? (One tile)");
        if(paddle_size==2)
            printw("Think you're tough? (Two tiles)");
        if(paddle_size==3)
            printw("Sharpened senses (Three tiles)");
        if(paddle_size==4)
            printw("Default size (Four tiles)");
        if(paddle_size==5)
            printw("Hard to miss (Five tiles)");
    }
    if(options_menu_item!=5){
        go_to_xy(24,16);
        mvprintw(print_y,print_x,"Theme: ");
        if(theme==0)
            printw("Classic Pong");
        if(theme==1)
            printw("Icy Waters");
        if(theme==2)
            printw("Fiery Wastes");
        if(theme==3)
            printw("Ping Pong");
        if(theme==4)
            printw("Girly");
    }
    if(options_menu_item!=6){
        go_to_xy(24,18);
        mvprintw(print_y,print_x,"Quit Game");
    }
    if(options_menu_item!=7){
        go_to_xy(24,20);
        mvprintw(print_y,print_x,"Back");
    }
    set_color(false);
    set_highlight(true);
    if(options_menu_item==0){
        go_to_xy(24,6);
        mvprintw(print_y,print_x,"Game Type: ");
        if(gametype==0)
            printw("Standard");
        if(gametype==1)
            printw("Timed");
        if(gametype==2)
            printw("Unending Fun");
    }
    if(options_menu_item==1){
        go_to_xy(24,8);
        mvprintw(print_y,print_x,"Human Players: ");
        if(singleplayer==false)
            printw("Two");
        if(singleplayer==true)
            printw("One");
    }
    if(options_menu_item==2){
        go_to_xy(24,10);
        mvprintw(print_y,print_x,"AI Personality: ");
        if(difficulty==0)
            printw("Slow and stupid (Very easy)");
        if(difficulty==1)
            printw("Slow to react (Easy)");
        if(difficulty==2)
            printw("A worthy opponent (Normal)");
        if(difficulty==3)
            printw("You will not win (Impossible)");
    }
    if(options_menu_item==3){
        go_to_xy(24,12);
        mvprintw(print_y,print_x,"Starting Speed: ");
        if(speed==1)
            printw("Use the force (Fastest)");
        if(speed==2)
            printw("Test your reflexes (Faster)");
        if(speed==3)
            printw("Speeding up (Fast)");
        if(speed==4)
            printw("Default speed (A reasonable speed)");
        if(speed==5)
            printw("Slow as molasses (Slow)");
    }
    if(options_menu_item==4){
        go_to_xy(24,14);
        mvprintw(print_y,print_x,"Paddle Size: ");
        if(paddle_size==1)
            printw("What are you trying to prove? (One tile)");
        if(paddle_size==2)
            printw("Think you're tough? (Two tiles)");
        if(paddle_size==3)
            printw("Sharpened senses (Three tiles)");
        if(paddle_size==4)
            printw("Default size (Four tiles)");
        if(paddle_size==5)
            printw("Hard to miss (Five tiles)");
    }
    if(options_menu_item==5){
        go_to_xy(24,16);
        mvprintw(print_y,print_x,"Theme: ");
        if(theme==0)
            printw("Classic Pong");
        if(theme==1)
            printw("Icy Waters");
        if(theme==2)
            printw("Fiery Wastes");
        if(theme==3)
            printw("Ping Pong");
        if(theme==4)
            printw("Girly");
    }
    if(options_menu_item==6){
        go_to_xy(24,18);
        mvprintw(print_y,print_x,"Quit Game");
    }
    if(options_menu_item==7){
        go_to_xy(24,20);
        mvprintw(print_y,print_x,"Back");
    }
    set_highlight(false);
}

void options(){
    bool menu_done=false;
    options_menu_item=0;
    erase();
    draw_options_menu();
    while(ch=getch()){
        draw_options_menu();
        switch(ch){
            case KEY_DOWN: case KP_DOWN:
            options_menu_item++;
            if(options_menu_item>7)
            options_menu_item=0;
            draw_options_menu();
            break;
            case KEY_UP: case KP_UP:
            options_menu_item--;
            if(options_menu_item<0)
            options_menu_item=7;
            draw_options_menu();
            break;
            case KEY_SPACE: case KEY_ESC:
            menu_done=true;
            break;
            case KEY_RIGHT: case KP_RIGHT:
            if(options_menu_item==0){
                    gametype++;
                    if(gametype>2)
                    gametype=0;
                    draw_options_menu();
                    save_options();
                    break;
            }
            if(options_menu_item==1 && singleplayer==false){
                    singleplayer=true;
                    draw_options_menu();
                    save_options();
                    break;
            }
            if(options_menu_item==1 && singleplayer==true){
                    singleplayer=false;
                    draw_options_menu();
                    save_options();
                    break;
            }
            if(options_menu_item==2){
                    difficulty++;
                    if(difficulty>3)
                    difficulty=0;
                    draw_options_menu();
                    save_options();
                    break;
            }
            if(options_menu_item==3){
                speed--;
                if(speed<1)
                speed=5;
                draw_options_menu();
                save_options();
                break;
            }
            if(options_menu_item==4){
                paddle_size--;
                if(paddle_size<1)
                paddle_size=5;
                draw_options_menu();
                save_options();
                break;
            }
            if(options_menu_item==5){
                theme++;
                if(theme>4)
                theme=0;
                draw_options_menu();
                save_options();
                break;
            }
            break;
            case KEY_LEFT: case KP_LEFT:
            if(options_menu_item==0){
                    gametype--;
                    if(gametype<0)
                    gametype=2;
                    draw_options_menu();
                    save_options();
                    break;
            }
            if(options_menu_item==1 && singleplayer==false){
                    singleplayer=true;
                    draw_options_menu();
                    save_options();
                    break;
            }
            if(options_menu_item==1 && singleplayer==true){
                    singleplayer=false;
                    draw_options_menu();
                    save_options();
                    break;
            }
            if(options_menu_item==2){
                    difficulty--;
                    if(difficulty<0)
                    difficulty=3;
                    draw_options_menu();
                    save_options();
                    break;
            }
            if(options_menu_item==3){
                speed++;
                if(speed>5)
                speed=1;
                draw_options_menu();
                save_options();
                break;
            }
            if(options_menu_item==4){
                paddle_size++;
                if(paddle_size>5)
                paddle_size=1;
                draw_options_menu();
                save_options();
                break;
            }
            if(options_menu_item==5){
                theme--;
                if(theme<0)
                theme=4;
                draw_options_menu();
                save_options();
                break;
            }
            break;
            case 'q':
            if(game_in_progress==true)
            game_end();
            if(game_in_progress==false)
            quitgame();
            break;
            case KEY_NTR:
            if(options_menu_item==6){
                if(game_in_progress==true)
                game_end();
                if(game_in_progress==false)
                quitgame();
            }
            if(options_menu_item==7)
            menu_done=true;
            break;
        }
        if(menu_done==true){
            menu_done=false;
            erase();
            if(game_in_progress==false)
            draw_main_menu();
            if(game_in_progress==true){
                set_color(true);
                color_fill();
                set_color(false);
                draw_borders();
                draw();
            }
            break;
        }
    }
}

void main_menu(){
    game_in_progress=false;
    int menu_tick=0;
    erase();
    draw_main_menu();
    while(ch=getch()){
        draw_main_menu();
        switch(ch){
            case KEY_DOWN: case KP_DOWN:
            menu_tick=0;
            menu_item++;
            if(menu_item>3)
            menu_item=0;
            draw_main_menu();
            break;
            case KEY_UP: case KP_UP:
            menu_tick=0;
            menu_item--;
            if(menu_item<0)
            menu_item=3;
            draw_main_menu();
            break;
            case KEY_NTR:
            menu_tick=0;
            if(menu_item==0)
            newgame();
            if(menu_item==1)
            options();
            if(menu_item==2)
            credits();
            if(menu_item==3)
            quitgame();
            break;
            case KEY_ESC:
            quitgame();
            break;
            case 'n': case 's':
            menu_tick=0;
            newgame();
            break;
            case 'o':
            menu_tick=0;
            options();
            break;
            case 'c':
            menu_tick=0;
            credits();
            break;
            case 'q':
            menu_tick=0;
            quitgame();
            break;
        }
        wait(.0001);
        menu_tick++;
        /**If there is no input for 30 seconds, start the demo. 5000 ticks=1 second.*/
        if(menu_tick==150000){
            menu_tick=0;
            demo=true;
            newgame();
        }
    }
}

void menu(){
    options();
}

#endif
