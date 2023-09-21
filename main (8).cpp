/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        int n = s.size();
       int len =-1;
        for(int i =0;i<n;i++){
            for(int j=n-1;j>0;j--){
                if(s[i]==s[j]){
                len = max(len , j-i-1);
                }
            }
        }
           
            return len;
        
    }
};