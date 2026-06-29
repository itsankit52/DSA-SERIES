class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Based on binary search
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                 left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};