/**
MIT License

Copyright (c) 2026 Ronald Rink

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

#include "../Calculator/CalculatorDouble.hpp"

#include <unity.h>

using Calculator::CalculatorDouble;

extern "C"
{
    namespace test::envNative::test_Calculator
    {
        void setUp(void)
        {
            // N/A
        }

        void tearDown(void)
        {
            // N/A
        }

        /**
         * @brief When you add two numbers, `add()` returns the sum of the operation.
         */
        void AddTwoNumbersSucceeds()
        {
            auto expected = 42.0;

            CalculatorDouble sut;

            [[maybe_unused]] auto result = sut.add(40.0, 2.0);

            TEST_ASSERT_EQUAL(expected, result);
        }

        int runUnityTests(void)
        {
            UNITY_BEGIN();

            RUN_TEST(AddTwoNumbersSucceeds);

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
