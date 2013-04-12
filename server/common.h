
#ifndef KINGSLANDING_ONLINEWHITEBOARD_SERVER_COMMON_H_
#define KINGSLANDING_ONLINEWHITEBOARD_SERVER_COMMON_H_

#undef FORBIDDEN_EVIL_CONSTRUCTORS
#define FORBIDDEN_EVIL_CONSTRUCTORS(TypeName) \
TypeName(const TypeName&); \
void operator=(const TypeName&)

#define	DEBUG

#include <glog/logging.h>
#include <gflags/gflags.h>

#ifdef DEBUG
#include <gtest/gtest.h>
#include <gtest/gtest_prod.h>
#endif

#endif