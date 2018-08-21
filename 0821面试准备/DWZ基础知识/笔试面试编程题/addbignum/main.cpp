#include <iostream>
#include <string>
using namespace std;

int str2int(string str)
{
    int len = str.length();
    int res = 0;
    for(int i=0 ; i<len ;i++)
    {
        res = res*10 +(str[i]-'0');
    }
    return res;
}

int* str2array(string str,int maxlen)
{
    int len = str.length();
    int *a = new int[maxlen];
    int i,j;
    for(i=0 ; i<(maxlen-len) ; i++)
    {
        a[i] = 0;
    }
    for(j=0; j<len ; i++,j++)
    {
        a[i] = str[j]-'0';
    }
    return a;
}

int main()
{
    string a,b;
    cin >> a >> b;//两个整数
    //做法1
//    int num1 = str2int(a);
//    int num2 = str2int(b);
//    long long sum = 0;
//    sum = num1 + num2;
//    cout << sum <<endl;
    //做法2
    int alen = a.length();
    int blen = b.length();
    int maxlen = alen>blen? alen+1:blen+1;
    int *num1 = str2array(a,maxlen);
    int *num2 = str2array(b,maxlen);
    int *sum = new int[maxlen];
    //手工加法
    int flag = 0 ;//进位
    for(int i=maxlen-1 ; i>=0 ; i--)
    {
        sum[i] = (num1[i]+num2[i])%10+flag;
        flag = (num1[i]+num2[i])/10;
    }
    for(int i=0 ; i<maxlen ; i++)
        cout << sum[i] ;
    return 0;
}
