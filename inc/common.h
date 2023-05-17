#ifndef COMMON_H
#define COMMON_H

#include <iostream>
using namespace std;

/*define debug flag*/
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define PRINT(format, ...) printf("[APP][%s]: " format "\n", __FILENAME__, __VA_ARGS__)
#if defined NDEBUG
#define INFO(_format, ...)
#define ERROR(_error, ...)
#else
#define INFO(format, ...) printf("[INFO] [%s]::[%s (line: %d)]: " format "\n", __FILENAME__, __FUNCTION__, __LINE__, __VA_ARGS__)
#define ERROR(error, ...) printf("[ERROR] [%s]::[%s (line: %d)]: " error "\n", __FILENAME__, __FUNCTION__, __LINE__, __VA_ARGS__)
#endif

#endif