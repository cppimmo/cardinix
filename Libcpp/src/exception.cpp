#include "exception"

static std::terminate_handler pHandler;
static int excepts_not_caught = 0;

/*std::terminate_handler std::get_terminate() noexcept
{
	return ;
}*/

/*std::terminate_handler std::set_terminate(
	terminate_handler pHandler) noexcept
{
	auto pCopy = ::pHandler;
	
	return ;
}*/

[[noreturn]] void std::terminate() noexcept
{

}

int std::uncaught_exceptions() noexcept
{
	return ::excepts_not_caught;
}

/*std::exception_ptr std::current_exception() noexcept
{

}*/

/*[[noreturn]] void std::rethrow_exception(std::exception_ptr pException)
{

}*/

/*template <class E>
std::exception_ptr std::make_exception_ptr(E e) noexcept
{

}*/

template <class T>
[[noreturn]] void std::throw_with_nested(T &&t)
{

}

template <class E>
void std::rethrow_if_nested(const E &e)
{

}

const char *std::exception::what() const noexcept
{
	return "std::exception";
}

const char *std::bad_exception::what() const noexcept
{
	return "std::bad_exception";
}

[[noreturn]] void std::nested_exception::rethrow_nested() const
{

}

/*std::exception_ptr std::nested_ptr() const noexcept
{

}*/

