#ifndef UTIL_TYPES_H
#define UTIL_TYPES_H

#include <random>
using namespace std;

// Definition of some confusing but useful type names that are used throughout the project

// The actual RNG
// Mersenne Twister 19937 generator (64 bit)
typedef mt19937_64 Rng;

// Seed type of the RNG, in this case it's the same as it's result type (???)
typedef mt19937_64::result_type RngSeed;

#endif  // UTIL_TYPES_H
