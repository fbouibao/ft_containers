#pragma once

#include "base_iterator.hpp"
// #include "avl.hpp"

namespace ft{
    template <class value_type_pair, class Node, class Tree>
    class map_iterator : public base_iterator<std::bidirectional_iterator_tag, value_type_pair>
    {
        typedef typename base_iterator<std::bidirectional_iterator_tag, value_type_pair>::difference_type difference_type;
        typedef typename base_iterator<std::bidirectional_iterator_tag, value_type_pair>::value_type value_type;
        typedef typename base_iterator<std::bidirectional_iterator_tag, value_type_pair>::pointer pointer;
        typedef typename base_iterator<std::bidirectional_iterator_tag, value_type_pair>::reference reference;
        typedef typename base_iterator<std::bidirectional_iterator_tag, value_type_pair>::iterator_category iterator_category;

    private:
        Tree _tree;
        Node _node;

    public:
        map_iterator()
        {
        }
        
        map_iterator(Tree *tree, Node *node)
        {
            this->_tree = tree;
            this->_node = node;
        }
    

        map_iterator(const map_iterator &it)
        {
            *this = it;
        }

        Node *base(){return (this->_node);}

        map_iterator &operator = (const map_iterator &it)
        {
            this->_tree = it._tree;
            this->_node = it._node;
            return (*this);
        }

        ~map_iterator()
        {
        }

        map_iterator & operator ++ ()
        {
            this->_node = this->_tree->getsuccesor(this->_node);
            return (*this);
        }

        map_iterator   operator ++ (int)
        {
            Node *tmp = this->_node;
            this->_node = this->_tree->getsuccesor(this->_node);
            return (map_iterator(this->_tree, tmp));
        }

        map_iterator & operator -- ()
        {
            this->_node = this->_tree->getpresuccesor(this->_node);
            return (*this);
        }

        map_iterator   operator -- (int)
        {
            Node *tmp = this->_node;
            this->_node = this->_tree->getpresuccesor(this->_node);
            return (map_iterator(this->_tree, tmp));
        }    

        map_iterator    operator + (difference_type a)
        {
            Node *tmp = this->_tree->getsuccesor(this->_node);
            while (--a)
            {
                tmp = this->_tree->getsuccesor(this->_node);
            }
            return (map_iterator(this->_tree, tmp));
        }

        reference operator * ()
        {
            return (*(this->_node->value));
        }

        reference operator -> ()
        {
            return (this->_node->value);
        }

        template <class it, class it2>
        friend bool operator== (const it &i, const it2 &i2);

        template <class it, class it2>
        friend bool operator!= (const it &i, const it2 &i2);

    };
    
    template <class it, class it2>
    bool operator== (const it &i, const it2 &i2)
    {
        return (i.base() == i2.base());
    }

    template <class it, class it2>
    bool operator!= (const it &i, const it2 &i2)
    {
        return (!(i == i2));
    }

}