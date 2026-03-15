#ifndef STACK_HPP

# define STACK_HPP

# include <cstddef>
# include <initializer_list>
# include "../list/list_node.hpp"
# include "../list/list.hpp"

namespace rub
{
	template <typename T>
	class	stack : public rub::list<T>
	{
		public:
			/*---------stack ctor/dtor---------*/
			stack(void);
			stack(const T& val);
			stack(const stack<T>& other);
			stack(stack<T>&& other) noexcept;
			stack(const std::initializer_list<T>& lst);
			~stack(void) noexcept = default;

			/*-----stack operators-----*/
			rub::stack<T>&	operator=(const rub::stack<T>& other);
			rub::stack<T>&	operator=(rub::stack<T>&& other) noexcept;

			/*-----stack methods (element access)-----*/
			rub::node<T>		*top(void);
			const rub::node<T>	*top(void) const;

			/*-----stack methods (capacity)-----*/
			bool				empty(void) const;
			std::size_t			size(void) const;

			/*-----stack methods (modifiers)-----*/
			void				pop(void);
			void				push(const T& val);
			void				swap(rub::stack<T>& other) noexcept;

			template <typename ...Args>
			void				emplace(Args&&... args);

	};
}

#include "./stack.tpp"

#endif //STACK_HPP