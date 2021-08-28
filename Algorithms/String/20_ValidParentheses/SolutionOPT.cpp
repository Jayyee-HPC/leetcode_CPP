//Solution: backward position counter
//TEST: 0 ms 6.3 MB mem.

class Solution {
public:
    bool isValid(string s) {
        int j = 1, n;
        n = s.size();
        
        char a[n+1];
        
        a[1] = s[0];
        
        for (int i = 1; i < n; i++)
        {           
            if(s[i] == a[j]+1 || s[i] == a[j]+2)
            { 
                j--; 
            }
            else
            {   
                j++;
                a[j]=s[i];
            }
        }
        
        if(j == 0)
            return true;
        else
            return false;
    }
};;