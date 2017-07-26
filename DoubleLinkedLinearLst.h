//
// Created by 葛尧 on 2017/7/26.
//

#ifndef LINEARLIST_DOUBLELINKEDLINEARLST_H
#define LINEARLIST_DOUBLELINKEDLINEARLST_H

#include "LinearList.h"
#include "DNode.h"
#include <iostream>

using namespace std;
/**
 * LinearList with double linked Node
 * Operations will be easy
 * @tparam T
 */
template <class T>
class DoubleLinkedLinearList: public LinearList<T>{
private:
    DNode<T>* head = nullptr;
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

    bool circleJudge() const override;

    Node<T> *getTailNode() const override;
};
template <class T>
Node<T> *DoubleLinkedLinearList::getHead() const {
    return this->head;
}
template <class T>
void DoubleLinkedLinearList::setHead(Node<T> *head) {
    this->head = (DNode<T> *)head;
}
template <class T>
bool DoubleLinkedLinearList::empty() const {
    return head == nullptr;
}
template <class T>
int DoubleLinkedLinearList::getSize() const {
    return 0;
}
template <class T>
Node<T> *DoubleLinkedLinearList::getNode(int index) const {
    return nullptr;
}
template <class T>
bool DoubleLinkedLinearList::insert(int index, Node<T> *node) {
    return false;
}
template <class T>
bool DoubleLinkedLinearList::remove(Node<T> *node) {
    return false;
}
template <class T>
bool DoubleLinkedLinearList::remove(int index) {
    return false;
}
template <class T>
bool DoubleLinkedLinearList::add(Node<T> *node) {
    return false;
}
template <class T>
bool DoubleLinkedLinearList::circleJudge() const {
    return false;
}
template <class T>
Node<T> *DoubleLinkedLinearList::getTailNode() const {
    return nullptr;
}

#endif //LINEARLIST_DOUBLELINKEDLINEARLST_H
