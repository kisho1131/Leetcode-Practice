class Solution {
public:
    int visited[200][200];
    void setRowCol(vector<vector<int>>& mat, int row, int col){
        for(int i = 0;i<mat[0].size();i++){ 
            if(mat[row][i] == 0 and col != i){
                continue;
            }
            visited[row][i] = 1;
            mat[row][i] = 0;
        }
        for(int j = 0;j<mat.size();j++){
            if(mat[j][col] == 0 and row !=j){
                continue;
            }
            mat[j][col] = 0;
            visited[j][col] = 1;
        }
    }
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        //vector<vector<int>>visited;
        memset(visited, 0, sizeof(visited));
        for(int row = 0;row<n;row++){
            for(int col = 0;col<m;col++){
                if(mat[row][col] == 0 and visited[row][col] == 0){
                    cout<<row<<"->"<<col<<endl;
                    setRowCol(mat, row, col);
                    
                }
                    
            }
        }
    }
};