/*
本题虽然简单，但却能说明很多问题：
1.DP
2.多组测试数据情况下，先一次性计算所有可能，然后每组测试数据直接读取
3.计算过程中数据溢出
4.
*/
#include <iostream>
#include <stdio.h>
using namespace std;
const int M=1000000000+7;
const int MAXN=100005;
long long f[MAXN];//数据类型为long long
int fac(int n){
    f[0]=1;//注意0的情况
    for(int i=1;i<=n;i++){        
        f[i] =f[i-1]*i % M;//乘法注意数据溢出
    }
    return f[n];
}
int main()
{
    int T,n;
    cin>>T;
    fac(MAXN);//先一次性算好否则时间复杂度T*N超时
    for(int i=0;i<T;i++){
        scanf("%d",&n);
        printf("%lld\n",f[n]);//long long 输出
    }
    return 0;
}
