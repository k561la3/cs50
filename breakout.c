//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 500
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3
char* colors[5] = {"RED","GREEN", "BLUE", "YELLOW", "BLACK"};
// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    float x,y,vx=2,vy=-1;
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
GObject obj = NULL;
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        if(getY(ball)>=HEIGHT-10){lives--; setLocation(ball,200,300);continue;}
        if(getX(ball)<=0 || getX(ball)+RADIUS>=WIDTH){vx=-vx;}
        if(getY(ball)<=0 || getY(ball)+RADIUS>=HEIGHT){vy=-vy;}
        move(ball, vx, vy);
        pause(10);
        vy+=0.01;
        obj = detectCollision(window,ball);
       GEvent event = getNextEvent(MOUSE_EVENT);

        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure circle follows top cursor
                double x = getX(event)-25;
                double y = getHeight(window)-20;
                setLocation(paddle, x, y);
            }
        }

        if (obj != NULL && strcmp(getType(obj), "GRect") == 0)
        {
            vy=-vy;
            if (obj != paddle)
            {
                removeGWindow(window, obj);
                bricks--;
                points++;
                updateScoreboard(window, label, points);
                
            }
        }
        
        
        
        
        
        
        
        
        
        
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    for(int i = 0;i < COLS;i++){
        for(int j = 0;j < ROWS;j++){
            GRect rect = newGRect(5+i*39,5+j*12,35,10);
            setFilled(rect, true);
            setColor(rect, colors[j]);
            add(window, rect);
    
        }
    
    
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval oval = newGOval(getWidth(window)/2,getHeight(window)/2,RADIUS,RADIUS);
    setFilled(oval, true);
      setColor(oval, "BLACK");
      add(window, oval);
    return oval;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    GRect paddle = newGRect(getWidth(window)/2-50,getHeight(window)-20,100,10);
    //printf("%.2f, %.2f\n",getHeight(window)-50,getWidth(window)/2-50);
    setFilled(paddle, true);
      setColor(paddle, "BLACK");
      add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label;
    double x, y;
    label = newGLabel("Score = 0");
    setFont(label, "SansSerif-18");
    x = (getWidth(window) - getWidth(label)) / 2;
    y = (getHeight(window) + getFontAscent(label)) / 2 - 50;
    setLocation(label, x, y);
    add(window, label);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "Score = %i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x +  RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y +  RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + RADIUS, y +  RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
