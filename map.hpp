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
			}																value_compare;
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
			Tree				_tree;
			type_size			_size;
			allocator_type		_map_alloc;
			key_compare			_key_map_compare;
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
			for (const_itarator it = x.begin(); it != x.end(); ++it)
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
			return (iterator(this->_tree, this->_tree.min_node(this->_tree._node)));
		}

		const_iterator begin() const
		{
			if (this->_tree._node == NULL)
				return (const_iterator(_tree, NULL));
			return (const_iterator(this->_tree, this->_tree.min_node(this->_tree._node)));
		}

		iterator end()
		{
			if (this->_tree._node == NULL)
				return (iterator(_tree, NULL));
			return (iterator(this->_tree, this->_tree.max_node(this->_tree._node)));
		}

		const_iterator end() const
		{
			if (this->_tree._node == NULL)
				return (const_iterator(_tree, NULL));
			return (const_iterator(this->_tree, this->_tree.max_node(this->_tree._node)));
		}

	    reverse_iterator rbegin()
		{
			return (reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const
		{
			if (this->_tree._node == NULL)
				return (const_reverse_iterator(const_iterator(_tree, NULL)));
			return (const_reverse_iterator(const_iterator(this->_tree, this->_tree.min_node(this->_tree._node))));
		}

	    reverse_iterator rend()
		{

		}

		const_reverse_iterator rend() const
		{

		}

		bool empty() const
		{

		}

		size_type size() const
		{

		}

		size_type max_size() const
		{
			
		}

		mapped_type& operator[] (const key_type& k)
		{

		}

		pair<iterator,bool> insert (const value_type& val)
		{

		}

		iterator insert (iterator position, const value_type& val)
		{

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
	};


}