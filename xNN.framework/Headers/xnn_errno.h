
#ifndef _AIENGINE_ERRNO_H_
#define _AIENGINE_ERRNO_H_

typedef enum {
    
    ENONE = 0,// no error
    
    EINIT_UNKNOWN                                   = -1000,
    EINIT_INVALID_LIB_VERSION                       = -1001,
    EINIT_MODEL_OPEN_FAILED                         = -1002,
    EINIT_MODEL_MMAP_FAILED                         = -1003,
    EINIT_MODEL_HEADER_CHECK_FAILED                 = -1004,
    EINIT_MODEL_SIZE_CHECK_FAILED                   = -1005,
    EINIT_MODEL_MALLOC_FAILED                       = -1006,
    EINIT_MODEL_HASH_CHECK_FAILED                   = -1007,
    EINIT_MODEL_VERSION_UNSUPPORTED                 = -1008,
    EINIT_MODEL_UNPACK_FAILED                       = -1009,
    EINIT_MODEL_FSTAT_FAILED                        = -1010,
    EINIT_INVALID_OP                                = -1011,
    EINIT_INVALID_PARAM                             = -1012,
    EINIT_UNEXPECTED_NULL                           = -1013,
    EINIT_BACKEND_FAIL                              = -1014,


    EFORWARD_UNKNOWN                                = -2001,
    EFORWARD_MALLOC_FAILED                          = -2002,
    EFORWARD_INVALID_DATA_TYPE                      = -2003,
    EFORWARD_INVALID_INPUT_NAME                     = -2004,
    EFORWARD_INVALID_SIZE                           = -2005,
    EFORWARD_UNEXPECTED_NULL                        = -2006,
    
    
    ERELEASE_UNKNOWN                                = -3001,
    ERELEASE_MULTIPLE_RELEASE                       = -3002,
    
    EMISC_UNKNOWN                                   = -4001
    
} XNN_ERROR;

typedef XNN_ERROR xnn_status_e;
#endif
