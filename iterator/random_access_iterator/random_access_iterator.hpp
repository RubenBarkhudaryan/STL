#ifndef RANDOM_ACCESS_ITERATOR_HPP

# define RANDOM_ACCESS_ITERATOR_HPP

# include <cstddef>
# include <iterator>
# include <type_traits>

namespace rub
{
	template <typename T>
	class	random_access_iterator
	{
		private:
			T	*ptr;

		public:
			/*-----iterator traits-----*/
			using value_type = T;
			using reference = T&;
			using pointer = T*;
			using const_reference = const T&;
			using const_pointer = const T*;
			using difference_type = std::ptrdiff_t;
			using iterator_category = std::random_access_iterator_tag;

			/*-----random_access_iterator ctor/dtor-----*/
			random_access_iterator(void);
			explicit random_access_iterator(T *ptr);
			template <typename U, typename = typename std::enable_if<std::is_convertible<U*, T*>::value>::type>
			random_access_iterator(const random_access_iterator<U>& other);
			~random_access_iterator() = default;

			/*-----random_access_iterator operators-----*/
			reference					operator*(void) noexcept;
			pointer						operator->(void) noexcept;
			const_reference				operator*(void) const noexcept;
			const_pointer				operator->(void) const noexcept;
			random_access_iterator&		operator++(void) noexcept;
			random_access_iterator		operator++(int) noexcept;
			random_access_iterator&		operator--(void) noexcept;
			random_access_iterator		operator--(int) noexcept;
			random_access_iterator		operator+(difference_type n) const noexcept;
			random_access_iterator		operator-(difference_type n) const noexcept;
			difference_type				operator-(const random_access_iterator& other) const noexcept;
			random_access_iterator&		operator+=(difference_type n) noexcept;
			random_access_iterator&		operator-=(difference_type n) noexcept;
			reference					operator[](difference_type n) noexcept;
			const_reference				operator[](difference_type n) const noexcept;
			bool						operator==(const random_access_iterator& other) const noexcept;
			bool						operator!=(const random_access_iterator& other) const noexcept;
			bool						operator<(const random_access_iterator& other) const noexcept;
			bool						operator<=(const random_access_iterator& other) const noexcept;
			bool						operator>(const random_access_iterator& other) const noexcept;
			bool						operator>=(const random_access_iterator& other) const noexcept;

			/*-----random_access_iterator methods-----*/
			pointer						base() const noexcept;
	};

	template <typename T>
	random_access_iterator<T>	operator+(typename random_access_iterator<T>::difference_type n,
		const random_access_iterator<T>& it) noexcept;
}

# include "./random_access_iterator.tpp"

#endif //RANDOM_ACCESS_ITERATOR_HPP
