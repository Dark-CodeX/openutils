/**
 * This header file contains `time` class.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/date-time.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "time.hh" under "date-time" directory
 * date-time: version 1.0.1
 * MIT License
 *
 * Copyright (c) 2023 Tushar Chaurasia
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

#ifndef TIME_H
#define TIME_H

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <openutils/sstring/sstring.hh>
#include <iostream>

#define date_time_version "1.0.1"

namespace openutils
{
	class time
	{
	private:
		unsigned int hour, minute, second;

	public:
		time();
		time(const time &t);
		time(time &&t);
		time(const unsigned int &hour_, const unsigned int &minute_, const unsigned int &second_);
		time(const openutils::sstring &str);
		void add(const time &t);
		void add(const unsigned long &skip_sec);
		void substract(const time &t);
		void substract(const unsigned long &skip_sec);
		unsigned long seconds_between(const time &FINAL) const;
		time get_ctime(void) const;
		bool is_am(void) const;
		sstring to_string(bool AMPM = true) const;
		time operator+(const time &dt) const;
		time operator+(const unsigned long &skip_sec) const;
		time operator-(const time &dt) const;
		time operator-(const unsigned long &skip_sec) const;
		void operator+=(const time &dt);
		void operator+=(const unsigned long &skip_sec);
		void operator-=(const time &dt);
		void operator-=(const unsigned long &skip_sec);
		void operator=(const time &dt);
		void operator=(time &&dt);
		bool operator>(const time &dt) const;
		bool operator<(const time &dt) const;
		bool operator>=(const time &dt) const;
		bool operator<=(const time &dt) const;
		bool operator==(const time &dt) const;
		bool operator!=(const time &dt) const;
		~time();
	};

	time::time()
	{
		std::time_t t = std::time(nullptr);
		struct std::tm *ct = std::localtime(&t);

		this->hour = ct->tm_hour;
		this->minute = ct->tm_min;
		this->second = ct->tm_sec;
	}

	time::time(const time &dt)
	{
		this->hour = dt.hour;
		this->minute = dt.minute;
		this->second = dt.second;
	}

	time::time(time &&dt)
	{
		this->hour = dt.hour;
		this->minute = dt.minute;
		this->second = dt.second;
	}

	time::time(const unsigned int &hour_, const unsigned int &minute_, const unsigned int &second_)
	{
		if (hour_ > 24)
		{
			std::fprintf(stderr, "err: %i is a hour and should not be greater than 24.\n", hour_);
			std::exit(EXIT_FAILURE);
		}
		if (minute_ > 60)
		{
			std::fprintf(stderr, "err: %i is a minute and should not be greater than 60.\n", minute_);
			std::exit(EXIT_FAILURE);
		}
		if (second_ > 60)
		{
			std::fprintf(stderr, "err: %i is a second and should not be greater than 60.\n", second_);
			std::exit(EXIT_FAILURE);
		}
		std::tm i_tm = {};
		i_tm.tm_hour = hour_;
		i_tm.tm_min = minute_;
		i_tm.tm_sec = second_;
		std::mktime(&i_tm);

		this->hour = i_tm.tm_hour;
		this->minute = i_tm.tm_min;
		this->second = i_tm.tm_sec;
	}

	time::time(const openutils::sstring &str)
	{
		unsigned int h = 0, m = 0, s = 0;
		vector_t<heap_pair<sstring, enum lexer_token>> parse = str.lexer();
		std::size_t n = 0;
		while (parse.get(n).second() != openutils::lexer_token::NULL_END)
		{
			if (parse.get(n).second() == openutils::lexer_token::INTEGER && n == 0)
			{
				h = std::strtoull(parse[n].first().c_str(), nullptr, 10);
				n++;
			}
			else
			{
				std::fprintf(stderr, "err: `%s` in `%s` should be a hour (integer).\n", parse[n].first().c_str(), str.c_str());
				std::exit(EXIT_FAILURE);
			}
			if (parse.get(n).second() != openutils::lexer_token::SPECIAL_CHAR && n == 1)
			{
				std::fprintf(stderr, "err: `%s` in `%s` should be a separator between hour and minute.\n", parse[n].first().c_str(), str.c_str());
				std::exit(EXIT_FAILURE);
			}
			else
				n++;
			if (parse.get(n).second() == openutils::lexer_token::INTEGER && n == 2)
			{
				m = std::strtoull(parse[n].first().c_str(), nullptr, 10);
				n++;
			}
			else
			{
				std::fprintf(stderr, "err: `%s` in `%s` should be a minute (integer).\n", parse[n].first().c_str(), str.c_str());
				std::exit(EXIT_FAILURE);
			}
			if (parse.get(n).second() != openutils::lexer_token::SPECIAL_CHAR && n == 3)
			{
				std::fprintf(stderr, "err: `%s` in `%s` should be a separator between minute and second.\n", parse[n].first().c_str(), str.c_str());
				std::exit(EXIT_FAILURE);
			}
			else
				n++;
			if (parse.get(n).second()== openutils::lexer_token::INTEGER && n == 4)
			{
				s = std::strtoull(parse[n].first().c_str(), nullptr, 10);
				n++;
			}
			else
			{
				std::fprintf(stderr, "err: `%s` in `%s` should be a second (integer).\n", parse[n].first().c_str(), str.c_str());
				std::exit(EXIT_FAILURE);
			}
			if (parse.length() != n + 1)
			{
				std::fprintf(stderr, "err: `%s` in `%s` is exceeding the time format (HH:MM:SS).\n", parse[n].first().c_str(), str.c_str());
				std::exit(EXIT_FAILURE);
			}
		}
		*this = time(h, m, s);
	}

	void time::add(const time &t)
	{
		unsigned long sec_bw = this->seconds_between(t);
		std::tm i_tm = {};
		i_tm.tm_hour = this->hour;
		i_tm.tm_min = this->minute;
		i_tm.tm_sec = this->second;
		i_tm.tm_sec += sec_bw;
		std::mktime(&i_tm);

		this->hour = i_tm.tm_hour;
		this->minute = i_tm.tm_min;
		this->second = i_tm.tm_sec;
	}

	void time::add(const unsigned long &skip_sec)
	{
		std::tm i_tm = {};
		i_tm.tm_hour = this->hour;
		i_tm.tm_min = this->minute;
		i_tm.tm_sec = this->second;
		i_tm.tm_sec += skip_sec;
		std::mktime(&i_tm);

		this->hour = i_tm.tm_hour;
		this->minute = i_tm.tm_min;
		this->second = i_tm.tm_sec;
	}

	void time::substract(const time &t)
	{
		unsigned long sec_bw = this->seconds_between(t);
		std::tm i_tm = {};
		i_tm.tm_hour = this->hour;
		i_tm.tm_min = this->minute;
		i_tm.tm_sec = this->second;
		i_tm.tm_sec -= sec_bw;
		std::mktime(&i_tm);

		this->hour = i_tm.tm_hour;
		this->minute = i_tm.tm_min;
		this->second = i_tm.tm_sec;
	}

	void time::substract(const unsigned long &skip_sec)
	{
		std::tm i_tm = {};
		i_tm.tm_hour = this->hour;
		i_tm.tm_min = this->minute;
		i_tm.tm_sec = this->second;
		i_tm.tm_sec -= skip_sec;
		std::mktime(&i_tm);

		this->hour = i_tm.tm_hour;
		this->minute = i_tm.tm_min;
		this->second = i_tm.tm_sec;
	}

	unsigned long time::seconds_between(const time &FINAL) const
	{
		std::tm i_tm = {};
		i_tm.tm_hour = this->hour, i_tm.tm_min = this->minute, i_tm.tm_sec = this->second;
		time_t i = std::mktime(&i_tm);

		std::tm f_tm = {};
		f_tm.tm_hour = FINAL.hour, f_tm.tm_min = FINAL.minute, f_tm.tm_sec = FINAL.second;
		time_t f = std::mktime(&f_tm);
		return std::difftime(f, i);
	}

	time time::get_ctime(void) const
	{
		time x = time();
		return x;
	}

	bool time::is_am(void) const
	{
		return this->hour < 12;
	}

	sstring time::to_string(bool AMPM) const
	{
		sstring x;
		if (AMPM)
		{
			x.set_formatted(1024, "%i:%i:%i %s", ((this->hour + 11) % 12 + 1), this->minute, this->second, ((this->hour >= 12) ? "PM" : "AM"));
			return x;
		}
		x.set_formatted(1024, "%i:%i:%i", this->hour, this->minute, this->second);
		return x;
	}

	time time::operator+(const time &dt) const
	{
		time d = time(*this);
		d.add(dt);
		return d;
	}

	time time::operator+(const unsigned long &skip_sec) const
	{
		time d = time(*this);
		d.add(skip_sec);
		return d;
	}

	time time::operator-(const time &dt) const
	{
		time d = time(*this);
		d.substract(dt);
		return d;
	}

	time time::operator-(const unsigned long &skip_sec) const
	{
		time d = time(*this);
		d.substract(skip_sec);
		return d;
	}

	void time::operator+=(const time &dt)
	{
		this->add(dt);
	}

	void time::operator+=(const unsigned long &skip_sec)
	{
		this->add(skip_sec);
	}

	void time::operator-=(const time &dt)
	{
		this->substract(dt);
	}

	void time::operator-=(const unsigned long &skip_sec)
	{
		this->substract(skip_sec);
	}

	void time::operator=(const time &dt)
	{
		this->hour = dt.hour;
		this->minute = dt.minute;
		this->second = dt.second;
	}

	void time::operator=(time &&dt)
	{
		this->hour = dt.hour;
		this->minute = dt.minute;
		this->second = dt.second;
	}

	bool time::operator>(const time &dt) const
	{
		if (this->hour > dt.hour)
			return true;
		else if (this->hour < dt.hour)
			return false;
		else
		{
			if (this->minute > dt.minute)
				return true;
			else if (this->minute < dt.minute)
				return false;
			else
			{
				if (this->second > dt.second)
					return true;
				else if (this->second < dt.second)
					return false;
				else
					return false;
			}
		}
	}

	bool time::operator<(const time &dt) const
	{
		if (this->hour > dt.hour)
			return false;
		else if (this->hour < dt.hour)
			return true;
		else
		{
			if (this->minute > dt.minute)
				return false;
			else if (this->minute < dt.minute)
				return true;
			else
			{
				if (this->second > dt.second)
					return false;
				else if (this->second < dt.second)
					return true;
				else
					return false;
			}
		}
	}

	bool time::operator>=(const time &dt) const
	{
		if (this->hour > dt.hour)
			return true;
		else if (this->hour < dt.hour)
			return false;
		else
		{
			if (this->minute > dt.minute)
				return true;
			else if (this->minute < dt.minute)
				return false;
			else
			{
				if (this->second > dt.second)
					return true;
				else if (this->second < dt.second)
					return false;
				else
					return true;
			}
		}
	}

	bool time::operator<=(const time &dt) const
	{
		if (this->hour > dt.hour)
			return false;
		else if (this->hour < dt.hour)
			return true;
		else
		{
			if (this->minute > dt.minute)
				return false;
			else if (this->minute < dt.minute)
				return true;
			else
			{
				if (this->second > dt.second)
					return false;
				else if (this->second < dt.second)
					return true;
				else
					return true;
			}
		}
	}

	bool time::operator==(const time &dt) const
	{
		return ((this->hour == dt.hour) && (this->minute == dt.minute) && (this->second == dt.second));
	}

	bool time::operator!=(const time &dt) const
	{
		return ((this->hour != dt.hour) && (this->minute != dt.minute) && (this->second != dt.second));
	}

	time::~time() = default;
}

#endif