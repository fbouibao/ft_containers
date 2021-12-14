
#include <iostream>
#include <memory>

template <class T, class alocator = std::allocator<T> >
class vector
{
private:

public:
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
    T* begin()
    {
        return (&ptr[0]);
    }
    T* end()
    {
        return (&ptr[this->size]);
    }
    T* rbegin()
    {
        return (&ptr[this->s - 1]);
    }
    T* rend()
    {
        return (&ptr[-1]);
    }

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

