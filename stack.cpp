#include <iostream>
#include <exception>

template <typename T>
class Stack {
public:
    Stack() : _top(nullptr), _size(0) {}

    struct Node {
        Node(T el) : data(el) {}

        Node(T el, Node *node) : data(el), next(node) {}

        Node *next;
        T data;
    };

    void push(const T);

    void pop();

    T &top();

    size_t size() noexcept
    {
        return _size;
    }

    bool empty() noexcept ;

private:
    Node *_top;
    size_t _size;
};


template <typename T>
void Stack<T>::push (const T el)
{

    Node *temp = new Node(el, _top);
    _top = temp;
    _size++;
}
template <typename T>
T& Stack<T>::top()
{
  if(!_top)
      throw std::out_of_range("Top:Stack id empty");

  return _top -> data;
 }
template <typename T>
bool Stack<T>::empty() noexcept
{
    return _size == 0;
}
template <typename T>
void Stack<T>::pop(){
    if(!_top)
        throw std::out_of_range("Pop: stack is empty");
    Node* temp = _top;
    _top = _top->next;
    delete temp;
    _size--;
}
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
