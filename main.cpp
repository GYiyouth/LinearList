#include <iostream>
#include "Node.h"
#include "LinearList.h"
#include "SimpleLinearList.h"
using namespace std;
int main() {

    LinearList<int>* linearList = new SimpleLinearList<int>();

    for (int i = 0; i < 10 ; i ++ ){
        auto node = new Node<int>();
        node->setDataNode(i);
        linearList->add(node);
    }

    while ( (linearList->empty() ) != true ){
        Node<int> * tail = linearList->getNode( linearList->getSize() - 1 );
        cout << tail->getDataNode() << endl;
        linearList->remove(tail);
    }
    return 0;
}