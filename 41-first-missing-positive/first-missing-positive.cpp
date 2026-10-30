class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int curr;
        int temp;
        while (i < nums.size()){
            curr = nums[i];

            while (curr > 0 && curr <= nums.size() && nums[curr -1 ] != curr) {
                temp = nums[curr -1];
                nums[curr-1] = curr;
                curr = temp; 
            }
            if 
            (nums[i] != i + 1 && nums[i] <= nums.size()) nums[i] =-1;
            i++;
        }

        i = 0;
        while (i < nums.size()) {
            if (nums[i] != i + 1) break;
            i++;
        } 

        return i + 1;

    }
};