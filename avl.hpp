#include <iostream>
#include <memory>
#include "pair.hpp"
#include "reverse_iterator.hpp"
#include "enable_type.hpp"
#include "algorithms.hpp"

namespace ft{
    template < class value_type,
			class Compare = std::less<typename	value_type::first_type>,
			class Alloc = std::allocator<value_type>
		>
    class avl
    {
    private:
        
    public:
        typedef size_t                              size_type;
        typedef typename value_type::first_type     key;
        typedef typename value_type::second_type    T;

        typedef struct node
        {
            value_type* value;
            size_type height;
            node* parent; // needed by find(), insert(), etc. (the rb tree uses it too by the way)
            node* left;
            node* right;
            int balance;
        }               Node;

        avl()
        {
            

        }
        ~avl()
        {

        }
    };
    
 
    
}