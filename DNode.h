//
// Created by 葛尧 on 2017/7/26.
//

#ifndef LINEARLIST_DNODE_H
#define LINEARLIST_DNODE_H

#include "Node.h"
/**
 * A node with double pointers.
 * With the two pointers we can get two nodes which before or after itself.
 */

template <class T>
class DNode:private Node<T>{
private:
    DNode<T> * before = nullptr;
    T dateNode;
    DNode<T> * after = nullptr;
protected:
public:
    DNode *getBefore() const {
        return before;
    }

    void setBefore(DNode *before) {
        DNode::before = before;
    }

    T getDateNode() const {
        return dateNode;
    }

    void setDateNode(T dateNode) {
        DNode::dateNode = dateNode;
    }

    DNode *getAfter() const {
        return after;
    }

    void setAfter(DNode *after) {
        DNode::after = after;
    }
};


#endif //LINEARLIST_DNODE_H
