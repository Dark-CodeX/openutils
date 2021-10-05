/**
* This header file is written reduce time complexity of `to_binary` function under `sstring` struct.
* Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
* Commit to this repository at https://github.com/Dark-CodeX/SafeString.git
* You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
* File: "binary.h" under "sstring" directory
* sstring: version 15.5.0
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

static const char *binary_data[] =
    {
        "00000000", "00000001", "00000010", "00000011", "00000100", "00000101", "00000110", "00000111", "00001000",
        "00001001", "00001010", "00001011", "00001100", "00001101", "00001110", "00001111", "00010000", "00010001",
        "00010010", "00010011", "00010100", "00010101", "00010110", "00010111", "00011000", "00011001", "00011010",
        "00011011", "00011100", "00011101", "00011110", "00011111", "00100000", "00100001", "00100010", "00100011",
        "00100100", "00100101", "00100110", "00100111", "00101000", "00101001", "00101010", "00101011", "00101100",
        "00101101", "00101110", "00101111", "00110000", "00110001", "00110010", "00110011", "00110100", "00110101",
        "00110110", "00110111", "00111000", "00111001", "00111010", "00111011", "00111100", "00111101", "00111110",
        "00111111", "01000000", "01000001", "01000010", "01000011", "01000100", "01000101", "01000110", "01000111",
        "01001000", "01001001", "01001010", "01001011", "01001100", "01001101", "01001110", "01001111", "01010000",
        "01010001", "01010010", "01010011", "01010100", "01010101", "01010110", "01010111", "01011000", "01011001",
        "01011010", "01011011", "01011100", "01011101", "01011110", "01011111", "01100000", "01100001", "01100010",
        "01100011", "01100100", "01100101", "01100110", "01100111", "01101000", "01101001", "01101010", "01101011",
        "01101100", "01101101", "01101110", "01101111", "01110000", "01110001", "01110010", "01110011", "01110100",
        "01110101", "01110110", "01110111", "01111000", "01111001", "01111010", "01111011", "01111100", "01111101",
        "01111110", "01111111"};