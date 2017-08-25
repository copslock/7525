#include <stdio.h>

#include "common/mgr_type.h"

unsigned char mgrErrorString[EXEC_MAX_ERRNO+1][80] = 
{
	"", //EXEC_OK = 0 ,
	"", //EXEC_ERR_NO_SUCH_CMD,
	"", //EXEC_ERR_NO_SUCH_TID,
	"", //EXEC_ERR_NO_SUCH_FILE,
	"", //EXEC_ERR_NO_RESOURCE,
	"", //EXEC_ERR_NO_SUCH_ENTITY,
	"", //EXEC_ERR_CMD_NOT_SUPPORT,
	"", //EXEC_ERR_FILE_EXIST,
	"", //EXEC_ERR_FILE_NOT_EXIST,
	"", //EXEC_ERR_FILE_BUSY,
	"", //EXEC_ERR_FILE_CREATE_FAILED,
	"", //EXEC_ERR_FILE_ACCESS_FAILED,
	"", //EXEC_ERR_RESOURCE_CREATE_FAILED, 
	"", //EXEC_ERR_RESOURCE_CONFIG_FAILED, 
	"", //EXEC_ERR_RESOURCE_BUSY,
	"", //EXEC_ERR_RESOURCE_INIT_FAILED,
	"", //EXEC_ERR_TIMEOUT,
	"", //EXEC_ERR_UNKNOWN_TRAP_GROUP,
	"", //EXEC_ERR_UNKNOWN_TRAP_ID,
	"", //EXEC_ERR,
	"", //EXEC_MAX_ERRNO
} ;

