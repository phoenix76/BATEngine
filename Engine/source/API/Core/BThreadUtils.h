/***********************************************************************
BTHREADUTILS


***********************************************************************/

#ifndef BTHREADUTILS_H
#define BTHREADUTILS_H

#include <mutex>

#define THREAD_GUARD(mut) std::lock_guard<std::mutex> guard(mut)

#endif