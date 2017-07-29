//
// Created by ge yao on 2017/7/29.
//

#include "Queue.h"
#include <iostream>
using namespace std;

void QueueTest(){
    Queue<int> *queue = new Queue<int>();
    cout << queue->pop() << endl;
    queue->info();
    cout << "\n\npushTest " << endl << endl;
    for (int i = 0; i < 10; ++i) {
        queue->push(&i);
    }
    queue->info();
    cout << "\npopTest\n" ;
    for (int j = 0; j < 5; ++j) {
        cout<<queue->pop() << endl;
    }
    queue->info();
    cout << "add again" <<endl;
    for (int i = 0; i < 5; ++i) {
        queue->push(&i);
    }
    queue->info();
}