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

int test1();

int main() {

    LinearList<int>* linearList = new SimpleLinearList<int>();
    //新建10个节点，添加到单链表中
    for (int i = 0; i < 10 ; i ++ ){
        auto node = new Node<int>(i, nullptr);
        linearList->add(node);
    }


    //遍历所有节点并删除
    while ( (linearList->empty() ) != true ){
        Node<int> * tail = linearList->getNode( linearList->getSize());
        cout << tail->getDataNode() << endl;
        linearList->remove(tail);
    }

    cout << (nullptr == nullptr) << endl;

    return 0;
}
