#include<iostream>
#include<map>
#include <set>
#include <algorithm>
using namespace std;

//char bmp(char &a,char &b)
//{
//    return a>b? a:b;
//}

int main()
{
//    std::map<std::string, int> test_map = {
//        {"how", 3},
//        {"are", 4},
//        {"you", 5}
//    };
//
//    std::map<std::string, int >::iterator iter_string_int;
//    std::string key_string = "shit";
//    iter_string_int = test_map.find(key_string);
//    if(iter_string_int == test_map.end())
//    {
//        std::cout << "error" << endl;
//    }
//    else
//    {
//        std::cout << iter_string_int->second << std::endl;
//    }

    //set
    set<char> s;
    s.insert('a');
    s.insert('k');
    s.insert('v');
    s.insert('c');
    sort(s.begin(),s.end(),[](char a,char b){return a>b? a: b;});
    for(auto &ff:s)
        cout << ff <<endl;



    return 0;
}
