class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            int low = 0, high = n - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (matrix[i][mid] == target)
                    return true;
                else if (matrix[i][mid] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return false;

        // for (int i = 0; i < matrix.size(); i++) {
        //     for (int j = 0; j < matrix[i].size(); j++) {
        //         if (matrix[i][j] == target)
        //             return true;
        //     }
        // }
        // return false;
    }
};