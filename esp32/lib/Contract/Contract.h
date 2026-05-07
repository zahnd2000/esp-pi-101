/**
* Copyright (c) Bjarne Stroustrup
* Copyright (c) Ronald Rink
* See LICENSE file in the project root for full license information.
*/

#pragma once

#include <stdexcept>
#include <cstdint>
#include <iostream>
#include <vector>

#include "ErrorAction.h"
#include "ErrorCode.h"

namespace Contract
{
    #define NAMEOF(name) #name

    constexpr uint16_t MessageLength = 256;

    constexpr ErrorAction DefaultErrorAction = ErrorAction::Throw;

    template<ErrorAction action = DefaultErrorAction, class C>
    constexpr void Assert(C condition, ErrorCode errorCode = ErrorCode::InvalidArgument)
    {
        if constexpr(ErrorAction::Throw == action)
        {
            if(!condition()) 
            {
                std::vector<char> message(MessageLength);
                const char* format = "Assertion failed: 0x%04X\n";

                std::snprintf(message.data(), message.size(), format, errorCode);

                throw std::invalid_argument(message.data());
            }
        }

        if constexpr(ErrorAction::Log == action)
        {
            if(!condition()) 
            {
                std::cerr << 
                    "Assertion failed: " << 
                    uint16_t(errorCode) << 
                    std::hex <<
                    uint16_t(errorCode) << 
                    "\n";
            }
        }

        if constexpr(ErrorAction::Abort == action)
        {
            if(!condition()) 
            {
                abort();
            }
        }
    }

    template<ErrorAction action = DefaultErrorAction, class C>
    constexpr void Assert(C condition, const char* customMessage)
    {
        if constexpr(ErrorAction::Throw == action)
        {
            if(!condition()) 
            {
                std::vector<char> message(MessageLength);
                const char* format = "Assertion failed: %s\n";
                const char* messageDefault = "Assertion failed (custom message too long).";

                auto size = std::snprintf(message.data(), message.size(), format, customMessage);
                if(size > 0)
                {
                    throw std::invalid_argument(message.data());
                }
                else
                {
                    throw std::invalid_argument(messageDefault);
                }
            }
        }

        if constexpr(ErrorAction::Log == action)
        {
            if(!condition()) 
            {
                std::cerr << 
                    "Assertion failed: " << 
                    customMessage << 
                    "\n";
            }
        }

        if constexpr(ErrorAction::Abort == action)
        {
            if(!condition()) 
            {
                abort();
            }
        }
    }
}
