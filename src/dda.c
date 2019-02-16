/*
 *  Digital Differential Analyser Implementation
 * ----------------------------------------------------------------------------
 *  Implementatio of all functions needed for the DDA algorithm.
 * ----------------------------------------------------------------------------
 *  Version: 0.0
 *  Author: Renan Bomtempo
 * ----------------------------------------------------------------------------
 */
#include <stdlib.h>
#include <math.h>
#include "point.h"
#include "screen.h"
#include "dda.h"

void DrawLineUsingDDA ( screen *scr, point p1, point p2 )
{   
    //X and Y differentials
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;

    float steps;
    float x_buffer = p1.x;
    float y_buffer = p1.y;

    if (abs(dx) > abs(dy))  
    {
        steps = abs(dx); 
    }
    else
    {
        steps = abs(dy);
    }

    SetPixelState(scr, round(x_buffer), round(y_buffer), ON); 

    for (int i = 0; i < steps; i++)
    {
        x_buffer += dx / steps;
        y_buffer += dy / steps;
        SetPixelState(scr, round(x_buffer), round(y_buffer), ON);
    }   
}

