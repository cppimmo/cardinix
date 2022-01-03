#ifndef __KERNEL_H__
#define __KERNEL_H__

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0])))
#define FIELD_SIZEOF(t, f) (sizeof(((t*)0)->f))

#endif
