//
// Created by ge yao on 2017/7/22.
//
#include "LinearList.h"
#include "SimpleLinearList.h"
//c++ 模板不支持分离编译模型，把实现文件中的定义移到头文件中
/*
template <class T>
Node<T> *SimpleLinearList<T>::getHead() const {
    return this->head;
}
template <class T>
void SimpleLinearList<T>::setHead(Node<T> *head) {
    this->head = head;
}

template <class T>
bool SimpleLinearList<T>::empty() const {
    return this->size == 0;
}

template <class T>
int SimpleLinearList<T>::getSize() const {
    return this->size;
}

template <class T>
Node<T> *SimpleLinearList<T>::getNode(const int index) const {
    if (index >= 0){
        Node<T> * node = nullptr;
        node = this->getHead();
        if(index == 0){
            return node;
        }
        int i = 0;
        while (i < index){
            if (node->getNextNode() != nullptr) {
                i++;
                node = node->getNextNode();
            } else{
                return nullptr;
            }
        }
        return node;
    } else{
        return nullptr;
    }
}

template <class T>
bool SimpleLinearList<T>::insert(int index, Node<T> *node) {
    Node<T> * source = this->getNode(index);
    if(source == nullptr) {
        return false;
    } else{
        node->setNextNode( source->getNextNode() );
        source->setNextNode( node );
        this->size ++ ;
        return true;
    }
}

template <class T>
bool SimpleLinearList<T>::remove(Node<T> *node) {
    Node<T> * node1 = this->getHead();
    if (node1 == node){
        setHead(node->getNextNode());
        this->size -- ;
        return true;
    }
    while (node1 != nullptr){
        if (node1->getNextNode() == node){
            node1->setNextNode( node1->getNextNode()->getNextNode() );
            size -- ;
            return true;
        }
        node1 = node1->getNextNode();
    }
}

template <class T>
bool SimpleLinearList<T>::remove(int index) {
    if (index < 0 || index > getSize()){
        return false;
    }
    Node<T> * node = getNode(index);
    remove(node);
    size -- ;
    return true;
}
*/
