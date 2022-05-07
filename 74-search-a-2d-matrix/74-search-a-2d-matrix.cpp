class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        int col = matrix[0].size()-1;
        int i =0;
        int j = col;
        while(i >= 0 and j >=0 and i <= row and j <=col){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j]  > target)
                j--;
            else
                i++;
        }
        return false;
    }
};