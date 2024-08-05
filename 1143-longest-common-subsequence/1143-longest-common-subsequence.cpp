class Solution {
public:
    int solveRec(string s1,string s2,int i,int j)
    {
        // base case
        if(i >= s1.size() || j >= s2.size())
        return 0;

        int ans = 0; // iska khi use nhi h bs ye store kr rha h ans ki value for every step
        if(s1[i] == s2[j]) // equal
        {
            ans = 1 + solveRec(s1,s2,i+1,j+1);
        }
        else // not equal
        {
            ans = 0 + max(solveRec(s1,s2,i,j+1),solveRec(s1,s2,i+1,j));
        }

        return ans;
    }
    int solveMemo(string &s1,string &s2,vector<vector<int>>& dp,int i,int j)
    {
        // base case
        if(i >= s1.size() || j >= s2.size())
        return 0;

        // if already present
        if(dp[i][j] != -1)
        return dp[i][j];

        // if equal
        if(s1[i] == s2[j])
        {
            dp[i][j] = 1 + solveMemo(s1,s2,dp,i+1,j+1);
        }
        else
        {
            dp[i][j] = 0 + max(solveMemo(s1,s2,dp,i,j+1),solveMemo(s1,s2,dp,i+1,j));
        }

        return dp[i][j];
    }
    // Tabulation (Bottom Up approach)
    int tabu(string s1,string s2,vector<vector<int>> &dp)
    {
        // base case ya fir starting of the method
        for(int i=0; i<=s1.size(); i++)
        {
            for(int j=0; j<=s2.size(); j++)
            {
                if(i == 0 || j == 0)
                dp[i][j] = 0;
                else if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }

        return dp[s1.size()][s2.size()];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // USING RECURSION - TLE
        // int ans = solveRec(text1,text2,0,0);
        // return ans;

        // USING MEMO
        // we will use 2D array bcoz i & j 2 variables are changing
        // vector<vector<int>> dp(text1.size()+1,vector<int> (text2.size()+1,-1));
        // int ans = solveMemo(text1,text2,dp,0,0);
        // return ans;

        // USING BOTTOM UP
        vector<vector<int>> dp(text1.size()+1,vector<int> (text2.size()+1,-1));
        int ans = tabu(text1,text2,dp);
        return ans;
    }
};