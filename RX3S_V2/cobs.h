#pragma once

#include <stdint.h>
#include <stddef.h>

size_t cobs_encode(const uint8_t* restrict input, size_t size, uint8_t* restrict output);
