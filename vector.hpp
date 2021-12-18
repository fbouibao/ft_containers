
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

    void resize(size_t sz)
    {
        alocator a;
        T *p;

        p = a.allocate(sz);
        for (size_t i = 0; i < sz; i++)
        {
            p[i] = (i < this->s) ? ptr[i] : 0;
        }
        a.deallocate(ptr, this->s);
        ptr = p;
        this->s = sz;
    }

    bool empty()
    {
        return (this->s == 0);
    }

    void resize(size_t sz, T x)
    {
        alocator a;
        T *p;

        p = a.allocate(sz);
        for (size_t i = 0; i < sz; i++)
        {
            p[i] = (i < this->s) ? ptr[i] : x;
        }
        a.deallocate(ptr, this->s);
        ptr = p;
        this->s = sz;
    }



    /************************ element acces ****************************/


    T& operator[](T indx)
    {
        return (this->ptr[indx]);
    }

    T& at(size_t n)
    {
        return (this->ptr[n]);
    }

    T& front()
    {
        return (*this->ptr);
    }

    T& back()
    {
        return (this->ptr[this->s - 1]);
    }

    T* data()
    {
        return (this->ptr);
    }



    /************************ end element acces ****************************/

    /************************ modifiers ****************************/
    /// Not yet tested clear()

    void clear()
    {
        alocator a;
        a.deallocate(ptr, this->s);
    }



    /************************ end modifiers ****************************/
};

