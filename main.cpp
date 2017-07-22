#include <iostream>
#include "Node.h"
#include "LinearList.h"
#include "SimpleLinearList.h"
using namespace std;
int main() {
    LinearList<int>* linearList = new SimpleLinearList<int>();
    //新建10个节点，添加到单链表中
    for (int i = 0; i < 10 ; i ++ ){
        auto node = new Node<int>(i, nullptr);
        linearList->add(node);
    }
    //遍历所有节点并删除
    while ( (linearList->empty() ) != true ){
        Node<int> * tail = linearList->getNode( linearList->getSize() - 1 );
        cout << tail->getDataNode() << endl;
        linearList->remove(tail);
    }
    return 0;
}