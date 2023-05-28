
#include "error_handling.h"

char *GetError(result res){
    switch (res){
        case SUCCESS:
            return "Success";
        case FAILURE:
            return "Failure";
        case NULL_ARG:
            return "Null argument";
        case INVALID_SIZE:
            return "Invalid size";
        case OUT_OF_MEMORY:
            return "Out of memory";
        case INVALID_DATA:
            return "Invalid data";
        case DATA_ALREADY_EXISTS:
            return "Data already exists";
        case LIST_IS_FULL:
            return "List is full";
        default:
            return "Unknown error";
    }
}
