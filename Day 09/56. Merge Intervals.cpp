class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort vector to find interval's start
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;     // for storing output

        // set initial variables for searching
        int val1=intervals[0][0];
        int val2=intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            int first=intervals[i][0];   // search begins
            int second=intervals[i][1];

            // update val2 (end) 
            if(val2>=first){
                val2=max(val2, second);
            }
            else{
            // finally push to result and reset val1, val2
                result.push_back({val1,val2});
                val1=first;
                val2=second;
            }
        }
        result.push_back({val1,val2});
        return result;
    }
};
