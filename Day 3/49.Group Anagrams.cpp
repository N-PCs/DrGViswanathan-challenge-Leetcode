class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Look-up table: Key = sorted string (encoding), Value = list of original strings
        unordered_map<string, vector<string>> ans;

        // Loop through every string in the input array
        for (string& s : strs) {
            
            // STEP 1: Create a temporary copy of the string to preserve the original word
            string key = s;
            
            // STEP 2: Sort the copy alphabetically to create a unique "signature"
            sort(key.begin(), key.end());
            
            // STEP 3: Map the original string 's' into the bucket labeled by the sorted 'key'
            ans[key].push_back(s);
        }

        // 2D vector to store the final grouped results
        vector<vector<string>> result;

        // STEP 4: Loop through the hash map, grab each group of anagrams, and dump them into 'result'
        for (auto& entry : ans) {
            // entry.first is the sorted key (ignored)
            // entry.second is the vector of original words (collected)
            result.push_back(entry.second);
        }

        // Return the final formatted groups
        return result;
    }
};
