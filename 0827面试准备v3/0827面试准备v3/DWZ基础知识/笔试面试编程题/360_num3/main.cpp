#include <iostream>
#include <algorithm>
using namespace std;

//360ÊýÖµÌâ

int main()
{
    int a,b;
    int cnt = 0;
    int pos ;
    int maxcnt = 0;
    while(cin >> a >> b)
    {
       for(int i=1 ; i<=a ; i++)
        {
            if(i == b) continue;
           for(int j=1 ; j<=a ; j++)
            {

               if(abs(b-j)>abs(i-j))
               {
                   cnt ++;
               }
            }
            if(cnt > maxcnt)
            {
                maxcnt = cnt;
                cnt = 0;
                pos = i;
            }
        }
        cout << pos <<endl;
    }
    return 0;
}
