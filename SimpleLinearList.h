//
// Created by ge yao on 2017/7/22.
//

#ifndef LINEARLIST_SIMPLELINEARLIST_H
#define LINEARLIST_SIMPLELINEARLIST_H

#include "LinearList.h"
template <class T>
class SimpleLinearList : public LinearList<T>{

private:
    int size = 0; // 变量和方法名不能相同
public:
    Node<T> *getHead() const override;

    void setHead(Node<T> *head) override;

    bool empty() const override;

    int getSize() const override;

    Node<T> *getNode(int index) const override;

    bool insert(int index, Node<T> *node) override;

    bool remove(Node<T> *node) override;

    bool remove(int index) override;

    bool add(Node<T> *node) override;
};


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

template <class T>
bool SimpleLinearList<T>::add(Node<T> *node) {
    if (node == nullptr){
        return false;
    }
    if (getHead() == nullptr){
        setHead(node);
        size ++;
        return true;
    } else{
        Node <T> * tail = getHead();
        while (tail->getNextNode() != nullptr){
            tail = tail->getNextNode();
        }
        tail->setNextNode( node );
        size ++ ;
        return true;
    }
}


#endif //LINEARLIST_SIMPLELINEARLIST_H
