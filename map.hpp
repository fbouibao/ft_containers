#pragma once

#include <iostream>
#include <memory>
#include "pair.hpp"
#include "avl.hpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_type.hpp"
#include "algorithms.hpp"
#include "vector.hpp"


namespace ft
{
	template < class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
			>
	class map
	{
		public:
			// types:
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef pair<const key_type, mapped_type>	value_type;
			typedef Compare								key_compare;
			typedef class value_compare : public std::binary_function<value_type, value_type, bool>
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class map;
				protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
				public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
			}															value_compare;
			typedef		Alloc												allocator_type;
			typedef		typename	allocator_type::reference				reference;
			typedef		typename	allocator_type::const_reference			const_reference;
			typedef		typename	allocator_type::pointer					pointer;
			typedef		typename	allocator_type::const_pointer			const_pointer;
			typedef		std::ptrdiff_t										difference_type;
			typedef		size_t												size_type;
		private:
			typedef		avl<value_type, Compare, Alloc> Tree;
			typedef		typename avl<value_type, Compare, Alloc>::Node Node;
			typename Alloc::template rebind<Tree>::other _alloc_avl;
			Tree				_tree;
			size_type			_size;
			allocator_type		_map_alloc;
			key_compare			_key_map_compare;
			int a;
		public:
			typedef		map_iterator<value_type, Node, Tree>				iterator;
			typedef		map_iterator<const value_type, const Node, Tree>	const_iterator;
			typedef		ft::reverse_iterator<iterator>						reverse_iterator;
			typedef		ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		
		
		
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			this->_tree._node = NULL;
			this->_map_alloc = alloc;
			this->_key_map_compare = comp;
			this->_tree._ob_c = comp;
			this->_size = 0;
			this->a = 0;
		}
	
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			this->_tree._node = NULL;
			this->_map_alloc = alloc;
			this->_key_map_compare = comp;
			this->_tree._ob_c = comp;
			this->_size = 0;
			this->insert(first, last);
		}

		map (const map& x)
		{
			*this = x;
		}

		~map()
		{
			this->clear();
		}

		map& operator= (const map& x)
		{
			this->_map_alloc = x._map_alloc;
			this->_key_map_compare = x._key_map_compare;
			this->_tree._ob_c = x._tree._ob_c;
			this->_tree.remove_tre(this->_tree._node);
			this->_tree._node = NULL;
			for (const_iterator it = x.begin(); it != x.end(); ++it)
			{
				this->insert(*it);
			}
			this->_size = x._size;
			return (*(this));
		}

	    iterator begin()
		{
			if (this->_tree._node == NULL)
				return (iterator(_tree, NULL));
			return (iterator(_tree, _tree.min_node(_tree._node)));
		}

		const_iterator begin() const
		{
			if (this->_tree._node == NULL)
				return (const_iterator(_tree, NULL));
			return (const_iterator(_tree, _tree.min_node(_tree._node)));
		}

			iterator end() {
				return iterator(_tree, _tree._end_node);
			}
			const_iterator end() const {
				return const_iterator(_tree, _tree._end_node);
			}

	    reverse_iterator rbegin()
		{
			return (reverse_iterator(end()));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(end()));
		}

	    reverse_iterator rend()
		{
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(begin()));
		}

		bool empty () const
		{
			return (this->_size == 0);
		}

		size_type size() const
		{
			return (this->_size);
		}

		size_type max_size() const
		{
			return (this->_tree.max_size());
		}

		mapped_type& operator[] (const key_type& k)
		{
				ft::pair<T&, bool> result = _tree[k];
				if (result.second == true)
					++(this->_size);
				return (result.first);
		}

		pair<iterator,bool> insert (const value_type& val)
		{
			iterator it = this->find(val.first);

			if (it != this->end())
				return (ft::make_pair<iterator, bool>(it, false));

			Node *tmp = this->_tree.insert(this->_tree._node, val.first, val.second);
			++(this->_size);
			return (ft::make_pair<iterator, bool>(iterator(this->_tree, tmp), true));
		}

		iterator insert (iterator position, const value_type& val)
		{
			(void)position;
			iterator it = this->find(val.first);

			if (it != this->end())
				return (it);

			Node *tmp = this->_tree.insert(this->_tree._node, val.first, val.second);
			++(this->_size);
			return (iterator(this->_tree, tmp));
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{

			while (first != last)
			{
				this->insert(*first);
				first++;
			}
			
		}

    	void erase (iterator position)
		{
			if (this->find(position->first) != this->end())
			{
				this->_tree.delete_node(this->_tree._node, position->first);
				this->_size--;
			}
		}

		size_type erase (const key_type& k)
		{
			if (this->find(k) != this->end())
			{
				this->_tree.delete_node(this->_tree._node, k);
				this->_size--;
				this->a++;
				return (1);
			}
			return (0);
		}

    	void erase (iterator first, iterator last)
		{
			ft::vector<Key> v;

			for (; first != last; first++)
			{
				v.push_back(first->first);
			}
			std::cout << " size "  << v.size() << std::endl;
			for (size_t i = 0; i < v.size(); i++)
			{
				this->erase(v[i]);
				std::cout << "ddddddd" << std::endl;
			}
			std::cout << "hhhhhhhh" << std::endl;	
		}

		void swap (map& x)
		{
			Tree tree;
			size_type size_tmp;

			tree = x._tree;
			x._tree = this->_tree;
			this->_tree = tree;

			size_tmp = x._size;
			x._size = this->_size;
			this->_size = size_tmp;
		}

		void clear()
		{
			this->_tree.remove_tre(this->_tree._node);
			this->_size = 0;
		}

        iterator find (const key_type& k)
        {
			Node *n = _tree.search(_tree._node, k);
			if (n)
				return (iterator(this->_tree, n));
			return (this->end());
        }

        const_iterator find (const key_type& k) const
        {
			Node *n = _tree.search(_tree._node, k);
			if (n)
				return (const_iterator(this->_tree, n));
			return (this->end());
        }

        size_type count (const key_type& k) const
        {
			if (this->find(k) == this->end())
				return (0);
			return (1);
        }

        iterator lower_bound (const key_type& k)
        {
			// iterator it = this->find(k);
			// if (it == this->end())
			// 	return (this->end());
			return (iterator(this->_tree, this->_tree._node));
        }

        const_iterator lower_bound (const key_type& k) const
        {
			return (const_iterator(this->_tree, this->_tree._node));
        }

        iterator upper_bound (const key_type& k)
        {
			return (iterator(this->_tree, this->_tree._node));
        }

        const_iterator upper_bound (const key_type& k) const
        {
			return (const_iterator(this->_tree, this->_tree._node));
        }

        pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        {
            return (ft::make_pair(const_iterator(), const_iterator()));
        }

        pair<iterator,iterator>             equal_range (const key_type& k)
        {
            return (ft::make_pair(iterator(), iterator()));
        }

		key_compare key_comp() const
		{
			return (this->_key_map_compare);
		}

		value_compare value_comp() const
		{
			return (value_compare(this->_key_map_compare));
		}

		allocator_type get_allocator() const
		{
			return (this->_map_alloc);
		}
	};

	template <class Key, class T, class Compare, class Alloc>
	void	swap (map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y)
	{
		x.swap(y);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator == (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator != (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator > (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator < (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator >= (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
			return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator <= (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs > rhs));
	}

}