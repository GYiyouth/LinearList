//
// Created by 葛尧 on 2017/7/26.
//

#ifndef LINEARLIST_CIRCLELIST_H
#define LINEARLIST_CIRCLELIST_H

#include "Node.h"

/**
 * circleList
 * It looks like a circle, normally.
 * It has a pointer of the tail Node so that we can get the head and tail fast.
 * It's single linked list.
 * @tparam T
 */
template<class T>
class CircleList{
private:
    Node<T>* tail = nullptr;
protected:
public:
};

#endif //LINEARLIST_CIRCLELIST_H
