#include <iostream>
#include "Node.h"
#include "LinearList.h"
#include "SimpleLinearList.h"
using namespace std;


//交换
template <class T>
void changeLength(T * & a, const int oldLength, const int newLength){
    if (newLength < 0){
        throw exception();
    }
    T* temp = new T[newLength];
    int number = min(oldLength, newLength);
    copy(a, a + number, temp);
    delete []a;
    a = temp;
}
//对于数组指针进行测试
int test(){
    int * arrs = new int[5];
    for (int i = 0; i < 5; ++i) {
        arrs[i] = i;
    }
    changeLength(arrs, 5, 3);
    // 每当指针移动一个位置，就会指向下一个元素
    for (int j = 0; j < 6; ++j) {
        cout << * (arrs + j) << endl;
    }
    return 0;
}
SimpleLinearList<int> getSimpleLinearList(void); // 获取无环单链表
SimpleLinearList<int>* getSimpleLinearListPoint(void);// 获取无环单链表
SimpleLinearList<int> getCircleLinearList(void); // 获取有环单链表
template <class T>
Node<T> * getCircleEnterNode(Node<T> * head, Node<T>* encounter);
template <class T>
Node<T> * getCircleTailNode(Node<T> * head, Node<T>* encounter);
template <class T>
Node<T > * getCircleNode(Node<T> *head, Node<T> *encounter);
int test1();
int DoubleLinkedLinearListExecute();
void QueueTest();


int main() {


    //TODO 这里不能用抽象类分配变量
//    SimpleLinearList<int> list = getSimpleLinearList();
//    Node<int> * node = list.getHead();
//    while (node != nullptr){
//        cout << node->getDataNode() << endl;
//        node = node->getNextNode();
//    }
//    这样会崩溃，因为指向的内存区域已经被收回了
//    LinearList<int> * listPoint = getSimpleLinearListPoint();
//    Node<int> * node1 = listPoint->getHead();
//    while (node1 != nullptr){
//        cout << node->getDataNode() << endl;
//        node = node->getNextNode();
//    }
//    Node<int> * temp;
//    temp = new Node<int>(); //TODO 这里我甚至不能输入常数进行构造，如果形参为引用类型
//    temp->setDataNode(10);
//    list.add( temp );
//    cout << list.getSize() << list.empty() ;
//    cout << endl << endl <<"环路测试" << endl << endl;
    //TODO 7356d09(完善了环路出线的情况的考虑，完成了简单单链表的测试。 明天测试环路的情况，以及，单链表变成循环链表时的情况。)
//    SimpleLinearList<int> cirList = getCircleLinearList();
//    Node<int>* node1 = cirList.getHead();
//    for (int i = 0; i < 20; ++i) {
//        cout<<node1->getDataNode()<< endl;
//        node1 = node1->getNextNode();
//    }
    //TODO 这里判断成环能不能用hashMap来做呢？
//    int size = cirList.getSize();
//    cout << "环路的size是" << size << endl;
//
//    Node<int>* encounter = cirList.getTailNode();
//    Node<int>* nodeC0 = getCircleNode(cirList.getHead(), encounter); //FIXME
//    cout << "环节点是" << nodeC0->getDataNode() << endl;
//    Node<int>* nodeC_1 = getCircleEnterNode(cirList.getHead(), encounter);
//    cout << "入环节点是" << nodeC_1->getDataNode() << endl;
//    Node<int>* nodeC1 = getCircleTailNode(cirList.getHead(), encounter);
//
//    cout << "环尾节点是" << nodeC1->getDataNode() << endl;
//    //FIXME 循环链表时无法通过
//
//    cout << "获取指定位置上的节点Test" << endl;
//    cout << cirList.getNode(0)->getDataNode() << endl;
//    cout << cirList.getNode(6)->getDataNode() << endl;
//    cout << cirList.getNode(16)->getDataNode() << endl;
//    cout << cirList.getNode(17)->getDataNode() << endl;
//    cout << "指定位置插入节点测试Test" << endl;
//    Node<int>* node2Inst1 = new Node<int>();
//    node2Inst1->setDataNode(2);
//    Node<int>* node2Inst2 = new Node<int>();
//    node2Inst2->setDataNode(12);
//    cirList.insert(9, node2Inst2);
//    cirList.insert(0, node2Inst1);
//
//    node1 = cirList.getHead();
//    for (int i = 0; i < 20; ++i) {
//        cout<<node1->getDataNode()<< endl;
//        node1 = node1->getNextNode();
//    }
//    cout << "指定位置删除节点测试Test" << endl;
//    cirList.remove(11);
//    node1 = cirList.getHead();
//    for (int i = 0; i < 20; ++i) {
//        cout<<node1->getDataNode()<< endl;
//        node1 = node1->getNextNode();
//    }
//    cout << "成环测试" << endl;
//    cout << list.circleJudge() << endl;
//    cout << cirList.circleJudge() << endl;
    QueueTest();
    return 0;
}
