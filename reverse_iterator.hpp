#pragma once

#include <iostream>
#include <memory>
#include "iterator_traits.hpp"


namespace ft{

    template<class iterator>
    class reverse_iterator
    {
        public:
            typedef iterator					                                iterator_type;
			typedef typename ft::iterator_traits<iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<iterator>::pointer			pointer;
			typedef typename ft::iterator_traits<iterator>::reference			reference;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename ft::iterator_traits<iterator>::iterator_category  iterator_category;


    private:
        iterator_type rvi;

    public:
        // constructors
        reverse_iterator() : rvi() { }
        explicit reverse_iterator(iterator_type it) : rvi(it) { }
        template<typename it2>
        reverse_iterator(const reverse_iterator<it2> &i) : rvi(i.base()){ }

        // getter
        iterator_type base() const
        {
            return  (rvi);
        }

        // operators

        reverse_iterator& operator=(const reverse_iterator& i)
        {
            this->rvi = i.rvi;
            return (*this);
        }

        reference operator*()
        {
            return (*(this->rvi - 1));
        }

        pointer operator->()
        {
            return &(operator*());
        }

        reverse_iterator& operator++()
        {
            --this->rvi;
            return (*this);
        }

        reverse_iterator operator++(int)
        {
            reverse_iterator tmp;

            tmp.rvi = this->rvi--;
            return (tmp);
        }

        reverse_iterator& operator--()
        {
            ++this->rvi;
            return (*this);
        }

        reverse_iterator operator--(int)
        {
            reverse_iterator tmp;

            tmp.rvi = this->rvi++;
            return (tmp);
        }

        reverse_iterator operator+ (difference_type indx)
        {
            reverse_iterator tmp;

            tmp.rvi = this->rvi - indx;
            return (tmp);
        }

        reverse_iterator operator-(difference_type indx)
        {
            return (reverse_iterator(this->rvi + indx));
        }

        reverse_iterator &operator+= (difference_type indx)
        {
            this->rvi = this->rvi - indx;
            return (*this);
        }

        reverse_iterator &operator-= (difference_type indx)
        {
            this->rvi = this->rvi + indx;
            return (*this);
        }

        reference operator[] (difference_type indx)
        {
            return (this->rvi[indx - 1]);
        }

        template<class it1, class it2>
        friend bool operator== (const reverse_iterator<it1> &ob1, const reverse_iterator<it2> &ob2);

        template<class it1, class it2>
        friend bool operator!= (const reverse_iterator<it1> &ob1, const reverse_iterator<it2> &ob2);

        template<class it1, class it2>
        friend bool operator> (const reverse_iterator<it1> &ob1, const reverse_iterator<it2> &ob2);

        template<class it1, class it2>
        friend bool operator< (const reverse_iterator<it1> &ob1, const reverse_iterator<it2> &ob2);

        template<class it1, class it2>
        friend bool operator>= (const reverse_iterator<it1> &ob1, const reverse_iterator<it2> &ob2);

        template<class it1, class it2>
        friend bool operator<= (const reverse_iterator<it1> &ob1, const reverse_iterator<it2> &ob2);

        template<class it1, class it2>
        friend typename reverse_iterator<it1>::difference_type operator-(const reverse_iterator<it1> &a, const reverse_iterator<it2> &b);


        template<class it>
        friend reverse_iterator<it> operator+(typename reverse_iterator<it>::difference_type a, const reverse_iterator<it> &b);

   };

    template<class it1, class it2>
    bool operator== (const reverse_iterator<it1> &ob1, const reverse_iterator<it2> &ob2)
    {
        return (ob1.base() == ob2.base());
    }
    template<class it1, class it2>
    bool operator!= (const reverse_iterator<it1> &ob1, const reverse_iterator<it2> &ob2)
    {
        return (ob1.base() != ob2.base());
    }
    template<class it1, class it2>
    bool operator> (const reverse_iterator<it1> &ob1, const reverse_iterator<it2> &ob2)
    {
        return (ob1.base() < ob2.base());
    }
    template<class it1, class it2>
    bool operator< (const reverse_iterator<it1> &ob1, const reverse_iterator<it2> &ob2)
    {
        return (ob1.base() > ob2.base());
    }
    template<class it1, class it2>
    bool operator>= (const reverse_iterator<it1> &ob1, const reverse_iterator<it2> &ob2)
    {
        return (ob1.base() <= ob2.base());
    }
    template<class it1, class it2>
    bool operator<= (const reverse_iterator<it1> &ob1, const reverse_iterator<it2> &ob2)
    {
        return (ob1.base() >= ob2.base());
    }
    template<class it1, class it2>
    typename reverse_iterator<it1>::difference_type operator-(const reverse_iterator<it1> &a, const reverse_iterator<it2> &b)
    {
        return (b.base() - a.base());
    }
    template<class it>
    reverse_iterator<it> operator+(typename reverse_iterator<it>::difference_type a, const reverse_iterator<it> &b)
    {
        return (reverse_iterator<it>(b.base() - a));
    }


}
