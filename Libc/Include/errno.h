#ifndef ERRNO_H
#define ERRNO_H

extern "C" {

extern int errno;

#define EDOM 0x400
#define ERANGE 0x800

}
#endif // ERRNO_H
