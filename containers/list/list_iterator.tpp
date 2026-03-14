#ifndef LIST_ITERATOR_TPP

# define LIST_ITERATOR_TPP

# include "./list_iterator.hpp"

template <typename T, typename U>
rub::list_iterator<T, U>::list_iterator(void) : ptr(nullptr), tail_ref(nullptr)
{}

template <typename T, typename U>
rub::list_iterator<T, U>::list_iterator(rub::node<T> *ptr) : ptr(ptr), tail_ref(nullptr)
{}

template <typename T, typename U>
rub::list_iterator<T, U>::list_iterator(rub::node<T> *ptr, rub::node<T> *const *tail_ref)
	: ptr(ptr), tail_ref(tail_ref)
{}

template <typename T, typename U>
U&	rub::list_iterator<T, U>::operator*(void) const noexcept
{
	return (this->ptr->value);
}

template <typename T, typename U>
U*	rub::list_iterator<T, U>::operator->(void) const noexcept
{
	return &(this->ptr->value);
}

template <typename T, typename U>
typename rub::list_iterator<T, U>&	rub::list_iterator<T, U>::operator++(void) noexcept
{
	this->ptr = this->ptr->next;
	return (*this);
}

template <typename T, typename U>
typename rub::list_iterator<T, U>	rub::list_iterator<T, U>::operator++(int) noexcept
{
	rub::list_iterator<T, U>	temp(*this);

	this->ptr = this->ptr->next;
	return (temp);
}

template <typename T, typename U>
typename rub::list_iterator<T, U>&	rub::list_iterator<T, U>::operator--(void) noexcept
{
	if (this->ptr)
		this->ptr = this->ptr->prev;
	else if (this->tail_ref)
		this->ptr = *(this->tail_ref);
	return (*this);
}

template <typename T, typename U>
typename rub::list_iterator<T, U>	rub::list_iterator<T, U>::operator--(int) noexcept
{
	rub::list_iterator<T, U>	temp(*this);

	if (this->ptr)
		this->ptr = this->ptr->prev;
	else if (this->tail_ref)
		this->ptr = *(this->tail_ref);
	return (temp);
}

template <typename T, typename U>
bool	rub::list_iterator<T, U>::operator==(const rub::list_iterator<T, U>& other) const noexcept
{
	return (this->ptr == other.ptr);
}

template <typename T, typename U>
bool	rub::list_iterator<T, U>::operator!=(const rub::list_iterator<T, U>& other) const noexcept
{
	return (this->ptr != other.ptr);
}

template <typename T, typename U>
rub::node<T>*	rub::list_iterator<T, U>::base() noexcept
{
	return (this->ptr);
}

template <typename T, typename U>
const rub::node<T>*	rub::list_iterator<T, U>::base() const noexcept
{
	return (this->ptr);
}

#endif //LIST_ITERATOR_TPP