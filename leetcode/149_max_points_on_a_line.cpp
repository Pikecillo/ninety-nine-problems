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
        if(points.size() < 3)
            return points.size();
        
        int max = 2;
        
        if(all_of(points.begin(), points.end(),
                  [&points](const Point &s){
		      return s.x == points.cbegin()->x
			  && s.y == points.cbegin()->y; })) {
            return points.size();
        }
        
        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
		
                int curr = 2;
                int dxij = points[j].x - points[i].x;
                int dyij = points[j].y - points[i].y;
                
                if(dxij == 0 && dyij == 0)
                    continue;
                
                for(int k = 0; k < points.size(); k++) {
                    if(k == i || k == j)
                        continue;
		    
                    int dxik = points[k].x - points[i].x;
                    int dyik = points[k].y - points[i].y;
                    
                    if(dxij == 0 && dxik == 0)
                        curr++;
                    else if(dyij == 0 && dyik == 0)
                        curr++;
                    else if(dxij * dyik == dxik * dyij)
                        curr++;
                }
                
                if(curr > max) max = curr;
            }
        }
        
        return max;
    }
};
