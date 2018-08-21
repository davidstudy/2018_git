#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    /*
    vector<int> vec1 = {21,14,31,6,13,2};//初始化
    vector<int> vec2(10,2);//初始化10个2
    vector<int> vec = {2,4,1,6,3};
    vector<int> v2 ;
    v2.assign(vec.begin(),vec.end()-2);//指定赋值
    vec.swap(vec1);//交换两个向量值
    vector<int>::iterator it = vec1.begin();//迭代器
    it += 3 ;
    it = vec1.insert(it,999);//插入一个元素，迭代器在最新处
    cout << *it <<endl;
    it = vec1.erase(it);//删除一个元素，迭代器指向+1
    cout << *it <<endl;
    */

    //创建vec[3][4]
    vector<vector<int>> vec(3);//row
    for(int i=0 ; i<vec.size() ; i++)
    {
        vec[i].resize(4);//col
    }



    return 0;
}
