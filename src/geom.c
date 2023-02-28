#include <stdio.h>
#include <stdlib.h>
#include "geom.h"

// WTK OGC: http://docs.opengeospatial.org/is/18-010r7/18-010r7.html#33
// OGC crs: https://docs.opengeospatial.org/as/18-005r4/18-005r4.html
// https://en.wikipedia.org/wiki/Well-known_text_representation_of_geometry



/**
 * @brief      Prints a bounding box.
 *
 * @param      bbox  The bounding box
 */
void print_bbox(AABB *bbox)
{
	printf("bbox: ((%d, %d), (%d, %d)) \n", 
		bbox->ul.x, 
		bbox->ul.y,
		bbox->lr.x,
		bbox->lr.y
	);
}


/**
 * @brief      Calculate midpoint of Axis Aligned Bounding Box
 *
 * @param      bbox  The bounding box
 *
 * @return     Point2D struct of midpoint
 */
Point2D bbox_midpoint(AABB *bbox)
{
	//Point((self.rx + self.lx) / 2, (self.ty + self.by) / 2)
	Point2D midpoint;
	midpoint.x = (bbox->ul.x + bbox->lr.x) / 2;
	midpoint.y = (bbox->ul.y + bbox->lr.y) / 2;

	return  midpoint;
}

