#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>
#include <cstring> // contains strchr
#include <vector>
#include <map>
#include <array>

using namespace std;

/*define debug flag*/
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#if defined NDEBUG
#define INFO(_format, ...)
#define ERROR(_error, ...)
#else
#define _log_info(format, ...) printf("[INFO] [%s]::[%s (line: %d)]: " format "\n", __FILENAME__, __FUNCTION__, __LINE__, __VA_ARGS__)
#define log_info(format, ...) printf("[INFO] [%s]::[%s (line: %d)]: " format "\n", __FILENAME__, __FUNCTION__, __LINE__)
#define _log_error(error, ...) printf("[ERROR] [%s]::[%s (line: %d)]: " error "\n", __FILENAME__, __FUNCTION__, __LINE__, __VA_ARGS__)
#define log_error(error, ...) printf("[ERROR] [%s]::[%s (line: %d)]: " error "\n", __FILENAME__, __FUNCTION__, __LINE__)
#endif

/*define data type*/
using BYTE = unsigned char;  // 8 BIT
using WORD = unsigned short; // 16 BIT

enum CODE
{
    OK = 0,
    ERROR = -1
};

#endif