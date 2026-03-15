#ifndef LIST_HPP

# define LIST_HPP

# include <cstddef>
# include <initializer_list>

# include "./list_node.hpp"
# include "./list_iterator.hpp"

namespace rub
{
	template <typename T>
	class	list
	{
		protected:
			rub::node<T>	*_head;
			rub::node<T>	*_tail;
			std::size_t		_size;

		public:
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

			/*---------list ctor/dtor---------*/
			list(void);
			list(const T& val);
			list(const rub::list<T>& other);
			list(rub::list<T>&& other) noexcept;
			list(const std::initializer_list<T>& lst);
			~list(void) noexcept;

			/*-----list operators-----*/
			rub::list<T>&			operator=(const rub::list<T>& other);
			rub::list<T>&			operator=(rub::list<T>&& other) noexcept;

			/*-----list member function-----*/
			void					assign(size_type count, const T& value);

			template <typename InputIt>
			void					assign(InputIt first, InputIt last);

			void					assign(const std::initializer_list<T>& lst);

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
			const_reverse_iterator	crbegin(void) const;
			const_reverse_iterator	crend(void) const;

			/*-----list methods (capacity)-----*/
			std::size_t				size() const;
			bool					empty() const;

			/*-----list methods (modifiers)-----*/
			void					clear(void);
			void					insert(rub::node<T> *target, const T& value);

			template <typename ...Args>
			iterator				emplace(const_iterator pos, Args&&... args);

			template <typename ...Args>
			void					emplace_back(Args&&... args);

			template <typename ...Args>
			void					emplace_front(Args&&... args);

			iterator				erase(const_iterator pos);
			iterator				erase(const_iterator first, const_iterator last);
			void					push_back(const T& value);
			void					pop_back(void);
			void					push_front(const T& value);
			void					pop_front(void);
			void					resize(size_type count);
			void					resize(size_type count, const value_type& value);
			void					swap(rub::list<T>& other);

			/*-----list methods (operations)-----*/
			template <typename Compare>
			void					merge(rub::list<T>& other, Compare cmp);
			
			template <typename Compare>
			void					merge(rub::list<T>&& other, Compare cmp) noexcept;
			
			void					merge(rub::list<T>& other);
			void					merge(rub::list<T>&& other) noexcept;

			void					reverse(void);
			void					remove(const T& value);

			template <typename UnaryPred>
			void					remove_if(UnaryPred p);

			void					unique();

			template <typename BinaryPred>
			void					unique(BinaryPred p);
	};
}

# include "./list.tpp"

#endif //LIST_HPP