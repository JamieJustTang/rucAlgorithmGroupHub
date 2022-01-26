#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target);

int binarySearch(vector<vector<int>> &matrix, int col[2], int row[2], int target, int land[4]);

int main()
{
    int m, n, target;
    cin >> m >> n >> target;
    // int array[5][5]={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++)
    {
        vector<int> row = {};
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            row.push_back(temp);
        }
        matrix.push_back(row);
    }

    cout << (searchMatrix(matrix, target) > 0 ? "true" : "false") << endl;

    return 0;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int col[2] = {};
    col[1] = matrix[0].size() - 1;
    int row[2] = {};
    row[1] = matrix.size() - 1; // cpp doesn't allow narrowing convertions in list initialization
    int land[4] = {0, 0, row[1], col[1]};
    return binarySearch(matrix, col, row, target, land) > 0 ? true : false;
}

int binarySearch(vector<vector<int>> &matrix, int col[2], int row[2], int target, int land[4])
{
    if (matrix[row[0]][col[0]] == target || matrix[row[1]][col[1]] == target) // 确认两角
        return 1;
    if (-col[0] + col[1] - row[0] + row[1] <= 1)
    { // if only one element, test it and over.
        int isover = 0;
        // cout << "test " << matrix[row[0]][col[0]] << endl;
        isover = matrix[row[0]][col[0]] == target;
        if (-col[0] + col[1] - row[0] + row[1] == 1)
        {
            int flag = col[1] - col[0];
            // cout << "test " << matrix[row[0] + (flag ? 0 : 1)][col[0] + (flag ? 1 : 0)] << endl;
            isover |= matrix[row[0] + flag ? 0 : 1][col[0] + flag ? 1 : 0] == target;
        }
        // cout << "---" << endl;
        return isover;
    }
    if (col[0] + 1 == col[1] || row[0] + 1 == row[1]) // this is a question .... #TODO 2 slice
    {
        // ---- solution 1: failed --------
        // if into the specific row or col
        // enumerate it to get the target
        // for(int i=0;i<=col[1]-col[0];i++){ // the cols
        //     if(col[0]+i>= matrix[0].size()) break;
        //     for(int j=0;j<matrix.size();j++){
        //         if( matrix[j][col[0]+i]>target)   break;
        //         if(matrix[j][col[0]+i]==target)  return 1; // 找到了！

        //     }
        // }
        // for(int i=0;i<=row[1]-row[0];i++){
        //     if(row[0]+i>=matrix.size()) break;
        //     for(int j=0;j<matrix[0].size();j++){
        //         if(matrix[row[0]+i][j]==target) return 1;// find it!
        //         if(matrix[row[0]+i][j]>target)  break;
        //     }
        // }

        // ---- solution 2：
        // nope, we should use binarySearch again.
        // because either of left-bottom or right-top area is possible!
        // but i need a proper condition to stop this cross-selection.

        int lbrow[2] = {row[0] + 1, land[2]}; // land: r1 c1 , r2 c2
        int lbcol[2] = {land[1], col[1] - 1};
        int lbland[4] = {lbrow[0], lbcol[0], lbrow[1], lbcol[1]};
        int rtrow[2] = {land[0], row[1] - 1};
        int rtcol[2] = {col[0] + 1, land[3]};
        int rtland[4] = {rtrow[0], rtcol[0], rtrow[1], rtcol[1]};
        return (matrix[lbrow[0]][lbcol[0]] <= target ? binarySearch(matrix, lbcol, lbrow, target, lbland) : 0) || (matrix[rtrow[1]][rtcol[1]] >= target ? binarySearch(matrix, rtcol, rtrow, target, rtland) : 0); // cannot find it.
    }
    // by default, the 0,0  m-1,n-1 points are not target, we'll check that before this function
    int mid[2] = {}; // row ,col
    mid[0] = int((row[1] + row[0]) / 2);
    mid[1] = int((int(col[1] + col[0]) / 2));
    // cout << "see " << matrix[mid[0]][mid[1]] << endl;
    if (matrix[mid[0]][mid[1]] == target)
    {
        return 1;
    }
    if (matrix[mid[0]][mid[1]] < target)
    { // target is in the right-bottom area
        int ncol[2] = {mid[1], col[1]};
        int nrow[2] = {mid[0], row[1]};
        return binarySearch(matrix, ncol, nrow, target, land);
    }
    else
    { // target is in the left-top area
        int ncol[2] = {col[0], mid[1]};
        int nrow[2] = {row[0], mid[0]};
        return binarySearch(matrix, ncol, nrow, target, land);
    }
}