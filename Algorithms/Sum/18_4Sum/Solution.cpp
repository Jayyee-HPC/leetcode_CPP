//First attempt: brute force
//TEST: 1950 ms 208.8 MB mem.

class Solution {
public:
    int binarySearch(vector<int>& arr, int l, int r, int x)
    {
        if (r >= l) {
            int mid = l + (r - l) / 2;

            // If the element is present at the middle
            // itself
            if (arr[mid] == x)
                return mid;

            // If element is smaller than mid, then
            // it can only be present in left subarray
            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);

            // Else the element can only be present
            // in right subarray
            return binarySearch(arr, mid + 1, r, x);
        }

    // We reach here when element is not
    // present in array
        return -1;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        
        int vect_size = nums.size();
        if (vect_size < 4)
            return results;
        
        for (int i = 0; i < vect_size; ++i)
        {
            int expect_val_1 = target - nums[i];
            for (int j = i + 1; j < vect_size; ++j)
            {
                if (nums[j] > expect_val_1/3)
                    break;
                
                int expect_val_2 = expect_val_1 - nums[j];
                
                for (int k = j + 1; k < vect_size; ++k)
                {
                    if (nums[k] > expect_val_2/2)
                        break;
                
                    int expect_val_3 = expect_val_2 - nums[k];
                    
                    int position = binarySearch(nums, k+1, vect_size-1, expect_val_3);
                    
                    if (position != -1)
                    {
                        vector<int> temp_vect;
                        temp_vect.push_back(nums[i]);
                        temp_vect.push_back(nums[j]);
                        temp_vect.push_back(nums[k]);
                        temp_vect.push_back(nums[position]);
                        
                        bool is_same_vect_exist = false;
                        for (int results_counter = 0; results_counter < results.size(); ++ results_counter)
                        {
                            if (results[results_counter] == temp_vect)
                            {
                                is_same_vect_exist = true;
                                break;
                            }
                        }

                        if (!is_same_vect_exist)
                            results.push_back(temp_vect);
                        
                        //results.push_back(temp_vect);
                    }
                }
            }
        }
        
        return results;
    }
};

