class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> nums1,nums2;

        for(int i = 0; i < n-1; i++){
            nums1.push_back(nums[i]);
        }
        for(int i = 1; i < n; i++){
            nums2.push_back(nums[i]);
        }

        int ans1 = calculate(nums1.size()-1,nums1);
        int ans2 = calculate(nums2.size()-1,nums2);

        return max(ans1,ans2);
    }

    int calculate(int n, vector<int> nums){

        vector<int> dp(n+1, 0);

        dp[0] = nums[0];
        

        for (int i = 1; i <= n; i++) {
            int include,exclude;
            if(i-2 >= 0)include = nums[i] + dp[i-2];  
            else  include = nums[i];
            
            exclude = dp[i-1];

            dp[i] = max(include, exclude);
        }
        return dp[n];
    }
};
