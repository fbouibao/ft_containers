#pragma once

#include <iostream>
#include <memory>
#include "iterator_traits.hpp"


namespace ft{

    template<class T>
    class iter
    {
        public:
            typedef T					                                iterator_type;
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;
			typedef typename ft::iterator_traits<T>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T>::iterator_category  iterator_category;


    private:
        iterator_type itr;

    public:
        // constructors
        iter() : itr(NULL) { }
        explicit iter(iterator_type it) : itr(it) { }
        template<typename it2>
        iter(const iter<it2> &i) : itr(i.base()){ }

        // getter
        iterator_type base() const
        {
            return (this->itr);
        }

        // operators

        iter& operator=(const iter& i)
        {
            this->itr = i.itr;
            return (*this);
        }

        reference operator*()
        {
            return *this->itr;
        }

        pointer operator->()
        {
            return this->itr;
        }

        iter& operator++()
        {
            ++this->itr;
            return (*this);
        }

        iter operator++(int)
        {
            iter tmp;

            tmp.itr = this->itr++;
            return (tmp);
        }

        iter& operator--()
        {
            --this->itr;
            return (*this);
        }

        iter operator--(int)
        {
            iter tmp;

            tmp.itr = this->itr--;
            return (tmp);
        }

        iter operator+ (difference_type indx)
        {
            iter tmp;

            tmp.itr = this->itr + indx;
            return (tmp);
        }

        iter operator-(difference_type indx)  const
        {
            return (iter(this->itr - indx));
        }

        iter &operator+= (difference_type indx)
        {
            this->itr = this->itr + indx;
            return (*this);
        }

        iter &operator-= (difference_type indx)
        {
            this->itr = this->itr - indx;
            return (*this);
        }

        reference operator[] (difference_type indx)
        {
            return (this->itr[indx]);
        }

        template<class it1, class it2>
        friend bool operator== (const iter<it1> &ob1, const iter<it2> &ob2);

        template<class it1, class it2>
        friend bool operator!= (const iter<it1> &ob1, const iter<it2> &ob2);

        template<class it1, class it2>
        friend bool operator> (const iter<it1> &ob1, const iter<it2> &ob2);

        template<class it1, class it2>
        friend bool operator< (const iter<it1> &ob1, const iter<it2> &ob2);

        template<class it1, class it2>
        friend bool operator>= (const iter<it1> &ob1, const iter<it2> &ob2);

        template<class it1, class it2>
        friend bool operator<= (const iter<it1> &ob1, const iter<it2> &ob2);

        template<class it1, class it2>
        friend typename iter<it1>::difference_type operator-(const iter<it1> &a, const iter<it2> &b);


        template<class it>
        friend iter<it> operator+(typename iter<it>::difference_type a, const iter<it> &b);

   };

    template<class it1, class it2>
    bool operator== (const iter<it1> &ob1, const iter<it2> &ob2)
    {
        return (ob1.base() == ob2.base());
    }
    template<class it1, class it2>
    bool operator!= (const iter<it1> &ob1, const iter<it2> &ob2)
    {
        return (ob1.base() != ob2.base());
    }
    template<class it1, class it2>
    bool operator> (const iter<it1> &ob1, const iter<it2> &ob2)
    {
        return (ob1.base() > ob2.base());
    }
    template<class it1, class it2>
    bool operator< (const iter<it1> &ob1, const iter<it2> &ob2)
    {
        return (ob1.base() < ob2.base());
    }
    template<class it1, class it2>
    bool operator>= (const iter<it1> &ob1, const iter<it2> &ob2)
    {
        return (ob1.base() >= ob2.base());
    }
    template<class it1, class it2>
    bool operator<= (const iter<it1> &ob1, const iter<it2> &ob2)
    {
        return (ob1.base() <= ob2.base());
    }
    template<class it1, class it2>
    typename iter<it1>::difference_type operator-(const iter<it1> &a, const iter<it2> &b)
    {
        return (a.base() - b.base());
    }
    template<class it>
    iter<it> operator+(typename iter<it>::difference_type a, const iter<it> &b)
    {
        return (iter<it>(a + b.base()));
    }

}
