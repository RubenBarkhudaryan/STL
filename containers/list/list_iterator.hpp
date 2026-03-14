#ifndef LIST_ITERATOR_HPP

# define LIST_ITERATOR_HPP

# include <cstddef>
# include <iterator>
# include "./list_node.hpp"

namespace rub
{
	template <typename T, typename U>
	class	list_iterator
	{
		
		private:
			rub::node<T>	*ptr;
			rub::node<T>	*const *tail_ref;

		public:

			/*-----iterator traits-----*/
			using value_type = T;
			using reference = U&;
			using pointer = U*;
			using difference_type = std::ptrdiff_t;
			using iterator_category = std::bidirectional_iterator_tag;

			/*-----list_iterator ctor/dtor-----*/
			list_iterator(void);
			explicit list_iterator(rub::node<T> *ptr);
			list_iterator(rub::node<T> *ptr, rub::node<T> *const *tail_ref);
			~list_iterator() = default;

			/*-----list_iterator operators-----*/
			reference			operator*(void) const noexcept;
			pointer				operator->(void) const noexcept;
			list_iterator&		operator++(void) noexcept;
			list_iterator		operator++(int) noexcept;
			list_iterator&		operator--(void) noexcept;
			list_iterator		operator--(int) noexcept;
			bool				operator==(const list_iterator& other) const noexcept;
			bool				operator!=(const list_iterator& other) const noexcept;

			/*-----list_iterator functions-----*/
			rub::node<T>*		base() noexcept;
			const rub::node<T>*	base() const noexcept;
	};
}

# include "./list_iterator.tpp"

#endif //LIST_ITERATOR_HPP