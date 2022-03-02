#include <string>
#include <sstream>
#include <chrono>

#include "logger.h"

#define TIC() \
{\
   std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();\
   int start_line = __LINE__;

#define TOC(SEVERITY) \
   std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); \
   std::stringstream ss; \
   ss << "time taken lines " << start_line << "->" << __LINE__ << " " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " [µs]";\
   LOG(SEVERITY, ss.str()) ;\
}
