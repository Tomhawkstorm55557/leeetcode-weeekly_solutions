/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        map<int, vector<pair<int, int>>> ele;

        // Store elements with the same value in a map
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                ele[mat[i][j]].push_back({i, j});
        }

        vector<int> rank(n + m, 0);

        for (auto itr : ele) {
            vector<int> parent(n + m);

            // Initialize parent vector
            iota(parent.begin(), parent.end(), 0);

            for (auto it : itr.second) {
                int i = it.first, j = it.second;
                int xroot = find_set(i, parent);
                int yroot = find_set(j + n, parent);

                // Union rows and columns
                parent[xroot] = yroot;

                // Update the rank
                rank[yroot] = max(rank[xroot], rank[yroot]);
            }

            vector<int> curr = rank;

            // Assign each cell its correct rank
            for (auto it : itr.second) {
                int i = it.first, j = it.second;
                int r = find_set(i, parent);

                ans[i][j] = 1 + rank[r];
                curr[i] = rank[r] + 1;
                curr[j + n] = rank[r] + 1;
            }

            swap(rank, curr);
        }

        return ans;
    }

private:
    int find_set(int x, vector<int>& parent) {
        if (parent[x] == x)
            return x;
        return parent[x] = find_set(parent[x], parent);
    }
};
