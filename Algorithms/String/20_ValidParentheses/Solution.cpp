//First attempt: always remove first found close pair
//TEST: 28 ms 6.3 MB mem.

class Solution {
public:
    
    bool isValid(string s) {
        if (s.size() == 0)
            return true;
        
        if (s.size()%2 == 1)
            return false;
        
        string temp_str;
        temp_str = s;
                    
        while (1)
        {
             for (int i = 0; i < temp_str.size() - 1; ++i)
             {
                 if (temp_str[i] == '(' && temp_str[i+1] == ')' ||
                     temp_str[i] == '[' && temp_str[i+1] == ']' ||
                     temp_str[i] == '{' && temp_str[i+1] == '}')
                 {
                     if (temp_str.size() == 2)
                         break;

                     temp_str.erase(i,2);
                     i = 0;
                     continue;
                 }     
             }
            
            break;
        }        

        if (temp_str.size() == 0)
            return true;
        else if (temp_str.size() == 2)
        {
            if (temp_str[0] == '(' && temp_str[1] == ')' ||
                     temp_str[0] == '[' && temp_str[1] == ']' ||
                     temp_str[0] == '{' && temp_str[1] == '}')
              return true;                  
        }
        
        return false;
    }
};
