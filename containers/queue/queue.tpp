#ifndef QUEUE_TPP

# define QUEUE_TPP

# include <utility>
# include "./queue.hpp"

/*-----queue ctor/dtor-----*/
template <typename T>
rub::queue<T>::queue(void) : rub::list<T>()
{}

template <typename T>
rub::queue<T>::queue(const T& val) : rub::list<T>(val)
{}

template <typename T>
rub::queue<T>::queue(const queue<T>& other) : rub::list<T>(other)
{}

template <typename T>
rub::queue<T>::queue(queue<T>&& other) noexcept : rub::list<T>(std::move(other))
{}

template <typename T>
rub::queue<T>::queue(const std::initializer_list<T>& lst) : rub::list<T>(lst)
{}

/*-----queue operators-----*/
template <typename T>
rub::queue<T>&	rub::queue<T>::operator=(const rub::queue<T>& other)
{
	if (this != &other)
		rub::list<T>::operator=(other);
	return (*this);
}

template <typename T>
rub::queue<T>&	rub::queue<T>::operator=(rub::queue<T>&& other) noexcept
{
	if (this != &other)
		rub::list<T>::operator=(std::move(other));
	return (*this);
}

/*-----queue methods (element access)-----*/
template <typename T>
rub::node<T>	*rub::queue<T>::front(void)
{
	return (rub::list<T>::front());
}

template <typename T>
const rub::node<T>	*rub::queue<T>::front(void) const
{
	return (rub::list<T>::front());
}

template <typename T>
rub::node<T>	*rub::queue<T>::back(void)
{
	return (rub::list<T>::back());
}

template <typename T>
const rub::node<T>	*rub::queue<T>::back(void) const
{
	return (rub::list<T>::back());
}

/*-----queue methods (capacity)-----*/
template <typename T>
bool	rub::queue<T>::empty(void) const
{
	return (rub::list<T>::empty());
}

template <typename T>
std::size_t	rub::queue<T>::size(void) const
{
	return (rub::list<T>::size());
}

/*-----queue methods (modifiers)-----*/
template <typename T>
void	rub::queue<T>::pop(void)
{
	rub::list<T>::pop_front();
}

template <typename T>
void	rub::queue<T>::push(const T& val)
{
	rub::list<T>::push_back(val);
}

template <typename T>
template <typename ...Args>
void	rub::queue<T>::emplace(Args&& ...args)
{
	rub::list<T>::emplace_back(std::forward<Args>(args)...);
}

template <typename T>
void	rub::queue<T>::swap(rub::queue<T>& other) noexcept
{
	rub::node<T>						*temp_head = this->_head;
	rub::node<T>						*temp_tail = this->_tail;
	typename rub::list<T>::size_type	temp_size = this->_size;

	this->_head = other._head;
	this->_tail = other._tail;
	this->_size = other._size;

	other._head = temp_head;
	other._tail = temp_tail;
	other._size = temp_size;
}

#endif //QUEUE_TPP