#include <iostream>
#include <memory>
#include "pair.hpp"
#include "reverse_iterator.hpp"
#include "enable_type.hpp"
#include "algorithms.hpp"
#include <cmath>

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

        Node *_node;
        Compare _ob_c;
        typename Alloc::template rebind<Node>::other _alloc_node;
        Alloc   _alloc_pair;



        avl()
        {
            

        }
        ~avl()
        {

        }

        Node *new_node(value_type pair_val, Node *parent)
        {
            Node *node = this->_alloc_node.allocate(1);
            node->value = this->_alloc_pair.allocate(1);
            this->_alloc_pair.construct(node->value, pair_val);
            node->left = NULL;
            node->right = NULL;
            node->parent = parent;
            node->hight = 1;
            return (node);
        }

        int max(int a, int b)
        {
            return (a > b ? a : b); 
        }

        int node_height(Node *node)
        {
            if (node == NULL)
                return (0);
            return (node->height);
        }
        
        int balanced(Node *node)
        {
            if (node == NULL)
                return (0);
            return (node_height(node->left) - node_height(node->right));
        }

			/*
                      A                                      B 
                     / \                                   /   \
                    B   1                                 x     A
                   / \          - - - - - - - - ->      /  \   /  \ 
                  C   2                                4    3 2    1
                 / \
                4   3
			*/


        Node *rotate_right(Node *node)
        {
            Node *b = node->left;
            Node *n2 = b->right;

            b->right = node;
            node->left = n2;
            b->parent = node->parent;
            node->parent = b;
            if (n2)
                n2->parent = node;
            node->height = this->max(this->node_height(node->left), this->node_height(node->right)) + 1;
            b->height = this->max(this->node_height(b->left), this->node_height(b->right)) + 1;
            return (b);
        }

		/*
          A                                B
         /  \                            /   \ 
        1    B                          A      C
            /  \   - - - - - - - ->    / \    / \
           2    C                     1   2  3   4
               / \
              3   4
		*/

        Node *rotate_left(Node *node)
        {
            Node *b = node->right;
            Node *n2 = b->left;

            b->right = node;
            node->left = n2;
            b->parent = node->parent;
            node->parent = b;
            if (n2)
                n2->parent = node;
            node->height = this->max(this->node_height(node->left), this->node_height(node->right)) + 1;
            b->height = this->max(this->node_height(b->left), this->node_height(b->right)) + 1;
            return (b);
        }


        Node *insert_node(Node *node, key k, T value, Node *parent = NULL)
        {
            Node *tmp;

            if (node == NULL)
            {
                node = this->new_node(ft::make_pair<key, T>(k, value), parent);
                tmp = node;
                return (tmp);
            }
            if (key_compare(k, node->value->first))
            {
                tmp = insert_node(node->left, k, value, node);
            }
            else if (key_compare(node->value->first, k))
            {
                tmp = insert_node(node->right, k, value, node);
            }
            else
            {
                return (node);
            }
            node->height = 1 + max(node_height(node->left), node_height(node->right));
            int balance = balanced(node);
            if (std::abs(balance) > 1 && this->_ob_c(k, node->left->value->first))
            {
                retate_right(node);
            }

            if (std::abs(balance) > 1 && this->_ob_c(node->left->value->first, k))
            {
                retate_left(node);
            }

        }
    };
    
 
    
}