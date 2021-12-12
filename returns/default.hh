/**
 * This header file is written to return default reference from a function in C++.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/returns.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "default.hh" under "returns" directory
 * returns version: 1.0.0
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

#ifdef __cplusplus

#pragma once

#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
#include <utility>
#else
#include <bits/move.h>
#endif

class default_t
{
public:
    template <typename T>
    operator T &() const
    {
        static T __t[1] = {};
        return __t[0];
    }

    template <typename T>
    T &operator()(const T &t) const
    {
        static T __t[1] = {};
        return (__t[0] = std::move(t));
    }
};

#endif