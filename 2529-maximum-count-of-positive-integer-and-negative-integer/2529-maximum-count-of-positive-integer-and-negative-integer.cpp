class Solution {
public:
    int maximumCount(vector<int>& nums) {

        // First element >= 0
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0)
                left = mid + 1;
            else
                right = mid;
        }
        int negetive = left;

        // First element > 0
        left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= 0)
                left = mid + 1;
            else
                right = mid;
        }
        int positive = nums.size() - left;

        return max(positive, negetive);
    }
};