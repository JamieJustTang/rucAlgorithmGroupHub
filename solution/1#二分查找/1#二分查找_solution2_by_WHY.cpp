#include<iostream>
#include<cmath>
using namespace std;
int nums[10000];
int main()
{
int k,target,n;
cin>>n;//������ ���ݸ���  
for(int j=1;j<=n;j++)
cin>>nums[j];//�������� 
cin>>target;//����Ŀ��
if(target>nums[n]||target<nums[1]){cout<<-1;return 0;}//���ж�n�ǲ��������½�� 
double m;m=log(n)/log(2);//���Ҵ���m��ʹ��2��m�η�>n����С����������cmath�������û��׹�ʽ����mֵ��Ȼ��Ϊ�˱��գ������ٶ����1�� 
int L=1,R=n;//��ʾ����������Ͻ���½磻 ��ʼ�½���һ����ʼ�Ͻ���n  
for(int j=1;j<=m+1;j++)//��һ��n��������в��϶��ֲ��ң�ǿ��ת��double ��int ,j�����ֵʵ������m������ȡ����
{
    if(nums[(R+L)/2]==target){cout<<(R+L)/2;break;} //��򵥵���� target�������м� 
    int mid=(R+L)/2; bool b; //���bool���������ж�target�ܷ��ҵ� 
    nums[mid]>target?b=(nums[mid-1]<target):b=(nums[mid+1]>target);//�����Ŀ����������þ����ж�target�Ƿ�λ���������ڵ���֮�䣻��b=1��˵��target���������������Ԫ��֮�䣬˵��Ӧ�����-1 
    if(b==1){cout<<-1;break;}
    nums[mid]>target?R=mid-1:L=mid+1;   //�����Ŀ����������ж�targetλ��mid����߻����ұߣ������ƶ���Ӧ�ı߽� -1��+1�ֱ���Ϊ�˱�֤���������ÿһ��Ԫ��  



}

return 0;
}
