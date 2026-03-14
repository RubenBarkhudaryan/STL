#ifndef LIST_TPP

# define LIST_TPP

# include <utility>
# include "./list.hpp"

/*-----list ctor/dtor-----*/
template <typename T>
rub::list<T>::list(void) : _head(nullptr), _tail(nullptr), _size(0)
{}

template <typename T>
rub::list<T>::list(const T& val) : _head(new rub::node<T>(val)), _tail(_head), _size(1)
{}

template <typename T>
rub::list<T>::list(const rub::list<T>& other) : _head(nullptr), _tail(nullptr), _size(0)
{
	for (const auto& it : other)
		this->push_back(it);
}

template <typename T>
rub::list<T>::list(rub::list<T>&& other) noexcept : _head(other._head), _tail(other._tail), _size(other._size)
{
	other._head = nullptr;
	other._tail = nullptr;
	other._size = 0;
}

template <typename T>
rub::list<T>::list(const std::initializer_list<T>& lst) : _head(nullptr), _tail(nullptr), _size(0)
{
	for (const auto& it : lst)
		this->push_back(it);
}

template <typename T>
rub::list<T>::~list(void) noexcept
{
	rub::node<T>	*temp;
	rub::node<T>	*nxt;

	temp = this->_head;
	while (temp)
	{
		nxt = temp->next;
		delete temp;
		temp = nxt;
	}
}

/*-----list operators-----*/
template <typename T>
rub::list<T>&	rub::list<T>::operator=(const rub::list<T>& other)
{
	if (this != &other)
	{
		this->clear();

		for (const auto& elem : other)
			this->push_back(elem);
	}
	return (*this);
}

template <typename T>
rub::list<T>&	rub::list<T>::operator=(rub::list<T>&& other) noexcept
{
	if (this != &other)
	{
		this->clear();

		this->_head = other._head;
		this->_tail= other._tail;
		this->_size = other._size;

		other._head = nullptr;
		other._tail = nullptr;
		other._size = 0;
	}
	return (*this);
}

/*-----list member function-----*/
template <typename T>
void	rub::list<T>::assign(typename rub::list<T>::size_type count, const T& value)
{
	rub::list<T>	temp;

	while (count--)
		temp.push_back(value);
	this->swap(temp);
}

template <typename T>
template <typename InputIt>
void	rub::list<T>::assign(InputIt first, InputIt last)
{
	rub::list<T>	temp;

	for (InputIt it = first; it != last; ++it)
		temp.push_back(*it);

	this->swap(temp);
}

template <typename T>
void	rub::list<T>::assign(const std::initializer_list<T>& lst)
{
	rub::list<T>	temp;

	for (const auto& elem : lst)
		temp.push_back(elem);

	this->swap(temp);
}

/*-----list methods (element access)-----*/
template <typename T>
rub::node<T>	*rub::list<T>::front(void)
{
	return (this->_head);
}

template <typename T>
const rub::node<T>	*rub::list<T>::front(void) const
{
	return (this->_head);
}

template <typename T>
rub::node<T>	*rub::list<T>::back(void)
{
	return (this->_tail);
}

template <typename T>
const rub::node<T>	*rub::list<T>::back(void) const
{
	return (this->_tail);
}

/*-----list methods (iterators)-----*/
template <typename T>
rub::list_iterator<T, T>	rub::list<T>::begin(void)
{
	return (rub::list_iterator<T, T>(this->_head, &(this->_tail)));
}

template <typename T>
rub::list_iterator<T, T>	rub::list<T>::end(void)
{
	return (rub::list_iterator<T, T>(nullptr, &(this->_tail)));
}

template <typename T>
rub::list_iterator<T, const T>	rub::list<T>::cbegin(void) const
{
	return (rub::list_iterator<T, const T>(this->_head, &(this->_tail)));
}

template <typename T>
rub::list_iterator<T, const T>	rub::list<T>::cend(void) const
{
	return (rub::list_iterator<T, const T>(nullptr, &(this->_tail)));
}

