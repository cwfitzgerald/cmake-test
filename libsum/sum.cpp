#include <iostream>

#include <simdpp/simd.h>

#include <simdpp/dispatch/get_arch_gcc_builtin_cpu_supports.h>
#include <simdpp/dispatch/get_arch_linux_cpuinfo.h>
#include <simdpp/dispatch/get_arch_raw_cpuid.h>

#if SIMDPP_HAS_GET_ARCH_RAW_CPUID
#define SIMDPP_USER_ARCH_INFO ::simdpp::get_arch_raw_cpuid()
#elif SIMDPP_HAS_GET_ARCH_GCC_BUILTIN_CPU_SUPPORTS
#define SIMDPP_USER_ARCH_INFO ::simdpp::get_arch_gcc_builtin_cpu_supports()
#elif SIMDPP_HAS_GET_ARCH_LINUX_CPUINFO
#define SIMDPP_USER_ARCH_INFO ::simdpp::get_arch_linux_cpuinfo()
#else
#error "Unsupported platform"
#endif

namespace SIMDPP_ARCH_NAMESPACE {
	std::size_t sumation(const std::vector<std::size_t>& array) {
		(void) array;
		return 1;
	}

} // namespace SIMDPP_ARCH_NAMESPACE

SIMDPP_MAKE_DISPATCHER((std::size_t)(sumation)((const std::vector<std::size_t>&) array))