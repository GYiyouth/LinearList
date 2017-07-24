//
// Created by ge yao on 2017/7/25.
// 用来放置对链表的各种试验操作
//
#include "Node.h"
#include "LinearList.h"
#include "SimpleLinearList.h"
#include <iostream>
using namespace std;

//获取一个简单的无环单链表
//TODO 这里能返回抽象类居然
SimpleLinearList<int> getSimpleLinearList(void){
    SimpleLinearList<int> * list = new SimpleLinearList<int>();
    for (int i = 0; i < 10; ++i) {
        Node<int> * node = new Node<int>(i);
        list->add(node);
    }
    return *list;
}
//TODO 返回指针类型，但这样是不行的，因为函数结束后，那块内存区域就可能被销毁了
SimpleLinearList<int>* getSimpleLinearListPoint(void){
    SimpleLinearList<int> * list = new SimpleLinearList<int>();
    for (int i = 0; i < 10; ++i) {
        Node<int> * node = new Node<int>(i);
        list->add(node);
    }
    return list;
}
