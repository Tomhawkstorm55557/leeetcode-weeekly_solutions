/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
class Solution {
public:
 char slowestKey(vector<int>& rel, string keys) {
        
        int n = keys.size();
        vector<pair<int,char>> v;

        v.push_back({rel[0], keys[0]});

        for(int i=1;i<n;i++){
            v.push_back({rel[i]- rel[i-1], keys[i]});
        }

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        return v[0].second;
        

    }
};