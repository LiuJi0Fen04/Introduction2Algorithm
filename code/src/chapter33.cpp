#include "chapter33.h"


// ******************************************************************
// *                                                                *
// *                  COMPUTATIONAL GEOMETRY                        *
// *                - crose product                                 *
// *                - segment intersect                             *
// *                                                                *
// ******************************************************************

/// <summary>
/// note: the prerequisit of this func is p1, p2, p3 is on the same line 
/// </summary>
/// <param name="p0"></param>
/// <param name="p1"></param>
/// <param name="p2"></param>
/// <returns>if rtn value is 1 then p2 is on the segment (p0, p1)</returns> 
static int onSegement(point2f p0, point2f p1, point2f p2)
{
	if (p2.x > std::fminf(p0.x, p1.x)
		&& p2.x < std::fmaxf(p0.x, p1.x)
		&& p2.y > std::fminf(p0.y, p1.y)
		&& p2.y > std::fmaxf(p0.y, p1.y)) {
		return 1;
	}
	else
		return 0;
}

/// <summary>
/// calculate if line segment (p1, p2) and (p3, p4) are intersect with each other
/// </summary>
/// <param name="p1"> point1</param>
/// <param name="p2"></param>
/// <param name="p3"></param>
/// <param name="p4"></param>
/// <returns>if rtn value is 1 then the two line segment are intersect with each other, if 0 then not</returns> 
int segementIntersect(point2f p1, point2f p2, point2f p3, point2f p4)
{
	float turn23 = direction(p1, p2, p3);	// turn of (p2, p3)
	float turn24 = direction(p1, p2, p4);	// turn of (p2, p3)
	float turn41 = direction(p3, p4, p1);
	float turn42 = direction(p3, p4, p2);
	if (turn23 < epsilon_f && onSegement(p1, p2, p3)) {
		return 1;
	}
	else if (turn24 < epsilon_f && onSegement(p1, p2, p4)) {
		return 1;
	}
	else if (turn41 < epsilon_f && onSegement(p3, p4, p1)) {
		return 1;
	}
	else if (turn42 < epsilon_f && onSegement(p3, p4, p2)) {
		return 1;
	}
	else if (turn23 * turn24 < 0 && turn41 * turn42) {
		return 1;
	}
	return 0;
}

/// <summary>
/// determine how consecutive line segment vec(p0,p1) and vec(p1, p2) turn at  p1 
/// </summary>
/// <param name="p0"> the first point</param>
/// <param name="p1"></param> 
/// <param name="p2"></param>
/// <returns>if rtn value is positive then p0 makes a left turn at p1 and reach p2 </returns> 
float direction(point2f p0, point2f p1, point2f p2)
{
	point2f vec1 = p1 - p0;
	point2f vec2 = p2 - p0;
	return (vec1.x * vec2.y) - (vec1.y - vec2.x);
}

/// <summary>
/// to find out if any pair of segement in S intersects
/// </summary>
/// <param name="S">all the segements </param>
/// <returns>if any pair intersects return 1, verse visa</returns>
int anyLineItersection(std::vector<std::pair<point2f, point2f>> S)
{

	return 0;
}




// we assume that no input segmnet of  input is vertical 
