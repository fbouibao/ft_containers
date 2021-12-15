#include <iostream>
#include <memory>

template<class T>
class iter
{
private:
    T *i;
public:
    iter()
    {

    }
    iter(T *i)
    {
       this->i = i; 
    }
    ~iter(){}
    // iter *operator=(const iter *f)
    // {
    //     this->i = f;
    // }



    T& operator*()
    {
        // this->i = f.;
        return *this->i;
    }

    iter<T> operator++ (int)
    {
        iter<T> tmp;

        tmp.i = this->i++;
        return (tmp);
    }

    iter<T> operator++ ()
    {
        ++this->i;
        return (*this);
    }


    iter<T> operator-- (int)
    {
        iter<T> tmp;

        tmp.i = this->i--;
        return (tmp);
    }

    iter<T> operator-- ()
    {
        --this->i;
        return (*this);
    }

    iter<T> operator+ (T indx)
    {
        iter<T> tmp;

        tmp.i = this->i + indx;
        return (tmp);
    }

    iter<T> operator- (T indx)
    {
        iter<T> tmp;

        tmp.i = this->i - indx;
        return (tmp);
    }
};
