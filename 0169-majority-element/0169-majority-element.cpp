class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Method : 1 - Brute force approach
        /*
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == nums[i])
                    count++;
            }
            if (count > nums.size() / 2)
                return nums[i];
        }
        return -1;
        */

        // Method : 2 - Better than brute Force
        /*
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
              mpp[nums[i]]++;
        }
        for (auto it : mpp) {
            if (it.second > (nums.size() / 2)) {
                return it.first;
            }
        }
        return -1;
        */

        // Method : 3 - Optimal approach : Moore's voting algorithm
        int element = 0, count = 0;

        for (int num : nums) {
            if (count == 0)
                element = num;

            if (num == element)
                count++;

            else
                count--;
        }
        return element;
    }
};