.section .init
    /* gcc will place crtend.o's .init section here */
    popl %ebp
    ret

.section .fini
    /* gcc will place crtend.o's .fini section here */
    popl %ebp
    ret

