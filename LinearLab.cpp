//
// Created by ge yao on 2017/7/25.
// 用来放置对链表的各种试验操作
//
#include "Node.h"
#include "LinearList.h"
#include "SimpleLinearList.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//获取一个简单的无环单链表
//TODO 这里不能返回抽象类居然
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

//获取一个成环的链表
SimpleLinearList<int> getCircleLinearList(void){
    SimpleLinearList<int>* list = new SimpleLinearList<int>();
    for (int i = 0; i < 10; ++i) {
        Node<int> * node = new Node<int>(i);
        list->add(node);
    }
    Node<int>* tail = list->getTailNode();
    //获取一个随机数
    srand((unsigned)time(NULL)); // 使用当前时钟作为随机数种子 否则每次rand()每次运行结果都与上一次相同
    int index = (rand() % 10);
    Node<int>* node = list->getNode(index);
    tail->setNextNode(node);
    return *list;
}
