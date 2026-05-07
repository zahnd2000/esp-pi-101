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

#if defined(ESP_PLATFORM)

#include "Pin.h"

using Gpio::Pin;

namespace Gpio
{
    Pin::Pin(const gpio_num_t number, gpio_mode_t mode)
        : number(number), mode(mode)
    {
        gpio_reset_pin(number);
        gpio_set_direction(number, GPIO_MODE_OUTPUT);
    }

    bool Pin::Get()
    {
        auto level = gpio_get_level(number);
        auto result = level == High ? true : false;
        
        return result;
    }

    void Pin::Set(bool flag)
    {
        gpio_set_level(number, flag ? High : Low);
    }
}

#endif
