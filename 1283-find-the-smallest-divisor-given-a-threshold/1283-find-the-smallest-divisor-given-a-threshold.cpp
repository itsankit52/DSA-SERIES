class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int left = 1, right = *max_element(nums.begin(), nums.end()),
            ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long sum = 0;

            for (int j = 0; j < nums.size(); j++)
                sum = sum + ceil((double)nums[j] / mid);

            if (sum <= threshold) {
                ans = mid;
                right = mid - 1;
            }

            else
                left = mid + 1;
        }

        return ans;

        // int maxElement = *max_element(nums.begin(), nums.end());
        // for (int i = 1; i <= maxElement; i++) {
        //     int sum = 0;

        //     for (int j = 0; j < nums.size(); j++)
        //         sum = sum + ceil((double)nums[j] / i);

        //     if (sum <= threshold)
        //         return i;
        // }
        // return -1;
    }
};