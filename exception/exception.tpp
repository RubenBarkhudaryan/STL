#ifndef EXCEPTION_TPP

# define EXCEPTION_TPP

# include <utility>
# include "./exception.hpp"

rub::exception::exception(const char *issue) : issue(issue)
{}

const char	*rub::exception::what() const noexcept
{
	return (this->issue);
}

#endif //EXCEPTION_TPP