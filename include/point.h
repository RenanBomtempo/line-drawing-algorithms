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

/*
 * Returns 1 if the given points are the same. Else returns 0.
 */
char IsSamePoint (point p1, point p2);


#endif // POINT_H
