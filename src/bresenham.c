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
#include "bresenham.h"

void DrawLineUsingBresenham ( screen *scr, point p1, point p2 )
{   
    if (IsSamePoint(p1, p2)) { 
        //If the two points are the same
        SetPixelState(scr, p1.x, p1.y, ON);
    } else { 
        //If the two points are different
        int dx = p2.x - p1.x;
        int dy = p2.y - p1.y;
        int current_x = p1.x;
        int current_y = p1.y;
        int error_bound;

        //Axis of maximum movement
        char driving_axis = abs(dx) >= abs(dy) ? X : Y;
        
        if (driving_axis == X) {
            //X is the driving axis 
            error_bound = dy - dx;

            while (current_x != p2.x) {
                SetPixelState(scr, current_x, current_y, ON);
                if (error_bound >= 0) {
                    error_bound -= dx;
                    ++current_y;
                }
                error_bound += dy;
                ++current_x;
            }
        } else {
            //Y is the driving axis
            error_bound = dx - dy;

            while (current_y != p2.y) {
                SetPixelState(scr, current_x, current_y, ON);
                if (error_bound >= 0) {
                    error_bound -= dy;
                    ++current_x;
                }
                error_bound += dx;
                ++current_y;
            }
        }
    }
}
