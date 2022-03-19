#pragma once

#include <iostream>
#include <memory>
#include "pair.hpp"
#include "avl.hpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_type.hpp"
#include "algorithms.hpp"


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
				// friend class map;
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
		public:
			typedef		map_iterator<value_type, Node, Tree>				iterator;
			typedef		map_iterator<const value_type, const Node, Tree>	const_iterator;
			typedef		ft::reverse_iterator<iterator>						reverse_iterator;
			typedef		ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		
		
		
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			// this->_tree = this->_alloc_avl.allocate(1);
			// this->_alloc_avl.construct(this->_tree);
			this->_tree._node = NULL;
			this->_map_alloc = alloc;
			this->_key_map_compare = comp;
			this->_tree._ob_c = comp;
		}
	
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			this->_tree._node = NULL;
			this->_map_alloc = alloc;
			this->_key_map_compare = comp;
			this->_tree._ob_c = comp;
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

			// mapped_type& operator[] (const key_type& k)		{

			// }

		pair<iterator,bool> insert (const value_type& val)
		{
			iterator it = this->find(val.first);

			if (this->_tree._node && it != this->end())
				return (ft::make_pair<iterator, bool>(it, false));

			Node *tmp = this->_tree.insert(this->_tree._node, val.first, val.second);
			++(this->_size);
			return (ft::make_pair<iterator, bool>(iterator(this->_tree, tmp), true));
		}

		iterator insert (iterator position, const value_type& val)
		{
			return (iterator(this->_tree, NULL));
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{

		}

    	void erase (iterator position)
		{

		}

		size_type erase (const key_type& k)
		{
			
		}

    	void erase (iterator first, iterator last)
		{
			
		}

		void swap (map& x)
		{

		}

		void clear()
		{
			
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

        }

        iterator lower_bound (const key_type& k)
        {

        }

        const_iterator lower_bound (const key_type& k) const
        {

        }

        iterator upper_bound (const key_type& k)
        {

        }

        const_iterator upper_bound (const key_type& k) const
        {

        }

        pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        {
            
        }

        pair<iterator,iterator>             equal_range (const key_type& k)
        {
            
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