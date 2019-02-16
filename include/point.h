/*
 *  Point ADT Interface
 * ----------------------------------------------------------------------------
 *  All prototypes of functions that manipulate the point data structure.
 * ----------------------------------------------------------------------------
 *  Author: Renan Bomtempo
 * ----------------------------------------------------------------------------
 */
#ifndef POINT_H
#define POINT_H

typedef struct Point {
    int x;
    int y;
}   point;

/*
 * Set the X and Y values of a point.
 */
void SetPointCoordinates ( point *p, int x, int y );

#endif // POINT_H
