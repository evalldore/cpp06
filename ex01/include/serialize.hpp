#pragma once
#include <cstdint>
#include "data.hpp"

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);