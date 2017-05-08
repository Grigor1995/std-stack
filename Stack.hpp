#ifndef _Stack_hpp_
#define _Stack_hpp_

/***************************/
/*Stack.hpp~Abstrackt class*/
/***************************/

template <typename T>
class Stack
{
public:
    Stack () {}

    virtual int get_size () const = 0;
    virtual int capacity () const = 0;

    virtual bool push (const T&) = 0;
    virtual bool pop () = 0;
    virtual bool empty ()const = 0;

    virtual void clear () = 0;

    virtual T Top () = 0;
};
#endif//end including Stack.hpp file
