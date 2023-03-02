#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d:%s: " M "\n",\
        __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, \
        ANSI_COLOR_RED "[ERROR]" ANSI_COLOR_RESET \
        "\t(%s:%d: %s errno: " \
        ANSI_COLOR_MAGENTA "%s" ANSI_COLOR_RESET ") " M "\n", \
        __FILE__, __LINE__, __FUNCTION__, clean_errno(), ##__VA_ARGS__)


#define log_warn(M, ...) fprintf(stderr, \
        ANSI_COLOR_YELLOW "[WARN]" ANSI_COLOR_RESET \
        "\t(%s:%d: %s errno: " \
        ANSI_COLOR_MAGENTA "%s" ANSI_COLOR_RESET ") " M "\n", \
        __FILE__, __LINE__, __FUNCTION__, clean_errno(), ##__VA_ARGS__)


#define log_info(M, ...) fprintf(stderr, \
        ANSI_COLOR_CYAN "[info]" ANSI_COLOR_RESET \
        "\t(%s:%d %s) " M "\n", \
        __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)


#define check(A, M, ...) if(!(A)) {\
    log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__);\
    errno=0; goto error; }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__);\
    errno=0; goto error; }

#endif
