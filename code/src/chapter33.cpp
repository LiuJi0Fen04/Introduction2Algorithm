#include "chapter33.h"
#include "chapter13.h"

// ******************************************************************
// *                                                                *
// *                  COMPUTATIONAL GEOMETRY                        *
// *                - cross product                                 *
// *                - segment intersect                             *
// *                - segmentAboveAtX                               *
// *                - anySegmentsIntersects(to be finished)         *
// *                - segmentAboveAtX                               *
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
/// compare if the first segment is above another segment at x-coordinate x(the two segment are not vertical)
/// </summary>
/// <param name="ps1">the start point of segment 1</param> 
/// <param name="pe1"></param>
/// <param name="ps2"></param>
/// <param name="pe2"></param>
/// <param name="x"></param>
/// <returns></returns>
int segmentAboveAtX(point2f ps1, point2f pe1, point2f ps2, point2f pe2, float x)
{
	// instead of directly calculate y-coordinate y1(x) at x, we calculate y1(x) * (ps1.x - pe1.x) * (ps2.x - pe2.x)
	float y1multi = ((ps1.y - pe1.y) * (x - pe1.x) + pe1.y * (ps1.x - pe1.x)) * (ps2.x - pe2.x);
	float y2multi = ((ps2.y - pe2.y) * (x - pe2.x) + pe2.y * (ps2.x - pe2.x)) * (ps1.x - pe1.x);
	if ((ps2.x - pe2.x) * (ps1.x - pe1.x) > epsilon_f && y1multi > y2multi){
		return 1;
	}
	else if ((pe2.x - ps2.x) * (ps1.x - pe1.x) > epsilon_f && y1multi < y2multi) {
		return 1;
	}
	return 0;
}

/// <summary>
/// to find out if any pair of segement in S intersects
/// </summary>
/// <param name="S"></param>
/// <returns>if any pair intersects return 1</returns>
int anySegmentsIntersects(std::vector<std::pair<point2f, point2f>> S)
{
	// sort end points
	std::vector<point2f> end_points;
	std::vector<int> is_left;
	std::vector<int> belong_idx;
	//
	RBTree_Node* root = NULL; // this must be initialed
	for (int i = 0; i < end_points.size(); i++) {
		if (1 == is_left[i]) {
			RBTree_Node* s = createRBNode(belong_idx[i]);
			RBTreeInsert(&root, s); // 在插入的时候就已经使用segmentAboveAtX函数对x处的segment进行排序， 此时的红黑树需要做变形（每个节点存储当前直线的端点信息）
			
			// persudocode(below和above函数就是树中的前驱节点和后继节点)
			// 
			//if (above(s) exist and intersects(s)) {
			//	return 1;
			//}
			//else if (below(s) exist and intersects(s)) {
			//	return 1;
			//}
		}
		if (0 == is_left[i]) {
			//if (above(s) and below(s) exist and intersects with each other) {
			//	return 1;
			//}
			// delete
			RBTree_Node* s = RBTreeSearch(root, belong_idx[i]);
			RBTreeDelete(&root, s); 
		}
	}
	return 0;
}





// we assume that no input segmnet of  input is vertical 


// finding the convex hull
// Graham Scan(using the order of increasing polar angle and make sure there is no left turn, if so pop the point just push, until there is no left turn)
// Jarvis's march(the start point has the lowest y, and march from the loweest point to the highest from both right and left chain, each point has the smallest polar angle with respect of the last point)