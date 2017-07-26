//
// Created by ge yao on 2017/7/26.
// Do some exam to verify my operation of DoubleLinkedLinearList.h is correct
//
#include "DoubleLinkedLinearList.h"
#include "DNode.h"

using namespace std;

int DoubleLinkedLinearListExecute(){
    auto list = new DoubleLinkedLinearList<int>();
    cout << "insert test \n";
    auto head = new DNode<int>();
    head->setDataNode(0);
    cout << " - setHead\n";
    list->setHead(head);
    for (int i = 1; i < 10; ++i) {
        auto node = new DNode<int>();
        node->setDataNode(i);
        list->add(node);
    }
    list->info();
    return 0;
}

