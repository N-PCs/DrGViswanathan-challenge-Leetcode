class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map to store : <value, index>
        unordered_map<int, int> numMap;

        for(int i=0;i<nums.size();i++){
            int j= target-nums[i];          // setting j as complement

            // checking if j exists
            if(numMap.find(j) != numMap.end()){
                return {numMap[j], i};
            }
            // otherwise add current number and its index to map 
            numMap[nums[i]]=i;
        }
        // return empty vector if no solution found 
        return {};
    }
};

/* Brute Approach

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // Return empty if no solution is found
    }
};

*/
