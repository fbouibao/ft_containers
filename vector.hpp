
#include <iostream>
#include <memory>
#include "iter.hpp"

template <class T, class alocator = std::allocator<T> >
class vector
{
private:

public:
    typedef iter<T> iterator;
    T *ptr;
    size_t s;
    vector()
    {

    }

    





    vector(size_t size)
    {
        this->s = size;
        alocator a;
        ptr = a.allocate(this->s);
        for (int i = 0; i < size; i++)
        {
            ptr[i] = 0;
        }
    }
    vector(size_t size, T ins)
    { 
        this->s = size;
        alocator a;
        ptr = a.allocate(this->s);
        for (int i = 0; i < size; i++)
        {
            ptr[i] = ins;
        }
    }
    ~vector()
    {

    }


        iterator begin()
        {
            return (iterator(ptr));
        }

        iterator end()
        {
            return (iterator(ptr + s));
        }

        // iterator rbegin()
        // {
        //     return (&ptr[this->s - 1]);
        // }

        // iterator rend()
        // {
        //     return (&ptr[-1]);
        // }

    size_t size()
    {
        return (this->s);
    }
    size_t max_size()
    {
        alocator a;
        return (a.max_size());
    }
};

