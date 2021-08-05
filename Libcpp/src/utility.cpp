#include "utility"

template<typename Type>
void std::swap(Type &lhs, Type &rhs)
{
	const auto copyoflhs = lhs;
	lhs = rhs;
	rhs = copyoflhs;
}

