/*
 *  Point ADT Implementation
 * ----------------------------------------------------------------------------
 *  All implementations of functions that manipulate the point data structure.
 * ----------------------------------------------------------------------------
 *  Version: 0.1.1
 *  Author: Renan Bomtempo
 * ----------------------------------------------------------------------------
 *  - Set the coordinate values of a given point
 *  - Check if two points are the same
 */
#include <stdio.h>
#include <stdlib.h>
#include "point.h"

void SetPointCoordinates ( point *p, int x, int y ) 
{
    if (x < 0 || y < 0) {
        printf("ERROR: This program only supports positive coordinates.");
        exit(0);
    }
    p->x = x;
    p->y = y;
}

char IsSamePoint ( point p1, point p2 ) 
{
    if (p1.x == p2.x && p1.y == p2.y) {
        return 1;
    } else {
        return 0;
    }
}
