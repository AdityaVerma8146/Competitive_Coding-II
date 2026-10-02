class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> mp;
        int maxR = 0;

        for (int i = 0; i < requirements.size(); i++) {
            mp[requirements[i][0]] = requirements[i][1];
            maxR = max(maxR, requirements[i][1]);
        }

        vector<vector<int>> dp(n + 1, vector<int>(maxR + 5, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) { // length of array
            if (mp.count(i - 1)) {     // only 1 cell in this row will be >= 0. we need to fix one inversion count till this size acc to req
                int req = mp[i - 1];
                long long total = 0;

                // k is number of new inversions created after adding ith number in (i-1) prem
                // k = 0 is added , in this we place new elem at last, so no new inv
                // k = 1, 1 new inv created, we place new elem at 2nd last..
                // and so on, if k == i-1, we need i-1 inv, thne we have to place it to very first(new elem)
                // suppose, if if till i-1, inv count is 100, and at i, we need inv count 50, then we dont have any option, so go till req inv in dp[i-1].
                for (int k = 0; k < i && k <= req; k++) { // we only take those dp[i-1] where we we can make new inv count req after placing the new elem at some pos.
                    total = (total + dp[i - 1][req - k]) % MOD;
                }
                dp[i][req] = total;
            } else {
                long long total = 0;
                for (int j = 0; j <= maxR; j++) {
                    total = (total + dp[i - 1][j]) % MOD;
                    if (j >= i) {
                        // becox adding i will create at max (i-1) inversions.
                        // so suppose we add i = 10, then dp[i-1][x] will only contribute to 
                        // dp[i][x], dp[i][x+1], dp[i][x+2].....dp[i][x+9] it wont contribute to dp[i][x+10] and later
                        // so kind of sliding window
                        total = (total - dp[i - 1][j - i] + MOD) % MOD;
                    }
                    dp[i][j] = total;
                }
            }
        }

        return dp[n][mp[n - 1]];
    }
};