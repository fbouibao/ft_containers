
#include <iostream>
#include <memory>
#include "iter.hpp"
#include "reverse_iterator.hpp"


namespace ft{
    template <class T, class _aloc = std::allocator<T> >
    class vector
    {
    public:
        typedef T                                         				value_type;
        typedef _aloc                                  			        allocator_type;
        typedef typename allocator_type::reference	        			reference;
        typedef typename allocator_type::const_reference    			const_reference;
        typedef typename allocator_type::pointer           				pointer;
        typedef typename allocator_type::const_pointer      			const_pointer;
        typedef std::size_t												size_type;
        typedef ft::iter<pointer>										iterator;
        typedef ft::iter<const_pointer>							        const_iterator;
        typedef ft::reverse_iterator<iterator>						    reverse_iterator;
        typedef ft::reverse_iterator    <const_iterator>				const_reverse_iterator;
        typedef std::ptrdiff_t                                          difference_type;

    private:
        pointer         _array;
        size_type       _size;
        size_type       _capacity;
        allocator_type  _alloc;
        
        // vector()
        // {

        // }

        





        // vector(size_t size)
        // {
        //     this->s = size;
        //     alocator a;
        //     ptr = a.allocate(this->s);
        //     for (int i = 0; i < size; i++)
        //     {
        //         ptr[i] = 0;
        //     }
        // }
        // vector(size_t size, T ins)
        // { 
        //     this->s = size;
        //     alocator a;
        //     ptr = a.allocate(this->s);
        //     for (int i = 0; i < size; i++)
        //     {
        //         ptr[i] = ins;
        //     }
        // }
        // ~vector()
        // {

        // }


    public:
        explicit vector (const allocator_type& alloc = allocator_type())
        {
            this->size = 0;
            this->_capacity = 0;
            this->_array = NULL;
            this->_alloc = alloc;
        }
            
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
        {
            this->_size = n;
            this->_capacity = n;
            this->_alloc = alloc;
            this->_array = this->_alloc.allocate(n);
            for (size_type i = 0; i < n; i++)
            {
                this->_alloc.construct(this->_array + i, val);
            }
        }
            
        // template <class InputIterator>
        // vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
        // {

        // }
            
        vector (const vector& x)
        {
		this->_array = NULL;
		this->_size = 0;
		this->_capacity = 0;
		this->_alloc = allocator_type();
		*this = x;
        }


        vector& operator=(const vector& x)
        {
            if (*this != x)
            {
                // this->alloc = x.alloc;
                for (size_type i = 0; i < this->_size; i++)
                    _alloc.destroy(this->_array + i);
                if (this->_capacity > 0)
                    _alloc.deallocate(_array, this->_capacity);
                if (this->capacity() < x.capacity())
                        this->_capacity = x._capacity;
            
                this->_size = x._size;
                this->_array = _alloc.allocate(this->_capacity);
                for(size_type i = 0; i < x._size; i++)
                    _alloc.construct(this->_array + i, x._array[i]);
            }
            return *this;
        }



        iterator begin()
        {
            return (iterator(this->_array));
        }

        iterator end()
        {
            return (iterator(this->_array + this->_size));
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
            return (this->_size);
        }

        size_t max_size()
        {
            return (_alloc.max_size());
        }

        // void resize(size_t sz)
        // {
        //     alocator a;
        //     T *p;

        //     p = a.allocate(sz);
        //     for (size_t i = 0; i < sz; i++)
        //     {
        //         p[i] = (i < this->s) ? ptr[i] : 0;
        //     }
        //     a.deallocate(ptr, this->s);
        //     ptr = p;
        //     this->s = sz;
        // }

        bool empty()
        {
            return (this->_size == 0);
        }

        // void resize(size_t sz, T x)
        // {
        //     alocator a;
        //     T *p;

        //     p = a.allocate(sz);
        //     for (size_t i = 0; i < sz; i++)
        //     {
        //         p[i] = (i < this->s) ? ptr[i] : x;
        //     }
        //     a.deallocate(ptr, this->s);
        //     ptr = p;
        //     this->s = sz;
        // }



        /************************ element acces ****************************/


        // T& operator[](T indx)
        // {
        //     return (this->ptr[indx]);
        // }

        // T& at(size_t n)
        // {
        //     return (this->ptr[n]);
        // }

        // T& front()
        // {
        //     return (*this->ptr);
        // }

        // T& back()
        // {
        //     return (this->ptr[this->s - 1]);
        // }

        // T* data()
        // {
        //     return (this->ptr);
        // }



        /************************ end element acces ****************************/

        /************************ modifiers ****************************/
        /// Not yet tested clear()

        // void clear()
        // {
        //     alocator a;
        //     a.deallocate(ptr, this->s);
        // }



        /************************ end modifiers ****************************/
    };

}