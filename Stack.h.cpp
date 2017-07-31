//
// Created by ge yao on 2017/7/31.
//

#include <iostream>
#include "Stack.h"

void StackTest(){
    Stack<int>* stack = new Stack<int>();
    stack->info();
    for (int i = 0; i < 5; ++i) {
        //you cannot use a const element like push(1) because 1 is not a reference element
        stack->push(i);
    }
    stack->info();
    for (int j = 0; j < 6; ++j) {
        int result = 0;
        stack->pop(result);
        cout << result << endl;
    }
    stack->info();
}