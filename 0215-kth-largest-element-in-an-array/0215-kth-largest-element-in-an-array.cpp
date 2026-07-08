class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Method 1 : Sorting Approach O(nlogn)
        int size = nums.size();
        sort(nums.begin(), nums.end());
        return nums[size - k];
    }
};