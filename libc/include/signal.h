#ifndef SIGNAL_H
#define SIGNAL_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef int sig_atomic_t;

#define SIG_DFL 0x0
#define SIG_ERR 0x1
#define SIG_IGN 0x2

#define SIGABRT 0x3
#define SIGFPE 0x4
#define SIGILL 0x5
#define SIGINT 0x6
#define SIGSEGV 0x7
#define SIGTERM 0x8

void (*signal(int sig, void (*func)(int)))(int);
int raise(int sig);

#ifdef __cplusplus
}
#endif

#endif // SIGNAL_H
