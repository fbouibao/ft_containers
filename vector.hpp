
#include <iostream>
#include <memory>
#include "iter.hpp"
#include "reverse_iterator.hpp"
#include "enable_type.hpp"


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
        

    public:

        //constructors
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
            
        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
        {
            size_type d = (size_type)std::distane(first, last);
            this->_size = d;
            this->_capacity = d;
            this->_array = NULL;
            this->_alloc = alloc;
            this->_array = this->_alloc.allocate(d);
            for (size_type i = 0; i < d; i++)
            {
                this->_alloc.construct(this->_array + i, *(first + i));
            }
        }
            
        vector (const vector& x)
        {
            *this = x;
        }


        //destructor
        ~vector()
        {
            if (this->_array)
            {
                clear();
                this->_alloc.deallocate(this->_array, this->_capacity);
            }
        }




        //assignement operator
        vector& operator= (const vector& x)
        {
            if (this->_capacity > 0)
            {
                for (size_type i = 0; i < this->_size; i++)
                {
                    this->_alloc.destroy(this->_array[i]);
                }
                this->_alloc.deallocate(this->_array, this->_capacity);
                if (this->_capacity < x.capacity())
                    this->_capacity = x.capacity();


                this->_array = this->_alloc.allocate(this->_capacity);
                this->_size = x.size();
                for (size_type i = 0; i < this->_size; i++)
                {
                    this->_alloc.construct(this->_array + i, x._array + i);
                }
                return (*this);
            }
            this->_array = NULL;
            this->_size = 0;
            this->_capacity = 0;
            this->_alloc = allocator_type();
            return ();
        }



        //Iterators:
        iterator begin()
        {
            return (iterator(this->_array));
        }

        const_iterator begin() const
        {
            return (const_iterator(this->_array));
        }

        iterator end()
        {
            return (iterator(this->_array + this->_size));
        }

        const_iterator end() const
        {
            return (const_iterator(this->_array + this->_size));
        }


        // Capacity:
        size_type size() const
        {
            return (this->_size);
        }

        size_type max_size() const
        {
            return (_alloc.max_size());
        }

        void resize (size_type n, value_type val = value_type())
        {
            
        }

        size_type capacity() const
        {
            return (this->_capacity);
        }

        bool empty() const
        {
            return (this->_size == 0);
        }

        void reserve (size_type n)
        {

        }



        //element acces
        reference operator[] (size_type n)
        {
            return (this->_array[n]);
        }

        const_reference operator[] (size_type n) const
        {
            return (this->_array[n]);
        }

        reference at (size_type n)
        {
            return (this->_array[n]);
        }

        const_reference at (size_type n) const
        {
            return (this->_array[n]);
        }

        reference front()
        {
            return (*this->_array);
        }

        const_reference front() const
        {
            return (*this->_array);
        }

        reference back()
        {
            return (this->_array[this->_size - 1]);
        }

        const_reference back() const
        {
            return (this->_array[this->_size - 1]);
        }



        //modifiers

        template <class InputIterator>
        void assign (InputIterator first, InputIterator last)
        {

        }

        void assign (size_type n, const value_type& val)
        {

        }

        void push_back (const value_type& val)
        {

        }

        void pop_back()
        {

        }


        iterator insert (iterator position, const value_type& val)
        {

        }

        void insert (iterator position, size_type n, const value_type& val)
        {

        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last)
        {

        }

        iterator erase (iterator position)
        {

        }
        iterator erase (iterator first, iterator last)
        {
            
        }


        void swap (vector& x)
        {

        }

        void clear()
        {

        }



    };

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        
    }


    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {

    }
    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {

    }
    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {

    }
    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {

    }
    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {

    }
    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {

    }




}