#include <iostream>
#include <cstdint>
#include "serialize.hpp"

int	main(void) {
	Data	whoa = {"ok cool", {1, 2}};

	uintptr_t	raw = serialize(&whoa);
	Data*		dataPtr = deserialize(raw);
	if (dataPtr)
		std::cout << dataPtr->str << ' ' << dataPtr->settings[0] << ' ' << dataPtr->settings[1] << std::endl;
}