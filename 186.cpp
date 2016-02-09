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
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        int res = 0;
        int n = points.size();
        for(int i = 0; i < n; i++){
            unordered_map<double, int> slopeCount;
            slopeCount[std::numeric_limits<double>::infinity()] = 0;
            int duplicate = 1;
            for(int j = i + 1; j < n; j++){
                if((points[i].x == points[j].x) && (points[i].y == points[j].y)){
                    duplicate++;
                }
                else if(points[i].x == points[j].x){
                    slopeCount[std::numeric_limits<double>::infinity()]++;
                }
                else{
                    double slope = (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                    slopeCount[slope]++;
                }
            }
            for(auto it = slopeCount.begin(); it != slopeCount.end(); it++){
                int numPoints = it->second + duplicate;
                if(numPoints > res){
                    res = numPoints;
                }
            }
        }
        return res;
    }
};
