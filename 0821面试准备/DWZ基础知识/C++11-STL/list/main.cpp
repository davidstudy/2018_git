#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    //建立一个链表
    list<int> m_list(10,2);//十个元素为2
    list<int> m_copylist(m_list);//复制链表
    //添加
    m_list.push_back(3);
    m_list.push_front(5);
    list<int>::iterator it = m_list.begin();
    it++;//支持自加自减 ； wrong ：it += 3
    it = m_list.insert(it,99);
    //删除
    m_list.pop_back();
    m_list.pop_front();
    it = m_list.erase(it);
    int kval = 919 ;
    it = find(m_list.begin(),m_list.end(),kval);//找到返回该迭代器值
    m_list.sort();

    for(auto &i :m_list)
        cout << i <<endl;


    return 0;
}
