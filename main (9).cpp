/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        int dp[n], ans = 0;
        vector<pair<int, int>> players;
        for(int i = 0; i < n; i++) 
            players.push_back({ages[i], scores[i]});
        sort(players.begin(), players.end());
        for(int i = 0; i < n; i++) {
            dp[i] = players[i].second;
            for(int j = 0; j < i; j++) {
                if(players[j].second <= players[i].second)
                    dp[i] = max(dp[i], dp[j] + players[i].second);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};