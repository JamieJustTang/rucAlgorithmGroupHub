#include <iostream>
#include <vector>

using namespace std;

// 重新换成遍历递增法试试
void update(vector<vector<int>> &mat,int x,int y,int count){
    // 如果为合理数字，则更新其周围的数字
    int minx=mat[x][y]+1;
    if(x>0) {
        if(0>mat[x-1][y]){
            mat[x-1][y]=minx;   
            count--;
        }
    }
    if(y>0) {
        if(0>mat[x][y-1]){
            mat[x][y-1]=minx;
            count--;
        }
    }
    if(x<mat.size()-1) {
        if(0>mat[x+1][y]){
            mat[x+1][y]=minx;
            count--;
        }
    }
    if(y<mat[0].size()-1){
        if(0>mat[x][y+1]){
            mat[x][y+1]=minx;
            count--;

        }
    }
}
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int no=0;
    int count = 0;
    int m = mat.size();
    int n = mat[0].size();

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]){
                mat[i][j]=-1;  // 1 -> -1
                count++;
            }
        }
    }
    while(count){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==no){ // 处理数字
                    update(mat,i,j,count);
                }
            }
        }
    }

    return mat;
    
}

int main()
{

    return 0;
}