/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        
        vector<vector<int>> total_diff(n, vector<int>(m, INT_MAX));
        const vector<int> delrow = {-1, 0, 1, 0};
        const vector<int> delcol = {0, 1, 0, -1};
        
        while (!pq.empty()) {
            int wt = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == n - 1 && col == m - 1)
                return wt;
            if (wt >= total_diff[row][col])
                continue;
            total_diff[row][col] = wt;

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    int diff = abs(heights[nrow][ncol] - heights[row][col]);
                    pq.push({max(diff, wt), {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};
