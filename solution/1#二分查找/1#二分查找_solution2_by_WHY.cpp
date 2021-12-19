#include<iostream>
#include<cmath>
using namespace std;
int nums[10000];
int main()
{
int k,target,n;
cin>>n;//先输入 数据个数  
for(int j=1;j<=n;j++)
cin>>nums[j];//输入数组 
cin>>target;//输入目标
if(target>nums[n]||target<nums[1]){cout<<-1;return 0;}//先判断n是不是在上下界里； 
double m;m=log(n)/log(2);//查找次数m是使得2的m次方>n的最小整数；调用cmath函数运用换底公式计算m值，然后为了保险，我们再多查找1次 
int L=1,R=n;//表示搜索区间的上界和下界； 初始下界是一，初始上界是n  
for(int j=1;j<=m+1;j++)//在一个n项的数列中不断二分查找；强制转换double 到int ,j的最大值实际上是m的向上取整。
{
    if(nums[(R+L)/2]==target){cout<<(R+L)/2;break;} //最简单的情况 target正好在中间 
    int mid=(R+L)/2; bool b; //这个bool变量用于判断target能否找到 
    nums[mid]>target?b=(nums[mid-1]<target):b=(nums[mid+1]>target);//这个三目运算符的作用就是判断target是否位于两个相邻的数之间；若b=1则说明target在数组的相邻两个元素之间，说明应该输出-1 
    if(b==1){cout<<-1;break;}
    nums[mid]>target?R=mid-1:L=mid+1;   //这个三目运算符用来判断target位于mid的左边还是右边，并且移动对应的边界 -1和+1分别是为了保证遍历数组的每一个元素  



}

return 0;
}
