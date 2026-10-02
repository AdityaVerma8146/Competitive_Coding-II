class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        uniqueSubsets(0,nums,subset,ans,n);
        return ans;
    }
    void uniqueSubsets(int index,vector<int> &nums,vector<int> &subset,vector<vector<int>> &ans,int n){
        ans.push_back(subset);
        for(int i=index;i<n;i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            //if(nums[i]>target) break; this condition does not exist in this question bcz we are generating all unique subsets.
            subset.push_back(nums[i]);
            uniqueSubsets(i+1,nums,subset,ans,n);
            subset.pop_back();
        }
    }
};