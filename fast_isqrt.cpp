#include <limits>
#include <bit>
#include <cstdint>
#include <cassert>
#include <iostream>

using namespace std;

float fast_isqrt(float operand) {
    // Check that we're using the correct floating point standard and real square root is attainable
    static_assert(numeric_limits<float>::is_iec559);
    assert(operand >= 0);

    // Quake constant (FP approximation of sqrt(2^127))
    uint32_t magic_number = 0x5f3759df;

    // Bit reinterpretation magic
    float const y = bit_cast<float>(magic_number - (bit_cast<uint32_t>(operand) >> 1));

    // First-order Newton's method approximation
    return y * (1.5f - (operand * 0.5f * y * y));
}

int main() {
    cout << fast_isqrt(1); // Returns 0.998307 (as opposed to 1)
    cout << fast_isqrt(16); // Returns 0.249577 (as opposed to 0.25)
    cout << fast_isqrt(100); // Returns 0.0998449 (as opposed to 0.1)
    cout << fast_isqrt(6182004); // Returns 0.000401675 (as opposed to 0.000402194)
}
