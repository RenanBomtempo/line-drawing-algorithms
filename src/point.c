/*
 *  Point ADT Implementation
 * ----------------------------------------------------------------------------
 *  All implementations of functions that manipulate the point data structure.
 * ----------------------------------------------------------------------------
 *  Author: Renan Bomtempo
 * ----------------------------------------------------------------------------
 */
#include "point.h"

void SetPointCoordinates ( point *p, int x, int y ) 
{
    p->x = x;
    p->y = y;
}