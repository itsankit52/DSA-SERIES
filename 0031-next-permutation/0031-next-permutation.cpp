class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int pivot = -1;

        // Find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // No pivot
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find next greater element
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Reverse suffix
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};