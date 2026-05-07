/**
MIT License  
 
Copyright (c) 2023-2026 Ronald Rink
 
Permission is hereby granted, free of charge, to any person obtaining a copy  
of this software and associated documentation files (the "Software"), to deal  
in the Software without restriction, including without limitation the rights  
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  
copies of the Software, and to permit persons to whom the Software is  
furnished to do so, subject to the following conditions:  
 
The above copyright notice and this permission notice shall be included in all  
copies or substantial portions of the Software.  
 
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  
SOFTWARE.
*/

#include <unity.h>

#include <Contract.h>

using Contract::Assert;
using Contract::ErrorCode;

extern "C"
{
    namespace test::envNative::test_Contract
    {
        class ArbitraryClass
        {
            public:
                bool ThrowsOnTrue(bool flag)
                {
                    Assert([flag] { return !flag; }, ErrorCode::InvalidArgument);

                    return !flag;
                }

                bool ThrowsOnTrueWithDefaultArgument(bool flag)
                {
                    Assert([flag] { return !flag; });

                    return !flag;
                }

        };

        void setUp(void)
        {
            // N/A
        }

        void tearDown(void)
        {
            // N/A
        }

        void AssertDoesNotThrow()
        {
            ArbitraryClass sut;

            auto result = sut.ThrowsOnTrue(false);

            TEST_ASSERT_TRUE(result);
        }

        void AssertDoesThrow()
        {
            ArbitraryClass sut;

            auto hasThrown = false;
            try
            {
                auto result = sut.ThrowsOnTrue(true);
            }
            catch(const std::exception& e)
            {
                hasThrown = true;
            }

            TEST_ASSERT_TRUE(hasThrown);
        }

        void AssertDoesThrowWithDefaultArgument()
        {
            ArbitraryClass sut;

            auto hasThrown = false;
            try
            {
                auto result = sut.ThrowsOnTrueWithDefaultArgument(true);
            }
            catch(const std::exception& e)
            {
                hasThrown = true;
            }

            TEST_ASSERT_TRUE(hasThrown);
        }

        int runUnityTests(void)
        {
            UNITY_BEGIN();

            RUN_TEST(AssertDoesNotThrow);
            RUN_TEST(AssertDoesThrow);
            RUN_TEST(AssertDoesThrowWithDefaultArgument);

            return UNITY_END();
        }

        void app_main() 
        {
            runUnityTests();
        }

        int main(int argc, char **argv)
        {
            return runUnityTests();
        }
    }
}
