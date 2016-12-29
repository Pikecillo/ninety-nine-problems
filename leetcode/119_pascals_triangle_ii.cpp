class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(1, 1);

        if(rowIndex == 0)
            return row;
        
        for(int i = 1; i <= rowIndex; i++) {
            int prev1 = 1;
            
            for(int j = 1; j < i; j++) {
                int prev2 = row[j];
                row[j] = row[j] + prev1;
                prev1 = prev2;
	    }
            
            row.push_back(1);
        }
        
        return row;
    }
};
