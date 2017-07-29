#include <iostream>
#include "Node.h"
#include "LinearList.h"
#include "SimpleLinearList.h"
using namespace std;


//����
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
//��������ָ����в���
int test(){
    int * arrs = new int[5];
    for (int i = 0; i < 5; ++i) {
        arrs[i] = i;
    }
    changeLength(arrs, 5, 3);
    // ÿ��ָ���ƶ�һ��λ�ã��ͻ�ָ����һ��Ԫ��
    for (int j = 0; j < 6; ++j) {
        cout << * (arrs + j) << endl;
    }
    return 0;
}
SimpleLinearList<int> getSimpleLinearList(void); // ��ȡ�޻�������
SimpleLinearList<int>* getSimpleLinearListPoint(void);// ��ȡ�޻�������
SimpleLinearList<int> getCircleLinearList(void); // ��ȡ�л�������
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


    //TODO ���ﲻ���ó�����������
//    SimpleLinearList<int> list = getSimpleLinearList();
//    Node<int> * node = list.getHead();
//    while (node != nullptr){
//        cout << node->getDataNode() << endl;
//        node = node->getNextNode();
//    }
//    �������������Ϊָ����ڴ������Ѿ����ջ���
//    LinearList<int> * listPoint = getSimpleLinearListPoint();
//    Node<int> * node1 = listPoint->getHead();
//    while (node1 != nullptr){
//        cout << node->getDataNode() << endl;
//        node = node->getNextNode();
//    }
//    Node<int> * temp;
//    temp = new Node<int>(); //TODO �����������������볣�����й��죬����β�Ϊ��������
//    temp->setDataNode(10);
//    list.add( temp );
//    cout << list.getSize() << list.empty() ;
//    cout << endl << endl <<"��·����" << endl << endl;
    //TODO 7356d09(�����˻�·���ߵ�����Ŀ��ǣ�����˼򵥵�����Ĳ��ԡ� ������Ի�·��������Լ�����������ѭ������ʱ�������)
//    SimpleLinearList<int> cirList = getCircleLinearList();
//    Node<int>* node1 = cirList.getHead();
//    for (int i = 0; i < 20; ++i) {
//        cout<<node1->getDataNode()<< endl;
//        node1 = node1->getNextNode();
//    }
    //TODO �����жϳɻ��ܲ�����hashMap�����أ�
//    int size = cirList.getSize();
//    cout << "��·��size��" << size << endl;
//
//    Node<int>* encounter = cirList.getTailNode();
//    Node<int>* nodeC0 = getCircleNode(cirList.getHead(), encounter); //FIXME
//    cout << "���ڵ���" << nodeC0->getDataNode() << endl;
//    Node<int>* nodeC_1 = getCircleEnterNode(cirList.getHead(), encounter);
//    cout << "�뻷�ڵ���" << nodeC_1->getDataNode() << endl;
//    Node<int>* nodeC1 = getCircleTailNode(cirList.getHead(), encounter);
//
//    cout << "��β�ڵ���" << nodeC1->getDataNode() << endl;
//    //FIXME ѭ������ʱ�޷�ͨ��
//
//    cout << "��ȡָ��λ���ϵĽڵ�Test" << endl;
//    cout << cirList.getNode(0)->getDataNode() << endl;
//    cout << cirList.getNode(6)->getDataNode() << endl;
//    cout << cirList.getNode(16)->getDataNode() << endl;
//    cout << cirList.getNode(17)->getDataNode() << endl;
//    cout << "ָ��λ�ò���ڵ����Test" << endl;
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
//    cout << "ָ��λ��ɾ���ڵ����Test" << endl;
//    cirList.remove(11);
//    node1 = cirList.getHead();
//    for (int i = 0; i < 20; ++i) {
//        cout<<node1->getDataNode()<< endl;
//        node1 = node1->getNextNode();
//    }
//    cout << "�ɻ�����" << endl;
//    cout << list.circleJudge() << endl;
//    cout << cirList.circleJudge() << endl;
    QueueTest();
    return 0;
}