template <typename T>
typename rub::list<T>::reverse_iterator	rub::list<T>::rbegin(void)
{
	return (reverse_iterator(this->end()));
}

template <typename T>
typename rub::list<T>::reverse_iterator	rub::list<T>::rend(void)
{
	return (reverse_iterator(this->begin()));
}

template <typename T>
typename rub::list<T>::const_reverse_iterator	rub::list<T>::crbegin(void) const
{
	return (const_reverse_iterator(this->cend()));
}

template <typename T>
typename rub::list<T>::const_reverse_iterator	rub::list<T>::crend(void) const
{
	return (const_reverse_iterator(this->cbegin()));
}

/*-----list methods (capacity)-----*/
template <typename T>
std::size_t	rub::list<T>::size() const
{
	return (this->_size);
}

template <typename T>
bool	rub::list<T>::empty() const
{
	return (this->_head == nullptr);
}

/*-----list methods (modifiers)-----*/
template <typename T>
void	rub::list<T>::clear(void)
{
	while (this->_head)
		this->pop_back();
}

template <typename T>
void	rub::list<T>::insert(node<T> *target, const T& value)
{
	rub::node<T>	*new_node;
	if (!target)
		return ;
	new_node = new rub::node<T>(value);
	new_node->next = target->next;
	new_node->prev = target;
	if (new_node->next)
		new_node->next->prev = new_node;
	else
		this->_tail = new_node;
	target->next = new_node;
	++(this->_size);
}

template <typename T>
template <typename ...Args>
typename rub::list<T>::iterator	rub::list<T>::emplace(rub::list<T>::const_iterator pos, Args&&... args)
{
	T	value(std::forward<Args>(args)...);

	rub::node<T>	*new_node = new rub::node<T>(value);

	if (this->empty())
	{
		this->_head = new_node;
		this->_tail = new_node;
		++(this->_size);
		return (typename rub::list<T>::iterator(new_node, &this->_tail));
	}

	if (pos == this->cbegin())
	{
		new_node->next = this->_head;
		this->_head->prev = new_node;
		this->_head = new_node;
		++(this->_size);
		return (typename rub::list<T>::iterator(new_node, &this->_tail));
	}

	if (pos == this->cend())
	{
		new_node->prev = this->_tail;
		this->_tail->next = new_node;
		this->_tail = new_node;
		++(this->_size);
		return (typename rub::list<T>::iterator(new_node, &this->_tail));
	}

	rub::node<T>	*curr = (rub::node<T> *)pos.base();
	rub::node<T>	*prev = curr->prev;

	new_node->next = curr;
	new_node->prev = prev;
	prev->next = new_node;
	curr->prev = new_node;

	++(this->_size);
	return (typename rub::list<T>::iterator(new_node, &this->_tail));
}

template <typename T>
template <typename ...Args>
void	rub::list<T>::emplace_back(Args&&... args)
{
	this->emplace(this->cend(), std::forward<Args>(args)...);
}

template <typename T>
template <typename ...Args>
void	rub::list<T>::emplace_front(Args&&... args)
{
	this->emplace(this->cbegin(), std::forward<Args>(args)...);
}

template <typename T>
typename rub::list<T>::iterator	rub::list<T>::erase(const_iterator pos)
{
	if (this->empty() || pos == this->cend())
		return (this->end());

	rub::node<T>	*curr = const_cast<rub::node<T>*>(pos.base());
	rub::node<T>	*next = curr->next;
	rub::node<T>	*prev = curr->prev;

	if (curr == this->_head)
		this->_head = next;
	else
		prev->next = next;

	if (curr == this->_tail)
		this->_tail = prev;
	else
		next->prev = prev;

	delete curr;
	--(this->_size);

	if (!this->_head)
		return (this->end());

	return (typename rub::list<T>::iterator(next, &(this->_tail)));
}

