#ifndef CM_UTIL_LOG_HPP
#define CM_UTIL_LOG_HPP

#include <stdio.h>
#include <sys/time.h>
#include "util/util.hpp"

#define lock_log_write(...) \
  do { \
    extern FILE *lock_log_fp; \
    fprintf(lock_log_fp, __VA_ARGS__); \
    fflush(lock_log_fp); \
  } while(0) 

#define WAIT_CV(cv, lk, s, status, wait_value, ...) \
  do { \
    cv->wait(lk, [s, status, wait_value]{ return (*status)[s] < wait_value; }); \
    extern FILE* lock_log_fp; \
    if(log_enable && true){ \
      fprintf(lock_log_fp, __VA_ARGS__); \
      fflush(lock_log_fp); \
    } \
  } while(0) \

#define SET_LOCK(lk, ...) \
  do{ \
    lk.lock(); \
    extern FILE* lock_log_fp; \
    if(log_enable && true){ \
      fprintf(lock_log_fp, __VA_ARGS__); \
      fflush(lock_log_fp); \
    } \
  } while(0) \

#define UNSET_LOCK(lk, ...) \
  do{ \
    lk.unlock(); \
    extern FILE* lock_log_fp; \
    if(log_enable && true){ \
      fprintf(lock_log_fp, __VA_ARGS__); \
      fflush(lock_log_fp); \
    } \
  } while(0) \

long long get_time(){
  struct timespec currentTime;
  clock_gettime(CLOCK_REALTIME, &currentTime);
  return currentTime.tv_nsec;
}

bool log_enable = false;

void close_log(){
  log_enable = false;
}

#endif