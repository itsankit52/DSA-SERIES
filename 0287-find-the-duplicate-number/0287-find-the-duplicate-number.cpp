class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // BINARY SEARCH :
        int left = 1, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2, count = 0;

            for (int num : nums) {
                if (num <= mid)
                    count++;
            }
            if (count > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left;

        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {

        //         if (nums[i] == nums[j])
        //             return nums[i];
        //     }
        // }
        // return -1;
    }
};