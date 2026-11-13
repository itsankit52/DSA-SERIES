class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Find maximum element in middle column
            int maxRow = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid])
                    maxRow = i;
            }

            int current = mat[maxRow][mid];

            // Left and right neighbors
            int left = (mid > 0) ? mat[maxRow][mid - 1] : -1;

            int right = (mid < n - 1) ? mat[maxRow][mid + 1] : -1;

            // Check peak condition
            if (current > left && current > right)
                return {maxRow, mid};
            // Search left half
            else if (left > current)
                high = mid - 1;
            // Search right half
            else
                low = mid + 1;
        }

        return {-1, -1};
    }
};