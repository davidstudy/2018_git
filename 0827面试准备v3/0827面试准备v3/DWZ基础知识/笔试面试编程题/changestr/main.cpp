#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countdot(string &s)
{
    int len = s.length();
    int sum = 0;
    int seq_dot = 0;
    for(int i=0 ; i<=len ; i++)
    {
        if(s[i] == '.')
        {
            seq_dot++;
        }
        else
        {
            if(seq_dot>=1)
            {
                sum += (seq_dot-1);
                seq_dot = 0;
            }
        }
    }
    return sum;
}

int main()
{
    int n,m;
    string str;
    cin >> n >> m;
    cin >> str;
    vector<int> vec_x;
    vector<char> vec_c;
    int x; char c;
    for(int i=0 ; i<m ; i++)
    {
        cin >> x >> c;
        vec_x.push_back(x);
        vec_c.push_back(c);
    }
    for(int j=0 ; j<m ; j++)
    {
        str[vec_x[j]-1] = vec_c[j];
        //Êýµã
        cout << countdot(str) <<endl;
    }
    return 0;
}
