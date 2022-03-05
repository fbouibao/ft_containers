#include "base_iterator.hpp"

namespace ft{
    template <class value_type_pair, class Node, class Tree>
    class map_iterator : public base_iterator<std::bidirectional_iterator_tag, value_type_pair>
    {
        typedef base_iterator<std::bidirectional_iterator_tag, value_type_pair>::difference_type difference_type;
        typedef base_iterator<std::bidirectional_iterator_tag, value_type_pair>::value_type value_type;
        typedef base_iterator<std::bidirectional_iterator_tag, value_type_pair>::pointer pointer;
        typedef base_iterator<std::bidirectional_iterator_tag, value_type_pair>::reference reference;
        typedef base_iterator<std::bidirectional_iterator_tag, value_type_pair>::iterator_category iterator_category;

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
            
        }

    };
    
    
}