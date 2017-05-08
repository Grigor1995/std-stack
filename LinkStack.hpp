#ifndef _LinkStack_hpp_
#define _LinkStack_hpp_
#include "Stack.hpp"

/***************/
/*LinkStack.hpp*/
/***************/

template <typename T>
class LStack:public Stack<T>
{
 public:
    LStack (int = 1000);

    int get_size () const;
    int capacity () const;

    bool push (const T &);
    bool pop ();
    bool empty () const;

    void clear ();

    T Top ();
private:
    struct Node
    {
        Node* next;
        T value;
    };
    Node* currnt;

    int my_size;
    int max_size;
};

template <typename T>
LStack<T>::LStack (int number):my_size(0),max_size(number)
{
    if (max_size > 1000 || max_size < 1)
        max_size = 1000;
    Node* node = new Node;
    node->value = 0;
    node->next = 0;
    currnt = node;
}

template <typename T>
int LStack<T>::get_size() const
{
    return my_size;
}

template <typename T>
int LStack<T>::capacity() const
{
    return max_size;
}

template <typename T>
bool LStack<T>::push(const T & value)
{
    if (my_size == max_size)
        return false;
    Node* node = new Node;
    Node* temp = currnt->next;
    currnt->next = node;
    node->next = temp;
    node->value = value;
    ++my_size;
    return true;
}

template <typename T>
bool LStack<T>::pop()
{
    if (empty())
        return false;
    Node* temp = currnt->next;
    currnt->next = temp->next;
    delete temp;
    --my_size;
    return true;
}

template <typename T>
bool LStack<T>::empty() const
{
    return my_size == 0;
}

template <typename T>
void LStack<T>::clear()
{
    my_size = 0;
    currnt->next = 0;
}

template <typename T>
T LStack<T>::Top()
{
    Node* temp = currnt->next;
    return temp->value;
}
#endif//end including LinkStack.hpp file
