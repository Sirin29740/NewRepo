//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int y=matrix.size();
        int x=matrix[0].size();
        vector<int> ans;
        if(matrix.empty()||matrix[0].empty())return ans;
        order(ans,matrix,0,0,x,y);
        return ans;
    }
    void order(vector<int>& ans,vector<vector<int>>& matrix,int M,int N,int x,int y){
        
        if (M >= y || N >= x) return; // 基本条件，确保没有越界 
        int m=M,n=N;
        // 从左到右遍历
        for (int n = N; n < x; n++) ans.push_back(matrix[M][n]);
        M++;
        
        // 从上到下遍历
        for (int m = M; m < y; m++) ans.push_back(matrix[m][x - 1]);
        x--;

                if (M < y) {
            for (int n = x - 1; n >= N; n--) ans.push_back(matrix[y - 1][n]);
            y--;
        }
        
        // 从下到上遍历
        if (N < x) {
            for (int m = y - 1; m >= M; m--) ans.push_back(matrix[m][N]);
            N++;
        }


        order(ans,matrix,M,N,x,y);
        
        }
    
};


/*模拟法
class Solution {
private:
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns));
        int total = rows * columns;
        vector<int> order(total);

        int row = 0, column = 0;
        int directionIndex = 0;
        for (int i = 0; i < total; i++) {
            order[i] = matrix[row][column];
            visited[row][column] = true;
            int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
                directionIndex = (directionIndex + 1) % 4;
            }
            row += directions[directionIndex][0];
            column += directions[directionIndex][1];
        }
        return order;
    }
};

*/
