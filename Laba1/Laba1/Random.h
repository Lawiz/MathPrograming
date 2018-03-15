#pragma once
#include <random>
class Random 
{
    std::mt19937 _randomNumberGenerator;
    std::uniform_real_distribution<double_t> _realDistribution;
    std::uniform_int_distribution<int32_t> _bytedistribution;
public:
    Random(uint_least32_t seed);
    Random() : Random(std::_Random_device()) {};
    ~Random();
    int32_t Next();
    int32_t Next(int32_t maxValue);
    int32_t Next(int32_t minValue, int32_t maxValue);
    double_t NextDouble();
    double_t NextDouble(double_t minValue, double_t maxValue);
    void NextBytes(std::vector<uint8_t>& buffer);
};