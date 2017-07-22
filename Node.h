//
// Created by ge yao on 2017/7/22.
//

#ifndef LINEARLIST_NODE_H
#define LINEARLIST_NODE_H
template <class T>
class Node {
private:
    T dataNode;
    Node * nextNode = nullptr;
public:
    T getDataNode() const {
        return dataNode;
    }
    void setDataNode(T dataNode) {
        Node::dataNode = dataNode;
    }
    Node *getNextNode() const {
        return nextNode;
    }
    void setNextNode(Node *nextNode) {
        Node::nextNode = nextNode;
    }
    //构造函数
    Node() = default;
    Node(T dataNode, Node *nextNode) : dataNode(dataNode), nextNode(nextNode){};
    //析构函数
    virtual ~Node() = default;
};
#endif //LINEARLIST_NODE_H
