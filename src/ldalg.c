/*
 *  Bresenham's Algorithm Implementation (Integer Version)
 * ----------------------------------------------------------------------------
 *  Implementations of all functions used for Bresenham's algorithm.
 * ----------------------------------------------------------------------------
 *  Version: 0.0
 *  Author: Renan Bomtempo
 * ----------------------------------------------------------------------------
 *  *This version only plots lines within the first octant of the plane*
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "screen.h"
#include "point.h"
#include "ldalg.h"
#define _CONSOLE_LOG_(X)            printf("..."#X"...\n");


void DigitalDifferentialAnalyser ( screen *scr, point p0, point p1 )
{   
    _CONSOLE_LOG_(Initiating DDA Algorithm)

    //X and Y differentials
    float dx = p1.x - p0.x;
    float dy = p1.y - p0.y;

    //unit steps
    int steps;

    //X and Y values of the pixel that will be turned ON
    float x_buffer = p0.x;
    float y_buffer = p0.y;

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
    
    //Turn on the first pixel (exact coordinates of p0)
    SetPixelState(scr, round(x_buffer), round(y_buffer), ON); 

    //Loop for incrementing X and Y coordinates 
    for (int i = 0; i < steps; i++) {
        x_buffer += x_increment;
        y_buffer += y_increment;
        SetPixelState(scr, round(x_buffer), round(y_buffer), ON);
    }   

    _CONSOLE_LOG_(Finished executing DDA Algorithm)
}

void Bresenham ( screen *scr, point p0, point p1 )
{   
    _CONSOLE_LOG_(Initiating Bresenham Algorithm)

    if (IsSamePoint(p1, p0)) {
        SetPixelState(scr, p0.x, p0.y, ON);
    } else {
        //X and Y differentials
        int dx = p1.x - p0.x;
        int dy = p1.y - p0.y;

        //Auxilary variables
        int twice_dy = 2 * dy;
        int twice_dy_dx = twice_dy - 2*dx;
        int decision_variable = twice_dy - dx;

        //X and Y values of the pixel that will be turned ON
        int buffer_x = p0.x;
        int buffer_y = p0.y;

        while (buffer_x != p1.x) {
            SetPixelState(scr, buffer_x++, buffer_y, ON);
            if (decision_variable < 0) {
                decision_variable += twice_dy;
            } else {
                buffer_y++;
                decision_variable += twice_dy_dx;
            }
        }
    }

    _CONSOLE_LOG_(Finished executing Bresenham Algorithm)
}

void FloatMidpoint ( screen *scr, point p0, point p1 ) 
{
    _CONSOLE_LOG_(Initiating Float Midpoint Algorithm)

    //X and Y differentials
    float dx = p1.x - p0.x;
    float dy = p1.y - p0.y;

    //Slope
    float m = dy/dx;

    //Real value of Y coordinate
    float real_y = 0;

    //X and Y values of the pixel that will be turned ON
    int buffer_x = p0.x;
    int buffer_y = p0.y;
    
    while (buffer_x != p1.x) {
        SetPixelState(scr, buffer_x++, buffer_y, ON);  
        real_y = m * buffer_x;
        if (real_y > (float)buffer_y + 0.5f) {
            buffer_y += 1;
        } 
    }
    _CONSOLE_LOG_(Finished executing Float Midpoint Algorithm)
}

void IntMidpoint ( screen *scr, point p0, point p1 ) 
{
    _CONSOLE_LOG_(Initiating Integer Midpoint Algorithm)

    //X and Y differentials
    int dx = p1.x - p0.x;
    int dy = p1.y - p0.y;

    //X and Y values of the pixel that will be turned ON
    int buffer_x = p0.x;
    int buffer_y = p0.y;

    //Integer values of the Slope and real Y coordinate
    int m2dx = 2*dy;
    int real_y2dx = 0;

    while (buffer_x != p1.x) {
        SetPixelState(scr, buffer_x, buffer_y, ON);  
        real_y2dx = m2dx * (++buffer_x);    //Same as the float version, but multiplied by 2dx
        if (real_y2dx > (2*buffer_y + 1)*dx) {
            buffer_y += 1;
        } 
    }

    _CONSOLE_LOG_(Finished executing Integer Midpoint Algorithm)
}

