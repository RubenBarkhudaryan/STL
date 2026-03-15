#ifndef STACK_TPP

# define STACK_TPP

# include <utility>
# include "./stack.hpp"

/*-----stack ctor/dtor-----*/
template <typename T>
rub::stack<T>::stack(void) : rub::list<T>()
{}

template <typename T>
rub::stack<T>::stack(const T& val) : rub::list<T>(val)
{}

template <typename T>
rub::stack<T>::stack(const stack<T>& other) : rub::list<T>(other)
{}

template <typename T>
rub::stack<T>::stack(stack<T>&& other) noexcept : rub::list<T>(std::move(other))
{}

template <typename T>
rub::stack<T>::stack(const std::initializer_list<T>& lst) : rub::list<T>(lst)
{}

/*-----stack operators-----*/
template <typename T>
rub::stack<T>&	rub::stack<T>::operator=(const rub::stack<T>& other)
{
	if (this != &other)
		rub::list<T>::operator=(other);
	return (*this);
}

template <typename T>
rub::stack<T>&	rub::stack<T>::operator=(rub::stack<T>&& other) noexcept
{
	if (this != &other)
		rub::list<T>::operator=(std::move(other));
	return (*this);
}

/*-----stack methods (element access)-----*/
template <typename T>
rub::node<T>	*rub::stack<T>::top(void)
{
	return (rub::list<T>::back());
}

template <typename T>
const rub::node<T>	*rub::stack<T>::top(void) const
{
	return (rub::list<T>::back());
}

/*-----stack methods (capacity)-----*/
template <typename T>
bool	rub::stack<T>::empty(void) const
{
	return (rub::list<T>::empty());
}

template <typename T>
std::size_t	rub::stack<T>::size(void) const
{
	return (rub::list<T>::size());
}

/*-----stack methods (modifiers)-----*/
template <typename T>
void	rub::stack<T>::pop(void)
{
	rub::list<T>::pop_back();
}

template <typename T>
void	rub::stack<T>::push(const T& val)
{
	rub::list<T>::push_back(val);
}

template <typename T>
template <typename ...Args>
void	rub::stack<T>::emplace(Args&& ...args)
{
	rub::list<T>::emplace_back(std::forward<Args>(args)...);
}

template <typename T>
void	rub::stack<T>::swap(rub::stack<T>& other) noexcept
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

#endif //STACK_TPP