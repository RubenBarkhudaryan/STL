#ifndef LIST_HPP

# define LIST_HPP

# include <cstddef>
# include <utility>
# include <initializer_list>

# include "./list_node.hpp"
# include "./list_iterator.hpp"

namespace rub
{
	template <typename T>
	class	list
	{

		using value_type = T;
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = value_type*;
		using const_pointer = const value_type*;
		using iterator = rub::list_iterator<T, T>;
		using const_iterator = rub::list_iterator<T, const T>;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

		private:
			rub::node<T>	*_head;
			rub::node<T>	*_tail;
			std::size_t		_size;

		public:
			/*---------list ctor/dtor---------*/
			list(void);
			list(const T& val);
			list(std::initializer_list<T>& lst);
			list(const list<T> &) = delete;
			list<T>& operator=(const list<T> &) = delete;
			~list(void) noexcept;

			/*---------list methods (modifiers)---------*/
			void					clear(void);
			void					insert(rub::node<T> *target, const T& value);

			template <typename ...Args>
			iterator				emplace(const_iterator pos, Args&&... args);

			iterator				erase(const_iterator pos);
			iterator				erase(const_iterator first, const_iterator last);
			void					push_back(const T& value);
			void					pop_back(void);
			void					push_front(const T& value);
			void					pop_front(void);

			/*-----list methods (element access)-----*/
			rub::node<T>			*front(void);
			rub::node<T>			*back(void);
			const rub::node<T>		*back(void) const;
			const rub::node<T>		*front(void) const;

			/*-----list methods (iterators)-----*/
			iterator				begin(void);
			iterator				end(void);
			const_iterator			cbegin(void) const;
			const_iterator			cend(void) const;
			reverse_iterator		rbegin(void);
			reverse_iterator		rend(void);
			const_reverse_iterator	rend(void) const;
			const_reverse_iterator	rbegin(void) const;
			const_reverse_iterator	crbegin(void) const;
			const_reverse_iterator	crend(void) const;

			/*-----list methods (capacity)-----*/
			std::size_t				size() const;
			bool					empty() const;
	};
}

# include "./list.tpp"

#endif //LIST_HPP