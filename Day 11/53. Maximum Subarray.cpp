class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN; // Start with the lowest possible value
        int currentSum = 0;
        
        for (int num : nums) {
            currentSum += num; // Greedily add the current number
            
            if (currentSum > maxSum) {
                maxSum = currentSum; // Record if we found a new peak
            }
            
            if (currentSum < 0) {
                currentSum = 0; // Greedy Reset: Abandon this subarray because it's negative
            }
        }
        
        return maxSum;
    }
};
