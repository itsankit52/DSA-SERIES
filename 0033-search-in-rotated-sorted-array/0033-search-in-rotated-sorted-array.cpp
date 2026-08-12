class Solution {
public:
    int search(vector<int>& nums, int target) {
        // OPTIMAL : Using Binary Search 
        // TIME : O(logn), SPACE : O(1)

        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // If  target is found
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[left] <= nums[mid]) { // Left part 
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1; 
                }
                } 
            else { // Right part 
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1; 
                }
            }
        }

        // not found
        return -1;


        // BRUTE FORCE : Traverse Array From 0 to array size - 1
        // TIME : O(n), SPACE : O(1)
        // for(int i =0; i < nums.size();i++){
        //     if(nums[i] == target){
        //         return i;
        //     }
        // }
        // return -1;
    }
};
