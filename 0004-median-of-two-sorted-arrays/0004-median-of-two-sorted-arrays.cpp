class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Optimal : using binary search partitions

        // binary search on smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        // Calculate left partition size
        int leftSize = (nums1.size() + nums2.size() + 1) / 2;
        int low = 0, high = nums1.size();

        while (low <= high) {
            // Find partition positions
            int partition1 = (low + high) / 2,
                partition2 = leftSize - partition1;

            // Find boundary elements
            int L1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1],
                R1 = (partition1 == nums1.size()) ? INT_MAX : nums1[partition1],
                L2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1],
                R2 = (partition2 == nums2.size()) ? INT_MAX : nums2[partition2];

            // Check correct partition
            if (L1 <= R2 && L2 <= R1) {
                // Odd total elements
                if ((nums1.size() + nums2.size()) % 2 == 1)
                    return max(L1, L2);
                // Even total elements
                return (max(L1, L2) + min(R1, R2)) / 2.0;
            }

            // Move partition
            else if (L1 > R2)
                high = partition1 - 1;
            else
                low = partition1 + 1;
        }

        return 0.0;

        // Brute Force :
        // Step 1: Merge both array in a new array
        // step 2: Sort the new array
        // step 3: find median :
        // step 3.1: if size if odd then simply return "size/2"
        // step 3.2: else size is even then return "(size/2) + ((size/2)-1) / 2"
        // vector<int> newArr;

        // // Merge both arrays
        // for (int num : nums1)
        //     newArr.push_back(num);

        // for (int num : nums2)
        //     newArr.push_back(num);

        // // Sort the new array
        // sort(newArr.begin(), newArr.end());
        // int n = newArr.size();

        // // Find median
        // if (n % 2 == 1)
        //     return newArr[n / 2];
        // else
        //     return (newArr[n / 2 - 1] + newArr[n / 2]) / 2.0;
    }
};