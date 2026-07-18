class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's Algorithm
        if (nums.size() == 0)
            return 0;

        int sum = nums[0], maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maxSum = max(maxSum + nums[i], nums[i]);
            sum = max(sum, maxSum);
        }

        return sum;
    }
};