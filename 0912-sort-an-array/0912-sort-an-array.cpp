class Solution {
public:
    // Function to merge two sorted halves of the array
    void merge(vector<int>& nums, int start, int mid, int end) {

        // Temporary vector to store merged elements
        vector<int> temp;

        int left = start;
        int right = mid + 1;

        // Compare elements from both subarrays
        // and store the smaller one in temp
        while (left <= mid && right <= end) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        // Copy remaining elements from left subarray
        while (left <= mid)
            temp.push_back(nums[left++]);

        // Copy remaining elements from right subarray
        while (right <= end)
            temp.push_back(nums[right++]);

        // Copy the merged sorted elements, back into the original array
        for (int k = start; k <= end; k++) {
            nums[k] = temp[k - start];
        }
    }

    // Recursive Merge Sort function
    void mergeSort(vector<int>& nums, int start, int end) {

        // Base case
        if (start >= end)
            return;

        // Find mid
        int mid = start + (end - start) / 2;

        // Sort the left half
        mergeSort(nums, start, mid);
        // Sort the right half
        mergeSort(nums, mid + 1, end);
        // Merge the two sorted halves
        merge(nums, start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};