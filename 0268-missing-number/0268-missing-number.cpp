class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // find sum of total number from 0 to n
        int totalSum = n * (n + 1) / 2;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        return totalSum - sum;
    }
};