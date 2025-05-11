#ifndef _CHAPTER_33_
#define _CHAPTER_33_
#include <iostream>
#include "export_macro.h"
#include "common.h"
#include <limits>



//float epsilon_f = std::numeric_limits<float>::epsilon();


// ******************************************************************
// *                                                                *
// *                  COMPUTATIONAL GEOMETRY                        *
// *                - crose product                                 *
// *                - segment intersect                             *
// *                                                                *
// ******************************************************************

/// <summary>
/// calculate if line segment (p1, p2) and (p3, p4) are intersect with each other
/// </summary>
/// <param name="p1"> point1</param>
/// <param name="p2"></param>
/// <param name="p3"></param>
/// <param name="p4"></param>
/// <returns>if rtn value is 1 then the two line segment are intersect with each other, if 0 then not</returns> 
I2A_API int segementIntersect(point2f p1, point2f p2, point2f p3, point2f p4);


/// <summary>
/// determine how consecutive line segment vec(p0,p1) and vec(p1, p2) turn at  p1 
/// </summary>
/// <param name="p0"> the first point</param>
/// <param name="p1"></param> 
/// <param name="p2"></param>
/// <returns>if rtn value is positive then p0 makes a right turn at p1 and reach p2 </returns> 
I2A_API float direction(point2f p0, point2f p1, point2f p2);




#endif
