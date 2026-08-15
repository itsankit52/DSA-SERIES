class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high])
                low = mid + 1;

            else if (nums[mid] < nums[high])
                high = mid;

            else
                high--;
        }

        return nums[low];

        // In 153, nums[mid] vs nums[high] always tells which half to discard
        // in this ques  duplicates can make them equal, so may need high--
    }
};