class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // Brute force : Time Complexity -> O(n^2), Space Complexity -> O(n)
        /*
        int count = 0;
        for (int i =0 ; i< nums.size(); i++) {
            int sum = 0;
            for (int j = i ; j< nums.size(); j++){
                sum += nums[j];

                if (sum == k )
                    count ++;

            }
        }
        return count;
        */

        // Optimal Approach : TIme & Space Complexity -> O(n)
        unordered_map<int, int> mpp;
        int preSum = 0,count = 0;

        // prefix sum 0 has occurred once
        mpp[0] = 1;

        for (int num : nums) {
            // Update prefix sum
            preSum += num;

            // if there is a previous prefix sum
            if (mpp.find(preSum - k) != mpp.end()) 
                count += mpp[preSum - k];

            // Store current prefix sum
            mpp[preSum]++;
        }

        return count;
    }
};