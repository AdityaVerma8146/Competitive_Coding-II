class Solution {
public:
    void findCombination(int index, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
        if(index == arr.size()) {
            if(target == 0) {
                ans.push_back(ds);
            }
            return;
        }        

        // add same index value if it is less than target
        if(arr[index] <= target) {
            ds.push_back(arr[index]);
            findCombination(index, target - arr[index], arr, ans, ds);
            
            // remove the last push element in case of no valid combination found
            ds.pop_back();  
        }
        
        // if value at current index is less than target, then move to next index
        findCombination(index+1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};