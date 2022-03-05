#include <iostream>

namespace ft
{
    template <class Category, class T, class diff = std::ptrdiff_t,
    class Pointer = T*, class Refrence = T&>
    class base_iterator
    {
        typedef T   value_type;
        typedef diff difference_type;
        typedef Pointer pointer;
        typedef Refrence reference;
        typedef Category iterator_category;
    };
}
