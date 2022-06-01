#pragma once

#define CHECK_RETURN_NULL(value)			if(value==NULL){return NULL;}
#define CHECK_RETURN_0(value)				if(value==NULL){return 0;}
#define CHECK_MSG_RETURN_NULL(value,msg)    if(value==NULL){puts(msg); return NULL;}

#define CHECK_NULL_CLOSE_FILE_RETURN_0(value,file) if(value==NULL){fclose(file);return 0;}
#define CHECK_NULL_MSG_FREE_CLOSE_FILE_RETURN_0(value,ptr,msg,file)  if(value==NULL){puts(msg); free(ptr); fclose(file);  return 0;}
