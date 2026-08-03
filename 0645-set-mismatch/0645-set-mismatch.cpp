class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate = -1, missing = -1;

        // Find duplicate
        for (int i = 0; i < nums.size(); i++) {
            int j = abs(nums[i]) - 1;

            if (nums[j] < 0)
                duplicate = abs(nums[i]);
            else
                nums[j] = nums[j]* -1;
        }

        // Find missing
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                missing = i + 1;
                break;
            }
        }

        return {duplicate, missing};
    }
};