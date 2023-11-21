#ifndef MYASSERT_H
#define MYASSERT_H

#include <assert.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"

enum CODES_OF_ERRORS {
    BAD_POINTER_PASSED_IN_FUNC   = 1,
    BAD_CALLOC                   = 2,
    OPEN_FILE                    = 3,
    CLOSE_FILE                   = 4,
};

#define DEBUG_MYASSERT 1

#ifdef DEBUG_MYASSERT
#define MYASSERT(check, error_code, ending)                                                                         \
        do                                                                                                          \
        {                                                                                                           \
            if (!(check))                                                                                           \
            {                                                                                                       \
                printf(MAGENTA ">>>>> Error in code! Error code: %s <<<<<\n", #error_code);                         \
                printf("In File: %s, In Line: %d, In Function: %s\n", __FILE__, __LINE__,__PRETTY_FUNCTION__);      \
                printf("In this condition:\t\"%s\"\n\n" RESET, #check);                                             \
                ending;                                                                                             \
            }                                                                                                       \
        }                                                                                                           \
        while(0);
#else   
#define MYASSERT(check, error_code, ending)
#endif

#endif