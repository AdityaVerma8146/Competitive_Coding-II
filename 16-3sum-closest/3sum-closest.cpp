class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = INT_MAX, fd = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++) {
            int j = i+1, k = nums.size()-1;
                while(j<k){
                    int sum = nums[i]+nums[j]+nums[k];
                    int diff = abs(target-sum);
                    fd = min(diff,fd);
                    if(fd == diff){
                        ans = sum;
                    }
                    if(sum == target){
                        return target;
                    }
                    else if(sum < target){
                        j++;
                    }
                    else {
                        k--;
                    }
                }
        }
        return ans;
    }
};