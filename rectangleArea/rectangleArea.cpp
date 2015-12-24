// Source : https://leetcode.com/problems/rectangle-area/
// Author : weekend27
// Date   : 2015-12-24

/**********************************************************************************

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Assume that the total area is never beyond the maximum possible value of int.

**********************************************************************************/

// How to do it:
// ref: http://bookshadow.com/weblog/2015/06/08/leetcode-rectangle-area/
/*
题目大意：
计算二维平面上两个直线矩形的覆盖面积。

矩形通过其左下角和右上角的坐标进行定义。

假设总面积不会超过int的最大值。

解题思路：
简单计算几何。根据容斥原理：S(M ∪ N) = S(M) + S(N) - S(M ∩ N)

题目可以转化为计算矩形相交部分的面积

S(M) = (C - A) * (D - B)

S(N) = (G - E) * (H - F)

S(M ∩ N) = max(min(C, G) - max(A, E), 0) * max(min(D, H) - max(B, F), 0)
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (D - B) * (C - A) + (H - F) * (G - E);
        if (A >= G || B >= H || C <= E || D <= F)
        {
            return area;
        }

        int top = min(D, H);
        int right = min(C, G);
        int bottom = max(B, F);
        int left = max(A, E);

        return area - (top - bottom) * (right - left);
    }
};
