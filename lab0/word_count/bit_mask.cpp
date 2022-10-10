#include "word_count.h"

word_count::bit_mask::bit_mask() {
	mask = { 65472, 9223371901563305952, 8388736, 18446744073709551615 };
}

bool word_count::bit_mask::match(unsigned int degree) const {
	if (degree >= mask.size() * base) {
		return false;
	}
	return (mask[degree / base] & ((unsigned long long)1 << (base - 1 - (degree % base)))) == 0;
}