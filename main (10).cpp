/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
class Solution {
public:
    
    unordered_set<string> visited; // to keep track of the strings visited
    
    bool already_visited(string s){
        
        return !(visited.find(s)==visited.end());
    }
    
    string add(string s, int a) {
        
        for(int i=1;i<s.size();i+=2) {
            
            s[i] = '0' + (s[i] -'0'+ a)%10;
            
        }
        return s;
        
    }
    
    string rotate(string s, int b) {
        
        reverse(s.begin(), s.end());
        
        reverse(s.begin(), s.begin()+b);
        reverse(s.begin()+b, s.end());
        
        return s;
        
    }
    
    void dfs(string s, string& ans, int a, int b) {
        
        if(already_visited(s)) {
            return;
        }
        visited.insert(s);
        ans = min(ans, s);
        
        dfs(add(s,a), ans, a, b);
        dfs(rotate(s,b), ans, a, b);
        
    }
    
    string findLexSmallestString(string s, int a, int b) {
        
        string ans = s;
        
        dfs(s, ans, a, b);
        return ans;
    }
};