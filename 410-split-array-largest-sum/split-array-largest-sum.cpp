class Solution {
public:
    bool canAllocate(vector<int>& nums,int k,int m){
        int countstudent=1;
        long long pages=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>m)
             return false;
            if (pages+nums[i]<=m){
                pages+=nums[i];
            }else{
                countstudent++;
                pages=nums[i];
                if(countstudent>k)
                 return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size())
         return -1;
        int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(nums,k, mid)) {
            ans = mid;
            high = mid - 1; // try for smaller maximum
        } else {
            low = mid + 1;
        }
    }
    return ans;
    }
};