template <typename T>
typename rub::list<T>::iterator	rub::list<T>::erase(const_iterator first, const_iterator last)
{
	rub::node<T>	*start = const_cast<rub::node<T> *>(first.base());
	rub::node<T>	*end = const_cast<rub::node<T> *>(last.base());

	if (first == last)
		return typename rub::list<T>::iterator(end, &(this->_tail));

	while (start != end)
	{
		typename rub::list<T>::iterator	it = this->erase(rub::list<T>::const_iterator(start, &(this->_tail)));
		start = it.base();
	}
	return (typename rub::list<T>::iterator(start, &(this->_tail)));
}

template <typename T>
void	rub::list<T>::push_back(const T& value)
{
	rub::node<T>	*new_node;

	new_node = new rub::node<T>(value);
	new_node->next = nullptr;
	new_node->prev = nullptr;
	if (!this->_head)
	{
		this->_head = new_node;
		this->_tail = new_node;
	}
	else
	{
		this->_tail->next = new_node;
		new_node->prev = this->_tail;
		this->_tail = this->_tail->next;
	}
	++(this->_size);
}

template <typename T>
void	rub::list<T>::pop_back(void)
{
	rub::node<T>	*old_tail;

	if (!this->_head)
		return ;
	if (this->_head == this->_tail)
	{
		delete this->_head;
		this->_head = nullptr;
		this->_tail = nullptr;
		this->_size = 0;
		return ;
	}
	old_tail = this->_tail;
	this->_tail = this->_tail->prev;
	this->_tail->next = nullptr;
	delete old_tail;
	--(this->_size);
}

template <typename T>
void	rub::list<T>::push_front(const T& value)
{
	rub::node<T>	*new_node;

	new_node = new rub::node<T>(value);
	new_node->next = nullptr;
	new_node->prev = nullptr;
	if (!this->_head)
	{
		this->_head = new_node;
		this->_tail = new_node;
	}
	else
	{
		new_node->next = this->_head;
		this->_head->prev = new_node;
		this->_head = new_node;
	}
	++(this->_size);
}

template <typename T>
void	rub::list<T>::pop_front(void)
{
	rub::node<T>	*old_head;

	if (!this->_head)
		return ;
	if (this->_head == this->_tail)
	{
		delete this->_head;
		this->_head = nullptr;
		this->_tail = nullptr;
		this->_size = 0;
		return ;
	}
	old_head = this->_head;
	this->_head = this->_head->next;
	this->_head->prev = nullptr;
	delete old_head;
	--(this->_size);
}

template <typename T>
void	rub::list<T>::resize(typename rub::list<T>::size_type count)
{
	if (count == this->_size)
		return ;
	if (count == 0)
		this->clear();
	else if (count > this->_size)
	{
		while (this->_size < count)
			this->push_back(T{});
	}
	else
	{
		while (this->_size > count)
			this->pop_back();
	}
}

template <typename T>
void	rub::list<T>::resize(typename rub::list<T>::size_type count, const typename rub::list<T>::value_type& value)
{
	if (count == this->_size)
		return ;
	if (count > this->_size)
	{
		while (this->_size < count)
			this->push_back(value);
	}
	else
		this->resize(count);
}

template <typename T>
void	rub::list<T>::swap(rub::list<T>& other)
{
	rub::node<T>			*temp_head = this->_head;
	rub::node<T>			*temp_tail = this->_tail;
	rub::list<T>::size_type	temp_size = this->_size;

	this->_head = other._head;
	this->_tail = other._tail;
	this->_size = other._size;

	other._head = temp_head;
	other._tail = temp_tail;
	other._size = temp_size;
}

/*-----list methods (operations)-----*/
template <typename T>
void	rub::list<T>::reverse(void)
{
	rub::node<T>	*curr = this->_head;
	rub::node<T>	*prev = nullptr;

	while (curr)
	{
		prev = curr->prev;
		curr->prev = curr->next;
		curr->next = prev;
		curr = curr->prev;
	}

	prev = this->_head;
	this->_head = this->_tail;
	this->_tail = prev;
}

#endif //LIST_TPP