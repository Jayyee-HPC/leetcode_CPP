//First attempt: front back approach
//TEST: 44 ms 13.1 MB mem.

class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        int n=nums.size();
        
        if(n < 4) return results;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int target_2 = target-nums[i]-nums[j];
                int front=j+1, back=n-1;
                
                while(front<back)
                {
                    int two_sum=nums[front]+nums[back];
                    if(two_sum<target_2) 
                        front++;
                    else if(two_sum>target_2) 
                        back--;
                    else
                    {
                        vector<int> quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[front];
                        quad[3]=nums[back];
                        results.push_back(quad);
                        
                        while(front<back && nums[front]==quad[2]) 
                            front++;
                        while(front<back && nums[back]==quad[3]) 
                            back--;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j]) j++;
            }
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        
        return results;
        
    }
};