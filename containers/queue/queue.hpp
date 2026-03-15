#ifndef QUEUE_HPP

# define QUEUE_HPP

# include <cstddef>
# include <initializer_list>
# include "../list/list_node.hpp"
# include "../list/list.hpp"

namespace rub
{
	template <typename T>
	class	queue : public rub::list<T>
	{
		public:
			/*---------queue ctor/dtor---------*/
			queue(void);
			queue(const T& val);
			queue(const queue<T>& other);
			queue(queue<T>&& other) noexcept;
			queue(const std::initializer_list<T>& lst);
			~queue(void) noexcept = default;

			/*-----queue operators-----*/
			rub::queue<T>&	operator=(const rub::queue<T>& other);
			rub::queue<T>&	operator=(rub::queue<T>&& other) noexcept;

			/*-----queue methods (element access)-----*/
			rub::node<T>		*front(void);
			const rub::node<T>	*front(void) const;
			rub::node<T>		*back(void);
			const rub::node<T>	*back(void) const;

			/*-----queue methods (capacity)-----*/
			bool				empty(void) const;
			std::size_t			size(void) const;

			/*-----queue methods (modifiers)-----*/
			void				pop(void);
			void				push(const T& val);
			void				swap(rub::queue<T>& other) noexcept;

			template <typename ...Args>
			void				emplace(Args&&... args);

	};
}

#include "./queue.tpp"

#endif //QUEUE_HPP