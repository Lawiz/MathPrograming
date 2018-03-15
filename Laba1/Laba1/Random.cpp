#include "stdafx.h"
#include "Random.h"
#include <random>

Random::Random(uint_least32_t seed)
{
	this->_randomNumberGenerator = std::mt19937(seed);
	this->_realDistribution = std::uniform_real_distribution<double_t>();
	this->_bytedistribution = std::uniform_int_distribution<int32_t>(0, 256);
}

int32_t Random::Next()
{
	return this->Next(0, INT32_MAX);
}

int32_t Random::Next(int32_t maxValue)
{
	return this->Next(0, maxValue);
}

int32_t Random::Next(int32_t minValue, int32_t maxValue)
{
	std::uniform_int_distribution<int32_t> distribution(minValue, maxValue);
	return distribution(this->_randomNumberGenerator);
}

double_t Random::NextDouble()
{
	return this->_realDistribution(this->_randomNumberGenerator);
}

double_t Random::NextDouble(double_t minValue, double_t maxValue)
{
	std::uniform_real_distribution<double_t> distribution(minValue, minValue);
	return this->_realDistribution(this->_randomNumberGenerator);
}

void Random::NextBytes(std::vector<uint8_t>& buffer)
{
	for (auto &i : buffer)
	{
		i = static_cast<uint8_t>(_bytedistribution(this->_randomNumberGenerator));
	}
}
