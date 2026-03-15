#ifndef SET_TPP

# define SET_TPP

# include <iostream>
# include "./set.hpp"

template <typename T>
rub::set_node<T>::set_node(void) : value(T{}), left(nullptr), right(nullptr)
{}

template <typename T>
rub::set_node<T>::set_node(const T& val) : value(val), left(nullptr), right(nullptr)
{}

template <typename T>
bool	rub::set<T>::bst_insert(rub::set_node<T> *node, const T& val)
{
	if (val < node->value)
	{
		if (node->left)
			return (bst_insert(node->left, val));
		node->left = new rub::set_node<T>(val);
		++(this->_size);
		return (true);
	}
	if (val > node->value)
	{
		if (node->right)
			return (bst_insert(node->right, val));
		node->right = new rub::set_node<T>(val);
		++(this->_size);
		return (true);
	}
	return (false);
}

template <typename T>
bool	rub::set<T>::bst_contains(const rub::set_node<T> *node, const T& val) const
{
	if (!node)
		return (false);
	if (val < node->value)
		return (bst_contains(node->left, val));
	if (val > node->value)
		return (bst_contains(node->right, val));
	return (true);
}

template <typename T>
rub::set_node<T>*	rub::set<T>::min_node(rub::set_node<T> *node) const
{
	if (!node)
		return (nullptr);
	while (node->left)
		node = node->left;
	return (node);
}

template <typename T>
rub::set_node<T>*	rub::set<T>::bst_erase(rub::set_node<T> *node, const T& val, bool& erased)
{
	if (!node)
		return (nullptr);
	if (val < node->value)
	{
		node->left = bst_erase(node->left, val, erased);
		return (node);
	}
	if (val > node->value)
	{
		node->right = bst_erase(node->right, val, erased);
		return (node);
	}

	erased = true;
	if (!node->left && !node->right)
	{
		delete node;
		return (nullptr);
	}
	if (!node->left)
	{
		rub::set_node<T> *right = node->right;
		delete node;
		return (right);
	}
	if (!node->right)
	{
		rub::set_node<T> *left = node->left;
		delete node;
		return (left);
	}

	rub::set_node<T> *successor = min_node(node->right);
	node->value = successor->value;
	bool	unused = false;
	node->right = bst_erase(node->right, successor->value, unused);
	return (node);
}

template <typename T>
rub::set_node<T>*	rub::set<T>::clone_tree(const rub::set_node<T> *node)
{
	if (!node)
		return (nullptr);
	rub::set_node<T> *new_node = new rub::set_node<T>(node->value);
	new_node->left = clone_tree(node->left);
	new_node->right = clone_tree(node->right);
	return (new_node);
}

template <typename T>
rub::set<T>::set(void) : root(nullptr), _size(0)
{}

template <typename T>
rub::set<T>::set(const std::initializer_list<T>& list) : root(nullptr), _size(0)
{
	for (typename std::initializer_list<T>::const_iterator it = list.begin(); it != list.end(); ++it)
		insert(*it);
}

template <typename T>
rub::set<T>::set(const rub::set<T>& other) : root(nullptr), _size(other._size)
{
	this->root = clone_tree(other.root);
}

template <typename T>
rub::set<T>::set(rub::set<T>&& other) noexcept : root(other.root), _size(other._size)
{
	other.root = nullptr;
	other._size = 0;
}

template <typename T>
rub::set<T>&	rub::set<T>::operator=(const rub::set<T>& other)
{
	if (this != &other)
	{
		clear();
		this->root = clone_tree(other.root);
		this->_size = other._size;
	}
	return (*this);
}

template <typename T>
rub::set<T>&	rub::set<T>::operator=(rub::set<T>&& other) noexcept
{
	if (this != &other)
	{
		clear();
		this->root = other.root;
		this->_size = other._size;
		other.root = nullptr;
		other._size = 0;
	}
	return (*this);
}

template <typename T>
rub::set<T>::~set(void)
{
	clear();
}

template <typename T>
void	rub::set<T>::delete_tree(rub::set_node<T> *node)
{
	if (!node)
		return ;
	delete_tree(node->left);
	delete_tree(node->right);
	delete node;
}

template <typename T>
bool	rub::set<T>::insert(const T& val)
{
	if (!this->root)
	{
		this->root = new rub::set_node<T>(val);
		this->_size = 1;
		return (true);
	}
	return (bst_insert(this->root, val));
}

template <typename T>
bool	rub::set<T>::erase(const T& val)
{
	bool	erased = false;

	this->root = bst_erase(this->root, val, erased);
	if (erased)
		--(this->_size);
	return (erased);
}

template <typename T>
bool	rub::set<T>::contains(const T& val) const
{
	return (bst_contains(this->root, val));
}

template <typename T>
bool	rub::set<T>::empty(void) const
{
	return (this->_size == 0);
}

template <typename T>
std::size_t	rub::set<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
void	rub::set<T>::clear(void) noexcept
{
	delete_tree(this->root);
	this->root = nullptr;
	this->_size = 0;
}

#endif //SET_TPP
