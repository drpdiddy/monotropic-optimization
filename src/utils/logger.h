#pragma once

#ifdef HAVE_BOOST

#include <boost/log/trivial.hpp>
namespace logging = boost::log;
namespace keywords = boost::log::keywords;

namespace MonotropicOptimization {

   struct Logger {

      enum Severity {
          ALL   = 0,	//All levels including custom levels.
          TRACE = 1,	//Designates finer-grained informational events than the DEBUG.
          DEBUG = 2,	//Designates fine-grained informational events that are most useful to debug an application.
          INFO  = 3,	//Designates informational messages that highlight the progress of the application at coarse-grained level.
          WARN  = 4,	//Designates potentially harmful situations.
          ERROR = 5,	//Designates error events that might still allow the application to continue running.
          FATAL = 6,	//Designates very severe error events that will presumably lead the application to abort.
          OFF   = 7,	//The highest possible rank and is intended to turn off logging.
      };

      Severity level;

      Logger(Severity level) : level(level) {}

      const Logger& operator <<(const std::string& message) {
            switch (this->level) {
               case Severity::ALL:
               case Severity::TRACE:
                  BOOST_LOG_TRIVIAL(trace)   << message; 
                  break;
               case Severity::DEBUG:
                  BOOST_LOG_TRIVIAL(debug)   << message;
                  break;
               case Severity::INFO:
                  BOOST_LOG_TRIVIAL(info)    << message;
                  break;
               case Severity::WARN:
                  BOOST_LOG_TRIVIAL(warning) << message; 
                  break;          
               case Severity::ERROR:
                  BOOST_LOG_TRIVIAL(error)   << message;
                  break;     
               case Severity::FATAL:
                  BOOST_LOG_TRIVIAL(error)   << message;
                  break;
               default:
                  break;
            }
            return *this;
      }
   };

}

#define LOG(SEVERITY, MESSAGE) \
    MonotropicOptimization::Logger(MonotropicOptimization::Logger::Severity::SEVERITY) << \
         std::string(__FILE__) + ":" + std::to_string(__LINE__) + ": "+ std::string(MESSAGE);


#else

#define LOG(SEVERITY, MESSAGE) \
    std::cout << std::string(__FILE__) + ":" + std::to_string(__LINE__) + ": "+ std::string(MESSAGE);

#endif