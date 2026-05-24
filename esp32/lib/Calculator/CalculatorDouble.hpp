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

/**
 * @file CalculatorDouble.hpp
 * @brief Header-only implementation for `Calculator` that uses `double` as its data type.
 * @author Ronald Rink
 * @date 2026-05-09
 * @version 1.0
 */

#pragma once

#include <stdexcept>
#include <limits>

namespace Calculator
{
    /**
     * @class CalculatorDouble
     * @brief This class is a calculator that you can use to do basic arithmetic operations.
     * @details The class records the result of the last operation and shows if the last operation created an error.
     */
    class CalculatorDouble
    {
    public:
        // Use "initializer list" (see below) instead of assignment in body.
        // CalculatorDouble()
        // {
        //     result_ = INITIAL_VALUE;
        //     is_error_ = false;
        // }

        /**
         * @brief This constructor create an instance of the `Calculator` object.
         */
        CalculatorDouble() : result_(INITIAL_VALUE), is_error_(false)
        {
            // N/A
        }

        /**
         * @brief Resets the calculator to its initial state.
         * @post @post result() == INITAL_VALUE && is_error() == false
         * @return This method does not return anything.
         */
        void clear() noexcept
        {
            result_ = INITIAL_VALUE;
            is_error_ = false;
        }

        /**
         * @brief This is the result of the last arithmetic operation.
         */
        const double result() const noexcept
        {
            return result_;
        }

        /**
         * @brief This shows if the last arithmetic operation caused an error.
         * @return A `bool` that is `true`, if the last arithmetic operation caused an error. `False`, if not.
         */
        const bool is_error() const noexcept
        {
            return is_error_;
        }

        double add(double augend, double addend) noexcept
        {
            // `result` is the *sum* of the operation.
            result_ = augend + addend;

            is_error_ = false;
            return result_;
        }

        double add(double addend) noexcept
        {
            if(is_error_)
            {
                // return NaN;
            }

            return add(result_, addend);
        }

        double subtract(double minuend, double subtrahend) noexcept
        {
            // `result` is the *difference* of the operation.
            auto result = minuend - subtrahend;

            // if NaN, +inf or -inf, set is_error to true
            is_error_ = false;

            return result;
        }

        double subtract(double subtrahend) noexcept
        {
            if(is_error_)
            {
                // return NaN;
            }

            return subtract(result_, subtrahend);
        }

        double multiply(double multiplicand, double multiplier) noexcept
        {
            // `result` is the *product* of the operation.
            auto result = multiplicand * multiplier;

            return result;
        }

        double divide(double dividend, double divisor) noexcept
        {
            // `result` is the *quotient* of the operation.
            auto result = dividend / divisor;

            return result;
        }

    private:
        /**
         * @brief The initial value of the calculator.
         */
        static constexpr double INITIAL_VALUE = 0.0;

        /**
         * @brief This is the result of the last arithmetic operation.
         */
        double result_;

        /**
         * @brief This shows if the last operation caused an error.
         */
        bool is_error_;
    };
}
