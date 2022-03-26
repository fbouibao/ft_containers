#pragma once

#include <iostream>
#include <memory>
#include "iter.hpp"
#include "reverse_iterator.hpp"
#include "enable_type.hpp"
#include "algorithms.hpp"

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
            this->_size = 0;
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
            size_type d = (size_type)std::distance(first, last);
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
		this->_array = nullptr;
		this->_size = 0;
		this->_capacity = 0;
		this->_alloc = allocator_type();
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
        	vector& operator=(const vector& x)
	{
		if (*this != x)
		{
			// this->this->_alloc = x.this->_alloc;
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.destroy(this->_array + i);
			if (this->_capacity > 0)
				this->_alloc.deallocate(_array, this->_capacity);
			if (this->capacity() < x.capacity())
					this->_capacity = x._capacity;
		
			this->_size = x._size;
			this->_array = this->_alloc.allocate(this->_capacity);
			for(size_type i = 0; i < x._size; i++)
				this->_alloc.construct(this->_array + i, x._array[i]);
		}
		return *this;
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
            if (n < this->_size)
            {
                for (size_type i = n; i < this->_size; i++)
                    this->_alloc.destroy(this->_array + i);
                this->_size = n;
            }
            else if (n > this->_capacity)
            {
                if (n > this->_capacity && n < this->_capacity * 2)
                    reserve(n * 2);
                else if (n > this->_capacity)
                    reserve(n);
                for (size_type i = this->_size; i < n; i++)
                    this->_alloc.construct(this->_array + i, val);
                this->_size = n;
            }
            else if (n > this->_size)
            {
                for (size_type i = this->_size; i < n; i++)
                    this->_alloc.construct(this->_array + i, val);
                this->_size = n;
            }
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
            if (n > this->_capacity)
            {
                if (n > max_size())
                    throw std::length_error("exceeds maximum supported size");
                pointer tmp;
                tmp = this->_alloc.allocate(n);
                for (size_type i = 0; i < this->_size; i++)
                {
                    this->_alloc.construct(tmp + i, this->_array[i]);
                }
                for (size_type i = 0; i < this->_size; i++)
                {
                    this->_alloc.destroy(this->_array + i);
                }
                this->_alloc.deallocate(this->_array, this->_capacity);
                this->_array = tmp;
                this->_capacity = n;
            }
        }



        //element acces
        reference operator[] (size_type n)
        {
            if (n >= this->_size)
                throw std::out_of_range("outside of array");
            return (this->_array[n]);
        }

        const_reference operator[] (size_type n) const
        {
            if (n >= this->_size)
                throw std::out_of_range("outside of array");
            return (this->_array[n]);
        }

        reference at (size_type n)
        {
            if (n >= this->_size)
                throw std::out_of_range("outside of array");
            return (this->_array[n]);
        }

        const_reference at (size_type n) const
        {
            if (n >= this->_size)
                throw std::out_of_range("outside of array");
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
            size_type n = (size_type)std::distance(first, last);
            if (n > this->_capacity)
                reserve(n);
            for (size_type i = 0; i < this->_size; i++)
                this->_alloc.destroy(this->_array + i);
            for (size_type i = 0; i < n; i++)
                this->_alloc.construct(this->_array + i, *(first + 1));
            this->_size = n;
        }

        void assign (size_type n, const value_type& val)
        {
            if (n > this->_capacity)
                reserve(n);
            for (size_type i = 0; i < this->_size; i++)
                this->_alloc.destroy(this->_array + i);
            for (size_type i = 0; i < n; i++)
                this->_alloc.construct(this->_array + i, val);
            this->_size = n;
        }

        void push_back (const value_type& val)
        {
            if (this->_capacity == 0)
                reserve(1);
            else if (this->_size == this->_capacity)
                reserve(this->_size * 2);
            this->_alloc.construct(this->_array + this->_size, val);
            this->_size++;
        }

        void pop_back()
        {
            if (this->_size > 0)
            {
                this->_size--;
                this->_alloc.destroy(this->_array + this->_size);
            }
        }


        iterator insert (iterator position, const value_type& val)
        {
            size_type d = (size_type)std::distance(begin(), position);
            if (this->_capacity == 0)
                reserve(1);
            else if (this->_size == this->_capacity)
                reserve(this->_size * 2);
            for (size_type i = this->_size; i > d; i--)
            {
                this->_alloc.construct(this->_array + i, this->_array[i - 1]);
            }
            this->_alloc.construct(this->_array + d, val);
            this->_size++;
            return (iterator(this->_array + d));
        }

        void insert (iterator position, size_type n, const value_type& val)
        {
            size_type d = (size_type)std::distance(begin(), position);
            if (this->_capacity == 0 || (this->_size + n) > (this->_capacity * 2))
                reserve(this->_size + n);
            else if ((this->_size + n) > this->_capacity)
                reserve(this->_size * 2);
            for (size_type i = this->_size - 1; i >= d; i--)
            {
                this->_alloc.construct(this->_array + i + n, this->_array[i]);
            }
            for (size_type i = 0; i < n; i++)
            {
                this->_alloc.construct(this->_array + d++, val);                
            }
            this->_size += n;
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last)
        {
            size_type d = (size_type)std::distance(begin(), position);
            size_type n = (size_type)std::distance(first, last);

            if (this->_capacity == 0 || (this->_size + n) > (this->_capacity * 2))
                reserve(this->_size + n);
            else if ((this->_size + n) > this->_capacity)
                reserve(this->_size * 2);

            for (size_type i = this->_size - 1; i >= d; i--)
            {
                this->_alloc.construct(this->_array + i + n, this->_array[i]);
            }
            for (size_type i = 0; i < n; i++)
            {
                this->_alloc.construct(this->_array + d++, *(first++));                
            }
            this->_size += n;
        }

        iterator erase (iterator position)
        {
            size_type d = (size_type)std::distance(begin(), position);
            this->_alloc.destroy(this->_array + d);
            for (size_type i = d; i < this->_size; i++)
            {
                this->_alloc.construct(this->_array + i, this->_array[i + 1]);                
            }
            this->_size--;
            return (iterator(this->_array + d));
        }

        iterator erase (iterator first, iterator last)
        {
            size_type d = (size_type)std::distance(begin(), first);
            size_type n = (size_type)std::distance(first, last);
            for (size_type i = d; i < d + n; i++)
            {
                this->_alloc.destroy(this->_array + i);
            }
            for (size_type i = d; i < this->_size; i++)
            {
                this->_alloc.construct(this->_array + i, this->_array[i + n]);                
            }
            this->_size -= n;
            return (iterator(this->_array + d));
        }


        void swap (vector& x)
        {
            pointer tmp;
            size_type ts;
            size_type tc;

            tmp = this->_array;
            this->_array = x._array;
            x._array = tmp;
            
            ts = this->_size;
            this->_size = x._size;
            x._size = ts;

            tc = this->_capacity;
            this->_capacity = x._capacity;
            x._capacity = tc;
        }

        void clear()
        {
            for (size_type i = 0; i < this->_size; i++)
                this->_alloc.destroy(this->_array + i);
            this->_size = 0;            
        }

        // get_allocator
        allocator_type get_allocator() const
        {
            return (this->_alloc);
        }
    reverse_iterator rbegin()
	{
		return (reverse_iterator(end()));
	}
	const_reverse_iterator rbegin() const
	{
		return(const_reverse_iterator(end()));
	}
	reverse_iterator rend()
	{
		return (reverse_iterator(begin()));
	}
	const_reverse_iterator	rend ()		const	
	{ 
		return (const_reverse_iterator(begin())); 
	}
    };

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }


	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		else
			return false;
	}

	template <class T, class Alloc>
  	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
  	{
		  return !(lhs == rhs);
  	}
    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs > rhs));
    }
    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (rhs < lhs);
    }
    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }




}