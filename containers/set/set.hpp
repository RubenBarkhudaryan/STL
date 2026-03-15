#ifndef SET_HPP

# define SET_HPP

# include <cstddef>
# include <initializer_list>

namespace rub
{
	enum	print_modes
	{
		INORDER,
		PREORDER,
		POSTORDER
	};

	template <typename T>
	struct	set_node
	{
		T				value;
		rub::set_node<T>	*left;
		rub::set_node<T>	*right;

		set_node(void);
		set_node(const T& val);
		~set_node(void) = default;
	};

	template <typename T>
	class	set
	{
		private:
			rub::set_node<T>	*root;
			std::size_t			_size;

			bool					bst_insert(rub::set_node<T> *node, const T& val);
			bool					bst_contains(const rub::set_node<T> *node, const T& val) const;
			rub::set_node<T>*		min_node(rub::set_node<T> *node) const;
			rub::set_node<T>*		bst_erase(rub::set_node<T> *node, const T& val, bool& erased);
			rub::set_node<T>*		clone_tree(const rub::set_node<T> *node);
			void					delete_tree(rub::set_node<T> *node);

		public:
			/*---------set ctor/dtor---------*/
			set(void);
			set(const std::initializer_list<T>& list);
			set(const rub::set<T>& other);
			set(rub::set<T>&& other) noexcept;
			~set(void);

			/*---------set operators---------*/
			rub::set<T>&	operator=(const rub::set<T>& other);
			rub::set<T>&	operator=(rub::set<T>&& other) noexcept;

			/*---------set methods---------*/
			bool			insert(const T& val);
			bool			erase(const T& val);
			bool			contains(const T& val) const;
			bool			empty(void) const;
			std::size_t		size(void) const;
			void			clear(void) noexcept;
	};
}

# include "./set.tpp"

#endif //SET_HPP
