class Solution {
public:
    void recur(vector<int>& nums, int start, vector<int>& temp, vector<vector<int>>& res) {
        res.push_back(temp);

        for(int i=start; i<nums.size(); i++) {
            if(i > start && nums[i-1] == nums[i]) continue;

            temp.push_back(nums[i]);
            recur(nums, i+1, temp, res);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;

        sort(nums.begin(), nums.end());
        recur(nums, 0, temp, res);

        return res;
    }
};