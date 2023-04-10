/**
 * This header file is written store morse code for (A-Z), (a-z), (0-9) and WHITESPACE.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/sstring.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "morse_code.h" under "sstring" directory
 * sstring: version 2.5.0
 * BSD 3-Clause License
 *
 * Copyright (c) 2023, Tushar Chaurasia
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SSTRING_MORSE_DEFINED
#define SSTRING_MORSE_DEFINED

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

#endif