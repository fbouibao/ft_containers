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
            struct node* parent; // needed by find(), insert(), etc. (the rb tree uses it too by the way)
            struct node* left;
            struct node* right;
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
            this->_end_node->height = 19;
        }

        ~avl()
        {
            // _alloc_node.deallocate(_end_node, 1);
        }

        Node *get_head(Node *node)
        {
        	Node * nodeParent = node;
			while (1) {
                if (nodeParent == NULL || nodeParent->parent == NULL)
                    return (nodeParent);
				nodeParent = nodeParent->parent;
			}
			return (nodeParent);
        }

        Node *new_node(const value_type &pair_val, Node *parent)
        {
            Node *node = this->_alloc_node.allocate(1);
            node->value = this->_alloc_pair.allocate(1);
            this->_alloc_pair.construct(node->value, pair_val);
            node->left = NULL;
            node->right = NULL;
            node->parent = parent;
            node->height = 1;
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


        Node *rotate_right(Node *z)
        {
				Node * y = z->left;
				Node * T3 = y->right;

				y->right = z;
				z->left = T3;
				
				y->parent = z->parent;
				z->parent = y;
				if (T3)
					T3->parent = z;

				z->height = this->max(this->node_height(z->left), this->node_height(z->right)) + 1;
				y->height = this->max(this->node_height(y->left), this->node_height(y->right)) + 1;
				return (y);
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

        Node *rotate_left(Node *z)
        {
				Node	*	y = z->right;
				Node	*	T2 = y->left;

				y->left = z;
				z->right = T2;

				y->parent = z->parent;
				z->parent = y;
				if (T2)
					T2->parent = z;
				
				z->height = this->max(this->node_height(z->left), this->node_height(z->right)) + 1;
				y->height = this->max(this->node_height(y->left), this->node_height(y->right)) + 1;

				return (y);
        }


        Node *insert(Node * &node, key k, T value, Node *parent = NULL)
        {
            Node *tmp;
            if (node == NULL)
            {
                node = this->new_node(ft::make_pair<key, T>(k, value), parent);
                tmp = node;
                this->_node = get_head(node);
                // std::cout << "here1" << std::endl;
            // std::cout << this->_node->value->first << " " << this->_node->value->second <<  std::endl;

                return (tmp);
            }
            if (this->_ob_c(k, node->value->first))
            {
                // std::cout << "here2" << std::endl;
            // std::cout << this->_node->value->first << " " << this->_node->value->second <<  std::endl;
                
                tmp = insert(node->left, k, value, node);
            }
            else if (this->_ob_c(node->value->first, k))
            {
                // std::cout << "here3" << std::endl;
                
                tmp = insert(node->right, k, value, node);
                // if (node->right)
            // std::cout << _node->right->value->first << " " << _node->right->value->second <<  std::endl;
            }
            else
            {
            // std::cout << this->_node->value->first << " " << this->_node->value->second <<  std::endl;

                this->_node = get_head(node);
                return (node);
            }
            node->height = 1 + max(node_height(node->left), node_height(node->right));
            int balance = balanced(node);

                // std::cout << "here2" << std::endl;
            // return (tmp);
            if (balance > 1 && this->_ob_c(k, node->left->value->first) == true)
            {

                node = rotate_right(node);
            }
            // return (tmp);

            if (balance < -1 && this->_ob_c(node->right->value->first, k) == true)
            {
                node = rotate_left(node);
            }

            if (balance > 1 && this->_ob_c(node->left->value->first, k) == true)
            {
                node->left = rotate_left(node->left);
                node = rotate_right(node);
            }

            if (balance < -1 && this->_ob_c(k, node->right->value->first))
            {
                node->right = rotate_right(node->right);
                node = rotate_left(node);
            }
            this->_node = get_head(node);
            // std::cout << this->_node->value->first << " " << this->_node->value->second <<  std::endl;
                // std::cout << "here4" << std::endl;

            // std::cout << this->_node->value->first << " " << this->_node->value->second <<  std::endl;

            return (tmp);
        }

        Node *min_node(const Node *node) const
        {
            Node *tmp;

            tmp = (Node *)node;
            while (tmp->left)
            {
                tmp = tmp->left;
            }
            return (tmp);
        }

        Node *max_node(const Node *node) const
        {
			Node	*	tmp = (Node *)node;

			// while (tmp->parent != NULL) {
			// 	tmp = tmp->parent;
			// }
			while (tmp->right)
				tmp = tmp->right;
			return (tmp);
        }

        void delete_node(Node * &node, key k)
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
                    this->_alloc_pair.deallocate(tmp->value, 1);
                    this->_alloc_node.deallocate(tmp, 1);
                }
                else
                {
                    Node *min = min_node(node->right);
                    std::swap(min->value, node->value);
                    this->delete_node(node->right, min->value->first);
                }
            }
            if (node == NULL)
                return ;
            node->height = 1 + max(node_height(node->left), node_height(node->right));
            int balance = balanced(node);
            if (balance > 1 && balanced(node->left) >= 0)
            {
                node = rotate_right(node);
            }

            if (balance < -1 && balanced(node->right) <= 0)
            {
                node = rotate_left(node);
            }

            if (balance > 1 && balanced(node->left) < 0)
            {
                node->left = rotate_left(node->left);
                node = rotate_right(node);
            }

            if (balance < -1 && balanced(node->right) > 0)
            {
                node->right = rotate_right(node->right);
                node = rotate_left(node);
            }
            this->_node = get_head(node);
        }

        Node *search(Node *node, key k) const
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

        void    remove_tre(Node * &node)
        {
            if (node == NULL)
                return ;
            remove_tre(node->left);
            remove_tre(node->right);
            this->_alloc_pair.deallocate(node->value, 1);
            this->_alloc_node.deallocate(node, 1);
            // this->_node.value
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

        Node *getsuccesor(const Node *node) const
        {

			if (node == NULL)
				return NULL;
			if (node->right)
				return (min_node(node->right));

			Node * nodeParent = node->parent;
			while (nodeParent != NULL && node == nodeParent->right) {
				node = nodeParent;
				nodeParent = nodeParent->parent;
			}
			return (nodeParent);
        }

        Node *getpresuccesor(const Node *node) const
        {
			if (node == NULL)
				return (NULL);
            
			if (node->left)
				return (max_node(node->left));
			Node * nodeParent = node->parent;
			while (nodeParent != NULL && node == nodeParent->left) {
				node = nodeParent;
				nodeParent = nodeParent->parent;
			}
			return (nodeParent);
        }

        void displayallnode()
        {
            Node *nd = this->min_node(this->_node);
            std::cout << nd->value->first << " " << nd->value->second << std::endl;
            while (nd != _end_node)
            {
                nd = getsuccesor(nd);
                std::cout << nd->value->first << " " << nd->value->second << std::endl;
                if (nd == this->max_node(this->_node))
                    break;
            }
            
            
        }

			ft::pair<T&, bool>			operator[] (const key& k) {
				Node	*	tmp = this->search(this->_node, k);
				if (tmp != NULL)
					return (ft::make_pair<T&, bool>(tmp->value->second, false));
				tmp = this->insert(this->_node, k, T());
				return (ft::make_pair<T&, bool>(tmp->value->second, true));
			}

        Node* bound(const Node *node, const key &k) const
        {
        	Node * current = min_node((Node *)node);
			while (current)
			{
				if (_ob_c(k, current->value->first)) {
                    return (current);
                }
				current = getsuccesor(current);
			}
			return this->_end_node;
        }

    };

}