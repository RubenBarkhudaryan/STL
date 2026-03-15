#ifndef RANDOM_ACCESS_ITERATOR_TPP

# define RANDOM_ACCESS_ITERATOR_TPP

# include "./random_access_iterator.hpp"

template <typename T>
rub::random_access_iterator<T>::random_access_iterator(void) : ptr(nullptr)
{}

template <typename T>
rub::random_access_iterator<T>::random_access_iterator(T *ptr) : ptr(ptr)
{}

template <typename T>
template <typename U, typename>
rub::random_access_iterator<T>::random_access_iterator(const rub::random_access_iterator<U>& other)
	: ptr(other.base())
{}

template <typename T>
typename rub::random_access_iterator<T>::reference	rub::random_access_iterator<T>::operator*(void) noexcept
{
	return (*(this->ptr));
}

template <typename T>
typename rub::random_access_iterator<T>::pointer	rub::random_access_iterator<T>::operator->(void) noexcept
{
	return (this->ptr);
}

template <typename T>
typename rub::random_access_iterator<T>::const_reference	rub::random_access_iterator<T>::operator*(void) const noexcept
{
	return (*(this->ptr));
}

template <typename T>
typename rub::random_access_iterator<T>::const_pointer	rub::random_access_iterator<T>::operator->(void) const noexcept
{
	return (this->ptr);
}

template <typename T>
typename rub::random_access_iterator<T>&	rub::random_access_iterator<T>::operator++(void) noexcept
{
	++(this->ptr);
	return (*this);
}

template <typename T>
typename rub::random_access_iterator<T>	rub::random_access_iterator<T>::operator++(int) noexcept
{
	rub::random_access_iterator<T>	temp(*this);

	++(this->ptr);
	return (temp);
}

template <typename T>
typename rub::random_access_iterator<T>&	rub::random_access_iterator<T>::operator--(void) noexcept
{
	--(this->ptr);
	return (*this);
}

template <typename T>
typename rub::random_access_iterator<T>	rub::random_access_iterator<T>::operator--(int) noexcept
{
	rub::random_access_iterator<T>	temp(*this);

	--(this->ptr);
	return (temp);
}

template <typename T>
typename rub::random_access_iterator<T>	rub::random_access_iterator<T>::operator+(difference_type n) const noexcept
{
	return (rub::random_access_iterator<T>(this->ptr + n));
}

template <typename T>
typename rub::random_access_iterator<T>	rub::random_access_iterator<T>::operator-(difference_type n) const noexcept
{
	return (rub::random_access_iterator<T>(this->ptr - n));
}

template <typename T>
typename rub::random_access_iterator<T>::difference_type	rub::random_access_iterator<T>::operator-(const random_access_iterator& other) const noexcept
{
	return (this->ptr - other.ptr);
}

template <typename T>
typename rub::random_access_iterator<T>&	rub::random_access_iterator<T>::operator+=(difference_type n) noexcept
{
	this->ptr += n;
	return (*this);
}

template <typename T>
typename rub::random_access_iterator<T>&	rub::random_access_iterator<T>::operator-=(difference_type n) noexcept
{
	this->ptr -= n;
	return (*this);
}

template <typename T>
typename rub::random_access_iterator<T>::reference	rub::random_access_iterator<T>::operator[](difference_type n) noexcept
{
	return (*(this->ptr + n));
}

template <typename T>
typename rub::random_access_iterator<T>::const_reference	rub::random_access_iterator<T>::operator[](difference_type n) const noexcept
{
	return (*(this->ptr + n));
}

template <typename T>
bool	rub::random_access_iterator<T>::operator==(const random_access_iterator& other) const noexcept
{
	return (this->ptr == other.ptr);
}

template <typename T>
bool	rub::random_access_iterator<T>::operator!=(const random_access_iterator& other) const noexcept
{
	return (this->ptr != other.ptr);
}

template <typename T>
bool	rub::random_access_iterator<T>::operator<(const random_access_iterator& other) const noexcept
{
	return (this->ptr < other.ptr);
}

template <typename T>
bool	rub::random_access_iterator<T>::operator<=(const random_access_iterator& other) const noexcept
{
	return (this->ptr <= other.ptr);
}

template <typename T>
bool	rub::random_access_iterator<T>::operator>(const random_access_iterator& other) const noexcept
{
	return (this->ptr > other.ptr);
}

template <typename T>
bool	rub::random_access_iterator<T>::operator>=(const random_access_iterator& other) const noexcept
{
	return (this->ptr >= other.ptr);
}

template <typename T>
typename rub::random_access_iterator<T>::pointer	rub::random_access_iterator<T>::base() const noexcept
{
	return (this->ptr);
}

template <typename T>
rub::random_access_iterator<T>	rub::operator+(typename rub::random_access_iterator<T>::difference_type n,
	const rub::random_access_iterator<T>& it) noexcept
{
	return (it + n);
}

#endif //RANDOM_ACCESS_ITERATOR_TPP
