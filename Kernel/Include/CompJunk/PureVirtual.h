#ifndef PUREVIRT_HXX
#define PUREVIRT_HXX

// support for pure virtual functions in GCC
#ifdef __cplusplus
extern "C"
{
#endif

#if defined __GNUC__ || defined __GNU__
	void __cxa_pure_virtual() { ; /* do nothing */ }
#endif

#ifdef __cplusplus
}
#endif

#endif // PUREVIRT_HXX
