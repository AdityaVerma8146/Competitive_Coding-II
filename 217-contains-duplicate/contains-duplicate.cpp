class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        if(numset.size()<nums.size()){
            return true;
        }
        return false;
    }
};