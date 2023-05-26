#ifndef _ERROR_HANDLING_H_
#define _ERROR_HANDLING_H_


#define HANDLE_ERROR(res)   \
    if ((res) != SUCCESS) { \
        fprintf(stderr, "[%s:%d]%s\n", __func__, __LINE__, GetError(res)); \
    }

typedef enum {
    SUCCESS,
    FAILURE,
    LIST_EMPTY,
    NULL_ARG,
    INVALID_SIZE,
    OUT_OF_MEMORY,
    INVALID_DATA,
    DATA_ALREADY_EXISTS,
    DATA_NOT_FOUND,
    LIST_IS_FULL,
} result;

char *GetError(result res);

#endif //_ERROR_HANDLING_H_
