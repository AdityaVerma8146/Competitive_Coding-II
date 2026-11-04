class Solution {
public:
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {
        // If we've reached the end of word1, we need to insert the remaining characters of word2
        if (i == word1.size()) return word2.size() - j;
        
        // If we've reached the end of word2, we need to delete the remaining characters of word1
        if (j == word2.size()) return word1.size() - i;
        
        // Return already computed result
        if (dp[i][j] != -1) return dp[i][j];
        
        // If characters match, no operation needed, move to next characters
        if (word1[i] == word2[j]) {
            return dp[i][j] = solve(i + 1, j + 1, word1, word2, dp);
        }
        
        // Otherwise, find the minimum cost among Insert, Delete, and Replace
        return dp[i][j] = 1 + min({
            solve(i + 1, j + 1, word1, word2, dp), // Replace
            solve(i, j + 1, word1, word2, dp),     // Insert
            solve(i + 1, j, word1, word2, dp)      // Delete
        });
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, word1, word2, dp);
    }
};