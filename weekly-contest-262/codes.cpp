// weekly-contest-262 
// 10 OCT 2021

// https://leetcode.com/contest/weekly-contest-262/problems/two-out-of-three/
// 2032. Two Out of Three

class Solution {
public:
    bool search(vector<int>&nums,int k)
    {
        for(auto ele: nums)
        {
            if(ele==k) return true;
        }
        return false;
    }
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> s;
        for(auto ele: nums1)
            s.insert(ele);
        for(auto ele: nums2)
            s.insert(ele);
        for(auto ele: nums3)
            s.insert(ele);
        
        vector<int> temp;
        for(auto ele: s)
            temp.push_back(ele);
        
        vector<int> ans;
        
        for(auto ele: temp)
        {
            // if(search(nums1,ele)) and search(nums2,ele) and search(nums3,ele))
            //     ans.push_back(ele);
            
            if(search(nums1, ele))
            {
                if(search(nums2,ele) or search(nums3,ele))
                    ans.push_back(ele);
            }
            else if(search(nums2,ele))
            {
                if(search(nums1,ele) or search(nums3,ele))
                    ans.push_back(ele);
            }
            else if(search(nums3,ele))
            {
                if(search(nums2,ele) or search(nums1,ele))
                    ans.push_back(ele);
            }
        }
        return ans;
    }
};

//
//

