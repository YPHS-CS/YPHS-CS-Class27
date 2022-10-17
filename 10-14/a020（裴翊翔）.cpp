/*
A=10 台北市     J=18 新竹縣     S=26 高雄縣
      B=11 台中市     K=19 苗栗縣     T=27 屏東縣
      C=12 基隆市     L=20 台中縣     U=28 花蓮縣
      D=13 台南市     M=21 南投縣     V=29 台東縣
      E=14 高雄市     N=22 彰化縣     W=32 金門縣
      F=15 台北縣     O=35 新竹市     X=30 澎湖縣
      G=16 宜蘭縣     P=23 雲林縣     Y=31 陽明山
      H=17 桃園縣     Q=24 嘉義縣     Z=33 連江縣
      I=34 嘉義市     R=25 台南縣
*/
#include <iostream>
#include <map>
using namespace std;

    
int main(void)
{
    int al[]={1,10,19,28,37,46,55,64,39,73,64,2,11,20,48,29,38,47,56,65,74,83,21,3,12,30};//-41
    string test;
    int sum;
    while(cin>>test)
    {
        sum=0;
        sum+=al[(int)test[0]-65];
        for(int i=1;i<=8;i++)
            sum+=( (int)test[i]-48 )*(9-i);
        sum+=(int)test[9]-48;
        if(sum%10 == 0)
            printf("real\n");
        else
            printf("fake\n");
    }

    return 0;
}
