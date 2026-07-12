class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort (nums.begin(), nums.end());

        // Dutch National flag
        int size = nums.size();
        int low = 0, mid = 0, high = size - 1;

        while (mid <= high) {

            // For 0
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            // For 1
            else if (nums[mid] == 1) {
                mid++;
            }

            // For 2
            //  (mid == 2)
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};