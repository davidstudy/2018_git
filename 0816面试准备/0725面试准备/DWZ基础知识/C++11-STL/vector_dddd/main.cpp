#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;

int main()
{
//    vector<int> vec;
//    int a[] = {2,3,5,9};
//    vec.assign(a,a+4);
//    for(auto &k :vec)
//        cout << k <<endl;
//    cout << "Hello world!" << endl;
//    deque<int> qe;
//    qe.assign(a,a+4);
//     for(auto &k1 :qe)
//        cout << k1 <<endl;
    map<char,int> mp;
    mp['s'] = 13;
    mp['k'] = 12;
    mp['p'] = 11;
    mp['a'] = 111;
    map<char,int>::iterator it = mp.begin();
    for(auto &ff : mp)
        cout << ff.first <<" "<< ff.second <<endl;
    cout << "**************"<<endl;
    it = mp.find('b');
    if(it != mp.end())
        cout << it->first <<"  "<<it->second<<endl;
    cout << mp.end()->first<< mp.end()->second <<endl;

    return 0;
}
