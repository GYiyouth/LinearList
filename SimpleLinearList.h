//
// Created by ge yao on 2017/7/22.
//

#ifndef LINEARLIST_SIMPLELINEARLIST_H
#define LINEARLIST_SIMPLELINEARLIST_H


#include "LinearList.h"
#include "LinearListOperator.h"
template <class T>
class SimpleLinearList : public LinearList<T>{
private:
    // 变量和方法名不能相同

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



// 获取头结点
template <class T>
Node<T> *SimpleLinearList<T>::getHead() const {
    return this->head;
}
//设置头结点
template <class T>
void SimpleLinearList<T>::setHead(Node<T> *head) {
    this->head = head;
}

//判空操作
template <class T>
bool SimpleLinearList<T>::empty() const {
    return getHead() == nullptr;
}

//获取大小
//考虑环路
template <class T>
int SimpleLinearList<T>::getSize() const {
    Node<T> * tail = getTailNode();
    int size = 0;
    Node<T> * head = getHead();
    while(head != tail){
        size ++ ;
        head = head->getNextNode();
    }
    return size;
}

// 获取指定位置上的节点
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

//插入
template <class T>
bool SimpleLinearList<T>::insert(int index, Node<T> *node) {
    Node<T> * source = this->getNode(index);
    if(source == nullptr) {
        return false;
    } else{
        node->setNextNode( source->getNextNode() );
        source->setNextNode( node );
        return true;
    }
}
//移除某个节点
//考虑到了空链表、环路、节点不存在于链表中 等种种情况
template <class T>
bool SimpleLinearList<T>::remove(Node<T> *node) {
    Node<T> * targetParent = this->getHead();
    if (targetParent == node){
        setHead(node->getNextNode());
        delete targetParent;
        return true;
    }
    Node<T> * slowNode = getHead(); // 考虑环路 且 节点不存在的情况
    bool forwardFlag = false;
    while (targetParent != nullptr){
        if (targetParent->getNextNode() == node){
            targetParent->setNextNode( targetParent->getNextNode()->getNextNode() );
            return true;
        }
        targetParent = targetParent->getNextNode();
        if (targetParent == slowNode){ // 环路出现，已遍历一圈
            return false;
        }
        if (forwardFlag){ // 慢指针该走了
            slowNode = slowNode->getNextNode();
            if (targetParent == slowNode){ // 环路出现，以遍历一圈
                return false;
            }
        }
        //翻转
        forwardFlag = ! forwardFlag;
    }
}

//移除指定位置上的节点
template <class T>
bool SimpleLinearList<T>::remove(int index) {
    //位置非法
    if (index < 0 ){
        return false;
    }

    Node<T> * targetParent = getHead();
    if (targetParent == nullptr) { // 如果头结点也不存在
        return false;
    }

    if (index == 0){ // 删除头结点的特殊情况
        setHead(targetParent->getNextNode());
        //delete是删除指针指向的对象，让其释放内存。
        delete(targetParent);
        //指针中的地址不变，所以一般在delete指针后，要将该指针的值赋值NULL（置空）。
        targetParent = nullptr;
        return true;
    }

    for(int i = 1 ; i < index ; i++){
        if (targetParent->getNextNode() == nullptr){
            //删除的位置不存在
            return false;
        }
        targetParent = targetParent->getNextNode();
    }

    Node<T> * target = targetParent->getNextNode();
    targetParent->setNextNode(target->getNextNode());
    //函数调用后会出现什么？
    // https://www.zhihu.com/question/52864288
    delete(target);
    target = nullptr;
    return true;
}

//在尾部添加节点
template <class T>
bool SimpleLinearList<T>::add(Node<T> *node) {
    //空指针无法添加
    if (node == nullptr){
        return false;
    }
    bool cirFlag = circleJudge();
    if (getHead() == nullptr){ // 空链表
        setHead(node);
        return true;
    }
    if (cirFlag){//有环路，无法添加
        return false;
    } else{//无环路，可以正常添加
        Node<T> * tail = getHead();
        while (tail->getNextNode() != nullptr){
            tail = tail->getNextNode();
        }
        tail->setNextNode(node);
        return true;
    }

}

//判断该链条是否存在环路
//返回node为生成环路的那个节点，它的next本应是nullptr
//如果没有环路，则返回的node是尾节点
template <class T>
bool SimpleLinearList<T>::circleJudge() const {
    if (getHead() == nullptr){
        return false;
    }
    Node<T> * fastNode = getHead();
    Node<T> * slowNode = getHead();
    bool forwardFlag = false;
    //出口之一，下一个节点为 nullptr
    while(fastNode->getNextNode() != nullptr){
        fastNode = fastNode->getNextNode();
        //出口之二，2个指针相逢了
        if (fastNode == slowNode){
            return true;
        } else
        if (forwardFlag){
            slowNode = slowNode->getNextNode();
            if (fastNode == slowNode){ //出口之二，2个指针相逢了
                return true;
            }
        }
        forwardFlag = !forwardFlag;
    }
    //没有环路，返回tail
    return false;
}


//获取尾节点，如果存在环路，则返回成环的那个节点
template <class T>
Node<T> *SimpleLinearList<T>::getTailNode() const {
    Node<T> * fastNode = getHead();
    Node<T> * slowNode = getHead();
    bool forwardFlag = false;
    if (fastNode == nullptr){
        return fastNode;
    }
    //从头至尾遍历
    while(fastNode->getNextNode() != nullptr){
        fastNode = fastNode->getNextNode();
        if (fastNode == slowNode){
            //出现环路
            return getCircleTailNode(getHead(), fastNode);
        }
        if (forwardFlag){
            slowNode = slowNode->getNextNode();
            if (fastNode == slowNode){
                //出现环路，之所以检查2次，是因为可能出现，快节点领先慢节点一圈，二者同时入环
                return getCircleTailNode(getHead(), fastNode);
            }
        }
        forwardFlag = !forwardFlag;
    }
    //无环路出线
    return fastNode;
}


#endif //LINEARLIST_SIMPLELINEARLIST_H
