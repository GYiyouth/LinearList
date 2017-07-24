#include <iostream>
#include "Node.h"
#include "LinearList.h"
#include "SimpleLinearList.h"
using namespace std;


//交换
template <class T>
void changeLength(T * & a, const int oldLength, const int newLength){
    if (newLength < 0){
        throw exception();
    }
    T* temp = new T[newLength];
    int number = min(oldLength, newLength);
    copy(a, a + number, temp);
    delete []a;
    a = temp;
}
//对于数组指针进行测试
int test(){
    int * arrs = new int[5];
    for (int i = 0; i < 5; ++i) {
        arrs[i] = i;
    }
    changeLength(arrs, 5, 3);
    // 每当指针移动一个位置，就会指向下一个元素
    for (int j = 0; j < 6; ++j) {
        cout << * (arrs + j) << endl;
    }
}
SimpleLinearList<int> getSimpleLinearList(void);
SimpleLinearList<int>* getSimpleLinearListPoint(void);
int test1();

int main() {


    //TODO 这里不能用抽象类分配变量
    SimpleLinearList<int> list = getSimpleLinearList();
    Node<int> * node = list.getHead();
    while (node != nullptr){
        cout << node->getDataNode() << endl;
        node = node->getNextNode();
    }
//    这样会崩溃，因为指向的内存区域已经被收回了
//    LinearList<int> * listPoint = getSimpleLinearListPoint();
//    Node<int> * node1 = listPoint->getHead();
//    while (node1 != nullptr){
//        cout << node->getDataNode() << endl;
//        node = node->getNextNode();
//    }
    Node<int> * temp;
    temp = new Node<int>(); //TODO 这里我甚至不能输入常数进行构造，如果形参为引用类型
    temp->setDataNode(10);
    list.add( temp );
    cout << list.getSize() << list.empty() ;
    //TODO 7356d09(完善了环路出线的情况的考虑，完成了简单单链表的测试。 明天测试环路的情况，以及，单链表变成循环链表时的情况。)
    return 0;
}
