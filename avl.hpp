#pragma once

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
        Node *_end_node;
        Compare _ob_c;
        typename Alloc::template rebind<Node>::other _alloc_node;
        Alloc   _alloc_pair;

        avl()
        {
            this->_node = NULL;
            this->_end_node = _alloc_node.allocate(1);
        }

        ~avl()
        {
            _alloc_node.deallocate(_end_node, 1);
        }

        Node *get_head(Node *node)
        {
        	Node * nodeParent = node->parent;
			while (nodeParent != NULL) {
				nodeParent = nodeParent->parent;
			}
			return (nodeParent);
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
                    B   1                                 C     A
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
            this->_node = get_head(node);
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
            this->_node = get_head(node);
            return (b);
        }


        Node *insert_node(Node *node, key k, T value, Node *parent = NULL)
        {
            Node *tmp;

            if (node == NULL)
            {
                node = this->new_node(ft::make_pair<key, T>(k, value), parent);
                tmp = node;
                this->_node = get_head(node);
                return (tmp);
            }
            if (this->_ob_c(k, node->value->first))
            {
                tmp = insert_node(node->left, k, value, node);
            }
            else if (this->_ob_c(node->value->first, k))
            {
                tmp = insert_node(node->right, k, value, node);
            }
            else
            {
                this->_node = get_head(node);
                return (node);
            }
            node->height = 1 + max(node_height(node->left), node_height(node->right));
            int balance = balanced(node);
            if (std::abs(balance) > 1 && this->_ob_c(k, node->left->value->first))
            {
                rotate_right(node);
            }

            if (std::abs(balance) > 1 && this->_ob_c(node->right->value->first, k))
            {
                rotate_left(node);
            }

            if (std::abs(balance) > 1 && this->_ob_c(node->left->value->first, k))
            {
                node->left = rotate_left(node->left);
                node = rotate_right(node);
            }

            if (std::abs(balance) > 1 && this->_ob_c(k, node->right->value->first))
            {
                node->right = rotate_right(node->right);
                node = rotate_left(node);
            }
            this->_node = get_head(node);
            return (tmp);
        }

        Node *min_node(Node *node)
        {
            Node *tmp;

            tmp = node;
            while (tmp->left)
            {
                tmp = tmp->left;
            }
            return (tmp);
        }

        Node *max_node(Node *node)
        {
            Node *tmp;

            tmp = node;
            while (tmp->right)
            {
                tmp = tmp->right;
            }
            return (tmp);
        }

        void delete_node(Node *node, key k)
        {
            if (node == NULL)
            {
                return ;
            }
            if (this->_ob_c(node->value->first, k))
            {
                delete_node(node->right, k);
            }
            else if (this->_ob_c(k, node->value->first))
            {
                delete_node(node->left, k);
            }
            else
            {
                // node->value->first == key
                if (node->left == NULL || node->right == NULL)
                {
                    Node *tmp = node->left ? node->left : node->right;
                    if (tmp == NULL)
                    {
                        tmp = node;
                        node = NULL;
                    }
                    else
                    {
                        std::swap(node->value, tmp->value);
                        node->left = tmp->left;
                        node->right = tmp->right;
                        node->height = tmp->height;
                    }
                    this->_alloc_pair.dealocate(tmp->value, 1);
                    this->_alloc_node.dealocate(tmp, 1);
                }
                else
                {
                    Node *min = min_node(node->right);
                    std::swap(min->value, node->value);
                    this->delete_node(node->right, node->value->first);
                }
            }
            if (node == NULL)
                return ;
            node->height = 1 + max(node_height(node->left), node_height(node->right));
            int balance = balanced(node);
            if (std::abs(balance) > 1 && balanced(node->left) >= 0)
            {
                rotate_right(node);
            }

            if (std::abs(balance) > 1 && balanced(node->right) <= 0)
            {
                rotate_left(node);
            }

            if (std::abs(balance) > 1 && balanced(node->left) < 0)
            {
                node->left = rotate_left(node->left);
                node = rotate_right(node);
            }

            if (std::abs(balance) > 1 && balanced(node->right) > 0)
            {
                node->right = rotate_right(node->right);
                node = rotate_left(node);
            }
            this->_node = get_head(node);
        }

        Node *search(Node *node, key k)
        {
            Node *tmp;

            if (node == NULL)
                return (NULL);
            tmp = node;
            if (this->_ob_c(node->value->first, k))
            {
                tmp = search(node->right, k);
            }
            else if (this->_ob_c(k, node->value->first))
            {
                tmp = search(node->left, k);
            }
            return (tmp);
        }

        void    remove_tre(Node *node)
        {
            if (node == NULL)
                return ;
            remove_tre(node->left);
            remove_tre(node->right);
            this->_alloc_pair.dealocate(node->value, 1);
            this->_alloc_node.dealocate(node, 1);
            node = NULL;
        }
    
        bool    empty(Node *node)
        {
            return (node == NULL);
        }

        size_type   max_size() const
        {
            return (this->_alloc_node.max_size());
        }

        Node *getsuccesor(const Node *node)
        {
            if (node == NULL)
                return (NULL);
            if (node->right)
                return (min_node(node->right));
            return (NULL);
        }

        Node *getpresuccesor(const Node *node)
        {
            if (node == NULL)
                return (NULL);
            if (node->left)
                return (min_node(node->left));
            return (NULL);
        }
    };
    
 
    
}