#pragma once

#include <cmath>
#include <iostream>
#include <fstream>
#include <limits>
#include <memory>
#include <vector>
#include <random>


// Constants

const double INF = std::numeric_limits<double>::infinity();
const double PI = 3.1415926535897932385;


// Pointers

template<typename T>
using Scope = std::unique_ptr<T>;
template<typename T, typename ... Args>
constexpr Scope<T> createScope(Args&& ... args)
{
	return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T>
using Ref = std::shared_ptr<T>;
template<typename T, typename ... Args>
constexpr Ref<T> createRef(Args&& ... args)
{
	return std::make_shared<T>(std::forward<Args>(args)...);
}


// Utility

inline double degreesToRadians(double degrees) 
{
	return degrees * PI / 180.0;
}

inline double clamp(double x, double min, double max) 
{
	if (x < min) return min;
	if (x > max) return max;
	return x;
}

template<typename T>
inline T mix(const T& x, const T& y, double a)
{
	return x + (y - x) * a;
}

inline double random() 
{
	static std::uniform_real_distribution<double> distribution(0.0, 1.0);
	static std::mt19937 generator;
	return distribution(generator);
}

inline double random(double min, double max) 
{
	return min + (max - min) * random();
}

#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60

inline void printProgress(double percentage) {
	int val = (int)(percentage * 100);
	int lpad = (int)(percentage * PBWIDTH);
	int rpad = PBWIDTH - lpad;
	printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
	fflush(stdout);
}