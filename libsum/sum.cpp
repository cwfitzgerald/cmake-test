#include <cinttypes>
#include <vector>

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
	int32_t sumation(const std::vector<int32_t>& array) {
		using simd_vec = simdpp::int32<SIMDPP_FAST_INT32_SIZE>;
		simd_vec sum{};
		std::size_t i = 0;
		for (; i < ((array.size() / SIMDPP_FAST_INT32_SIZE) * SIMDPP_FAST_INT32_SIZE); i += SIMDPP_FAST_INT32_SIZE) {
			simd_vec partial = simdpp::load_u(&array[i]);
			sum = sum + partial;
		}
		return simdpp::reduce_add(sum);
	}

} // namespace SIMDPP_ARCH_NAMESPACE

SIMDPP_MAKE_DISPATCHER((int32_t)(sumation)((const std::vector<int32_t>&) array))
