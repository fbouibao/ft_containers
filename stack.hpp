#include <iostream>
#include "vector.hpp"


namespace ft{ 
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        typedef     T   value_type;
        typedef     Container   container_type;
        typedef     size_t   size_type;
        
    private:
        container_type vec;
    public:
        explicit stack (const container_type& ctnr = container_type()) : vec(ctnr){}    

        bool empty() const
        {
            return (vec.empty());
        }

        size_type size() const
        {
            return (vec.size());
        }

        value_type& top()
        {
            return (vec.back());
        }

        const value_type& top() const
        {
            return (vec.back());
        }

        void push (const value_type& val)
        {
            vec.push_back(val);
        }

        void pop()
        {
            vec.pop_back();
        }

        template <class Tp, class Cntr>
        friend bool operator == (const stack<Tp, Cntr>& lhs, const stack<Tp, Cntr>& rhs) { return (lhs.vec == rhs.vec);}
        template <class Tp, class Cntr>
        friend bool operator != (const stack<Tp, Cntr>& lhs, const stack<Tp, Cntr>& rhs) { return (!(lhs.vec == rhs.vec));}
        template <class Tp, class Cntr>
        friend bool operator <  (const stack<Tp, Cntr>& lhs, const stack<Tp, Cntr>& rhs) { return (lhs.vec < rhs.vec);}
        template <class Tp, class Cntr>
        friend bool operator <= (const stack<Tp, Cntr>& lhs, const stack<Tp, Cntr>& rhs) { return (lhs.vec <= rhs.vec);}
        template <class Tp, class Cntr>
        friend bool operator >  (const stack<Tp, Cntr>& lhs, const stack<Tp, Cntr>& rhs) { return (lhs.vec > rhs.vec);}
        template <class Tp, class Cntr>
        friend bool operator >= (const stack<Tp, Cntr>& lhs, const stack<Tp, Cntr>& rhs) { return (lhs.vec >= rhs.vec);}

    };
}


