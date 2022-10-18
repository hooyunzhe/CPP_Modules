#include "Serialization.hpp"

uintptr_t	serialize(Data *ptr) {
	return ((uintptr_t)ptr);
}

Data	*deserialize(uintptr_t raw) {
	return ((Data *)raw);
}