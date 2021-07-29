#include "EngineTimer.h"

using namespace std::chrono;

EngineTimer::EngineTimer() noexcept
{
	last = steady_clock::now();
}

float EngineTimer::Mark() noexcept
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float EngineTimer::Peek() const noexcept
{
	return duration<float>( steady_clock::now() - last ).count();
}
