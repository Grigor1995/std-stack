#ifndef _ArrayStack_hpp_
#define _ArrayStack_hpp_
#include "Stack.hpp"

/****************/
/*ArrayStack.hpp*/
/****************/

template <typename T>
class AStack:public Stack<T>
{
public:
        AStack (int = 1000);

        int get_size () const;
        int capacity () const;

        bool push (const T &);
        bool pop ();
        bool empty () const;

        void clear ();

        T Top();
private:
        T* arr;

        int my_size;
        int max_size;
};

template <typename T>
AStack<T>::AStack (int number):my_size(0),max_size(number)
{
    if (max_size > 1000 || max_size < 1)
        max_size = 1000;
    arr = new T[max_size];
}

template <typename T>
int AStack<T>::get_size() const
{
    return my_size;
}

template <typename T>
int AStack<T>::capacity() const
{
    return max_size;
}

template <typename T>
bool AStack<T>::push(const T & value)
{
    if (my_size == max_size)
        return false;
    arr[my_size] = value;
    ++my_size;
    return true;
}

template <typename T>
bool AStack<T>::pop()
{
    if (empty())
        return false;
    --my_size;
    return true;
}

template <typename T>
bool AStack<T>::empty() const
{
    return my_size == 0;
}

template <typename T>
void AStack<T>::clear()
{
    my_size = 0;
}

template <typename T>
T AStack<T>::Top()
{
    return arr[my_size-1];
}

#endif//end including ArrayStack.hpp file
