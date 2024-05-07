#pragma once

#include <cassert>

#define LOG_INFO(x) std::cout << x << std::endl;

#define LOG_ERROR(x) std::cerr << x << std::endl;

#define ASSERT(x, info) if(!(x)) { LOG_ERROR(info); assert(x); }