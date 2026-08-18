class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        // This question based on binary search
        // int size = nums.size()-1;
        // int left = 0, right = size;

        // while(left<right){
        //     int mid = left - (left - right) / 2;

        //     if(mid %2 == 1) mid --;

        //     if(nums[mid] == nums[mid+1])  left = mid + 2;

        //     else right = mid;
        // }
        // return nums[left];

        // ANOTHER METHOD :
        int size = nums.size();

        for (int i = 0; i < size; i++) {

            if (size == 1)
                return nums[0];

            if (i == 0) {
                if (nums[i] != nums[i + 1])
                    return nums[i];
            }
            else if (i == size - 1) {
                if (nums[i] != nums[i - 1])
                    return nums[i];
            }
            else {
                if (nums[i] != nums[i + 1] &&
                    nums[i] != nums[i - 1])
                    return nums[i];
            }
        }

        return -1;
    }
};