class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> minimum;
        
        if(triangle.empty())
            return 0;
            
        minimum.push_back(triangle[0][0]);
        
        for(int i = 1; i < triangle.size(); i++) {
            int prev1 = minimum[0];
            
            minimum[0] += triangle[i][0];
            
            for(int j = 1; j < triangle[i].size() - 1; j++) {
                int prev2 = minimum[j];
                minimum[j] = triangle[i][j] + min(prev2, prev1);
                prev1 = prev2;
            }
            
            minimum.push_back(prev1 + triangle[i].back());
        }
        
        return *min_element(minimum.begin(), minimum.end());
    }
};
