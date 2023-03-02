#ifndef GEOM_H
#define GEOM_H 

#include <stdint.h>

typedef struct {
	uint32_t x;
	uint32_t y;
} Point2D;


/**
 * Axis Aligned Bounding Box
 * @param ul Upper left point 
 * @param lr Lower right point
 */
typedef struct {
	Point2D ul;  // Upper left (x, y)
	Point2D lr;  // Lower right (x, y)
} AABB;


typedef struct 
{
	float x;
	float y;
	float z;
} Point3D_f;

#endif
