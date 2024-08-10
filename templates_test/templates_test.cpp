#include "pch.h"
#include "CppUnitTest.h"
#include "../templates/templates.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace templatestest
{
	TEST_CLASS(templatestest)
	{
	public:
		
		TEST_METHOD(TestHtoN)
		{
			bool le = isLittleEndian();

			uint16_t h16 = 0xabcd;
			uint16_t n16 = hton(h16);
			
			if (le)
			{
				Assert::AreEqual(n16, (uint16_t)0xcdab, L"Conversion failed for 16 bit data");
			}
			else
			{
				Assert::AreEqual(n16, h16, L"Conversion failed for 16 bit data");
			}

			uint32_t h32 = 0x1234abcd;
			uint32_t n32 = hton(h32);

			if (le)
			{
				Assert::AreEqual(n32, (uint32_t)0xcdab3412, L"Conversion failed for 32 bit data");
			}
			else
			{
				Assert::AreEqual(n32, h32, L"Conversion failed for 32 bit data");
			}

			uint64_t h64 = 0x1234567890abcdef;
			uint64_t n64 = hton(h64);

			if (le)
			{
				Assert::AreEqual(n64, (uint64_t)0xefcdab9078563412, L"Conversion failed for 64 bit data");
			}
			else
			{
				Assert::AreEqual(n64, h64, L"Conversion failed for 64 bit data");
			}
		}
	};
}
