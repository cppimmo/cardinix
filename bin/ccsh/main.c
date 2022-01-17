#include <stdlib.h>
#include <stdio.h>

int handle_args(int argc, char *argv[]);
void ccsh_exit(void);
void ccsh_loop(void);
char *ccsh_readline(void);
char **ccsh_argline(char *line);

int
main(int argc, char *argv[])
{
    atexit(ccsh_exit);

    /* Load configuration. */

    /* 

    /* Interactive shell. */
    ccsh_loop();

    /* Shutdown */

    return EXIT_SUCCESS;
}

int
handle_args(int argc, char *argv[])
{

    return 0;
}

void
ccsh_exit(void)
{ /* atexit routine. */

    return;
}

void
ccsh_loop(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = ccsh_read_line();
        args = ccsh_split_line(line);
        status = ccsh_execute(args);

        free(line);
        free(args);
    } while (status);
    return;
}

/* TODO: Seperate routines for buffer handling. */
#define CCSH_READLINE_MAXCHAR
char *
ccsh_readline(void)
{
    int c; /* Current character. */
    int buffer_size = CCSH_READLINE_MAXCHAR; /* Current buffer size */
    int currpos; /* Current buffer position */
    char *buffer; /* Character buffer. */
    
    currpos = 0;
    buffer = malloc(sizeof(char) * buffer_size);
    if (buffer == NULL) {
        (void)ccsh_log(CCSH_LOG_ERROR, "memory failure");
        ccsh_panic();
    }

    for (;;) {
        /* Read the character */
        c = getchar();

        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        }
        else {
            buffer[currpos] = c;
        }
        currpos += 1;

        /* TODO: Make this a separate function. */
        if (currpos >= buffer_size) {
            buffer_size += CCSH_READLINE_MAXCHAR;
            buffer = realloc(buffer, buffer_size);
            if (buffer == NULL) {
                (void)ccsh_log(CCSH_LOG_ERROR, "");
                ccsh_panic(); /* Exit. */
            }
        }
    }
    return NULL;
}
