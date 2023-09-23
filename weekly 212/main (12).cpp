/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ans;

        for (int i = 0; i < n; i++) {
            int st = l[i];
            int en = r[i];
            ans.push_back(chk(nums, st, en));
        }

        return ans;
    }

    bool chk(vector<int>& s, int& st, int& end) {
        if (end - st <= 1) {
            return true; 
        }

        vector<int> subarray;
        for (int i = st; i <= end; i++) {
            subarray.push_back(s[i]);
        }

      
        sort(subarray.begin(), subarray.end());

        int common_diff = subarray[1] - subarray[0];
        for (int i = 1; i < subarray.size(); i++) {
            if (subarray[i] - subarray[i - 1] != common_diff) {
                return false;
            }
        }

        return true;
    }
};