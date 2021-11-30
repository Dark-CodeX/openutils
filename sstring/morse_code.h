/**
* This header file is written store morse code for (A-Z), (a-z), (0-9) and WHITESPACE.
* Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
* Commit to this repository at https://github.com/Dark-CodeX/SafeString.git
* You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
* File: "morse_code.h" under "sstring" directory
* sstring: version 49.3.0
* 
* MIT License
* 
* Copyright (c) 2021 Tushar Chaurasia
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#pragma once

struct morse_code
{
    const char *code;
    char character;
} morse_code[] =
    {
        {"-----", '0'},
        {".----", '1'},
        {"..---", '2'},
        {"...--", '3'},
        {"....-", '4'},
        {".....", '5'},
        {"-....", '6'},
        {"--...", '7'},
        {"---..", '8'},
        {"----.", '9'},
        {".-", 'a'},
        {"-...", 'b'},
        {"-.-.", 'c'},
        {"-..", 'd'},
        {".", 'e'},
        {"..-.", 'f'},
        {"--.", 'g'},
        {"....", 'h'},
        {"..", 'i'},
        {".---", 'j'},
        {"-.-", 'k'},
        {".-..", 'l'},
        {"--", 'm'},
        {"-.", 'n'},
        {"---", 'o'},
        {".--.", 'p'},
        {"--.-", 'q'},
        {".-.", 'r'},
        {"...", 's'},
        {"-", 't'},
        {"..-", 'u'},
        {"...-", 'v'},
        {".--", 'w'},
        {"-..-", 'x'},
        {"-.--", 'y'},
        {"--..", 'z'},
        {".......", ' '}};