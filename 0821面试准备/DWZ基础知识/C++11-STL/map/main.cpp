#include <iostream>
#include <map>
using namespace std;

int main()
{
   map<char,int> mp;
   mp['S'] = 3;
   mp['A'] = 8;
   mp['k'] = 13;
   mp['m'] = 18;
   mp['m'] = 19;//覆盖之前那个
   mp.insert(mp.begin(),pair<char,int>('N',15));    //插入
   mp.insert(mp.begin(),make_pair('Z',11));
   map<char,int>::iterator it = mp.begin();
   mp.erase('k');//删除
   mp.erase(it);
   it = mp.find('m');//迭代器到‘m’
   if(it != mp.end()) cout <<"Find"<<endl;
   else cout <<"No Find"<<endl;
   cout << mp.count('m') <<endl;//可以判断是否为1找到 Find
   for(auto &i : mp)
        cout << i.first <<"  "<< i.second <<endl;



   return 0;
}
