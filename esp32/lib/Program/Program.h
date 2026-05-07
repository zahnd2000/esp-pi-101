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

#pragma once

#include <memory>

namespace Program
{
    #define NAMEOF(name) #name

    #define LED_BUILTIN GPIO_NUM_2

    class Program
    {
        private:
            std::string message = "Hello, world!";
            
            explicit Program();

        public:
            Program(Program&& instance) noexcept;
            Program(const Program& instance) = delete;
            Program& operator=(const Program& instance) = delete;

            static void OutputFunc(void *pvParameter);

            virtual void Invoke();
        
        class Factory
        {
            private:
                Factory() = delete;

            public:
                static std::shared_ptr<Program> Create();
        };
    };
}

#endif
