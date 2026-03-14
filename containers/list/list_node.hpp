#ifndef LIST_NODE_HPP

# define LIST_NODE_HPP

namespace rub
{
	template <typename T>
	struct	node
	{
		T				value;
		rub::node<T>	*next;
		rub::node<T>	*prev;
		explicit node(const T& val);
	};
}

template <typename T>
rub::node<T>::node(const T& val) : value(val), next(nullptr), prev(nullptr)
{}

#endif //LIST_NODE_HPP