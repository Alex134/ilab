#include <iostream>
#include <exception>
#include "Stack.h"


int main(){
    try {
        Stack<int> stack;
        stack.push(10);
        stack.push(2);
        stack.push(4);
        //stack.pop();
        while (!stack.empty()) {
            std::cout << stack.top() << " - " << stack.size() << std::endl;
            stack.pop();
        }

    }
    catch (std::out_of_range& e){
        std::cout << "Out of range exception: " << e.what() << std::endl;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }

    return  0;
}