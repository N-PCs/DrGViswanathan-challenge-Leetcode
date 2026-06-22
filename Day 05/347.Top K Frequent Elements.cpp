/*
better O(n) approach
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for (int n : nums) {
            count[n] = 1 + count[n];
        }
        for (const auto& entry : count) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for (int i = freq.size() - 1; i > 0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};
*/

// simple but O(nlogn) approach 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int> result;
        // 1st case : base case i.e if only one element in nums
        if(nums.size()==1){
            return nums;
        }
        // freq vector to store {count,nums[i]}
        vector<pair<int,int>> freq;
        int count=1;
        // linear checking and consecutive counting
        for(int i=0;i<nums.size();i++){
            // if no duplicate element remaining
            if(i==nums.size()-1 || nums[i] != nums[i+1]){
                freq.push_back({count,nums[i]});
                count=1;
            }
            // duplicate element remaining
            else{
                count++;
            }
        }
        // sort freq in descending order
        sort(freq.rbegin(),freq.rend());
        // add k elements with highest counts to result
        for(int i=0;i<k;i++){
            result.push_back(freq[i].second);
        }
        return result;
    }
};
