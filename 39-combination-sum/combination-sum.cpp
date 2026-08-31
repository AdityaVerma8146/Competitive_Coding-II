class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        makecombo(candidates, target, 0, comb, 0, ans);
        return ans;
    }
    void makecombo(vector<int>& candidates, int target, int i,
                   vector<int>& comb, int combtotal, vector<vector<int>>& ans) {

        if (combtotal == target) {
            ans.push_back(comb);
            return;
        }

        if (combtotal > target) {
            return;
        }

        if (i >= candidates.size()) {
            return;
        }

        comb.push_back(candidates[i]);


        makecombo(candidates, target, i, comb, combtotal + candidates[i], ans);

        comb.pop_back();


        makecombo(candidates, target, i + 1, comb, combtotal, ans);
    }
};