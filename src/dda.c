/*
 *  Digital Differential Analyser Implementation
 * ----------------------------------------------------------------------------
 *  Implementatio of all functions needed for the DDA algorithm.
 * ----------------------------------------------------------------------------
 *  Version: 0.1
 *  Author: Renan Bomtempo
 * ----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"
#include "screen.h"
#include "dda.h"
#define _CONSOLE_LOG_(X)            printf("..."#X"...\n");


void DrawLineUsingDDA ( screen *scr, point p1, point p2 )
{   
    _CONSOLE_LOG_(Initiating DDA Algorithm)
    //X and Y differentials
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;

    //unit steps
    int steps;

    //X and Y values of the pixel that will be turned ON
    float x_buffer = p1.x;
    float y_buffer = p1.y;

    //X and Y increments
    float x_increment;
    float y_increment;

    //Define the number of steps based on the greater differential
    if (abs(dx) > abs(dy)) {
        steps = abs(dx); 
    } else {
        steps = abs(dy);
    }

    //Calculate X and Y increment
    x_increment = dx / steps;
    y_increment = dy / steps;
    
    //Print computed increment values 
    //printf("x_increment = %.2f\ny_increment = %.2f\n", x_increment, y_increment);

    //Turn on the first pixel (exact coordinates of p1)
    SetPixelState(scr, round(x_buffer), round(y_buffer), ON); 

    //Loop for incrementing X and Y coordinates 
    for (int i = 0; i < steps; i++) {
        //Print Steps
        /*printf("Step %d:\n"
               "  x = %.2f\n"
               "  y = %.2f\n",
               i,
               x_buffer, y_buffer);*/
        x_buffer += x_increment;
        y_buffer += y_increment;
        SetPixelState(scr, round(x_buffer), round(y_buffer), ON);
    }   

    _CONSOLE_LOG_(Finished executing DDA Algorithm)
}

