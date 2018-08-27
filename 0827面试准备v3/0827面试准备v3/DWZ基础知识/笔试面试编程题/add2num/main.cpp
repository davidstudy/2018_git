#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
void bigdataadd(char *da,char *db)
{
 int la=strlen(da);
 int lb=strlen(db);
 int max=la>lb?la:lb;
 vector<int> stra(max);
 vector<int> strb(max);
 for (int i=0;i<la;i++)
 {
  stra[i]=da[la-1-i]-'0';
 }
 for (int i=0;i<lb;i++)
 {
  strb[i]=db[lb-1-i]-'0';
 }
 vector<int> pre(max+1);
 for (int i=0;i<max;i++)//注意此处的循环范围
 {
  pre[max-i]=pre[max-i]+stra[i]+strb[i];
  if (pre[max-i]>9)
  {
   pre[max-i]-=10;
   pre[max-i-1]++;
  }
 }
 int m=0;
 while(pre[m]==0){ m++;}
 for (int j=m;j<max+1;j++)
 {
  cout<<pre[j];
 }
// cin.get();
}
int main()
{
 char sa[100]={0},sb[100]={0};
 cin>>sa>>sb;
 bigdataadd(sa,sb);
// cin.get();
    return 0;
}
