#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

bool isLittleEndian();

// Generic host to network function
template<class T>
T hton(const T h)
{
	static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value, "Unsupported type");

	if (!isLittleEndian())
	{
		return h;
	}

	auto size = sizeof(T);
	T n = 0;
	const uint8_t* bp = reinterpret_cast<const uint8_t*>(&h);

	for (auto i = 0; i < size; i++)
	{
		n |= static_cast<T>(bp[i]) << ((size - (i + 1)) * 8);
	}

	return n;
}