// Source : https://leetcode.com/problems/max-points-on-a-line/
// Author : weekend27
// Date   : 2015-12-22

/**********************************************************************************

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

**********************************************************************************/

// How to do it:
// ref: https://leetcode.com/discuss/9011/c-o-n-2-solution-for-your-reference
/*
Hint by @stellari

"For each point pi, calculate the slope of each line it forms with all other points with greater indices, i.e. pi+1, pi+2, ..., and use a map to record how many lines have the same slope (If two lines have the same slope and share a common point, then the two lines must be the same one). By doing so, you can easily find how many points are on the same line that ends at pi in O(n). Thus the amortized running time of the whole algorithm is O(n^2)."

In order to avoid using double type(the slope k) as map key, I used pair (int a, int b) as the key where a=pj.x-pi.x, b=pj.y-pi.y, and k=b/a. Using greatest common divider of a and b to divide both a, b ensures that lines with same slope have the same key.

I also handled two special cases: (1) when two points are on a vertical line (2) when two points are the same.
*/


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() < 2){
            return points.size();
        }

        int result = 0;

        for (int i = 0; i < points.size(); i++){
            map<pair<int, int>, int> lines;
            int localmax = 0, overlap = 0, vertical = 0;

            for (int j = i + 1; j < points.size(); j++){
                if (points[j].x == points[i].x && points[j].y == points[i].y){
                    overlap++;
                    continue;
                }
                else if (points[j].x == points[i].x){
                    vertical++;
                }
                else {
                    int a = points[j].x - points[i].x;
                    int b = points[j].y - points[i].y;
                    int gcd = GCD(a, b);

                    a /= gcd;
                    b /= gcd;

                    lines[make_pair(a, b)]++;
                    localmax = max(lines[make_pair(a, b)], localmax);
                }

                localmax = max(vertical, localmax);
            }

            result = max(result, localmax+overlap+1);
        }

        return result;
    }

private:
    int GCD(int a, int b){
        if (b == 0){
            return a;
        }
        else {
            return GCD(b, a%b);
        }
    }
};
