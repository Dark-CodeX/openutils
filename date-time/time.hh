/**
 * This header file contains `time` class.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/date-time.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "time.hh" under "date-time" directory
 * date-time: version 1.1.0
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

#ifndef TIME_DEFINED
#define TIME_DEFINED

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <openutils/sstring/sstring.hh>
#include <iostream>

#define date_time_version "1.1.0"

namespace openutils
{
    class time
    {
    private:
        unsigned hour, minute, second;

    public:
        time();
        time(const time &t);
        time(time &&t) noexcept;
        time(const unsigned &hour_, const unsigned &minute_, const unsigned &second_);
        time(const openutils::sstring &str);
        time &add(const time &t);
        time &add(const unsigned long &skip_sec);
        time &substract(const time &t);
        time &substract(const unsigned long &skip_sec);
        unsigned long seconds_between(const time &FINAL) const;
        time get_ctime() const;
        bool is_am() const;
        sstring to_string(bool AMPM = true) const;
        std::size_t hash() const;
        time operator+(const time &dt) const;
        time operator+(const unsigned long &skip_sec) const;
        time operator-(const time &dt) const;
        time operator-(const unsigned long &skip_sec) const;
        time &operator+=(const time &dt);
        time &operator+=(const unsigned long &skip_sec);
        time &operator-=(const time &dt);
        time &operator-=(const unsigned long &skip_sec);
        time &operator=(const time &dt);
        time &operator=(time &&dt) noexcept;
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

    time::time(time &&dt) noexcept
    {
        this->hour = dt.hour;
        this->minute = dt.minute;
        this->second = dt.second;
    }

    time::time(const unsigned &hour_, const unsigned &minute_, const unsigned &second_)
    {
        if (hour_ > 24)
        {
            std::fprintf(stderr, "err: %u is a hour and should not be greater than 24.\n", hour_);
            std::exit(EXIT_FAILURE);
        }
        if (minute_ > 60)
        {
            std::fprintf(stderr, "err: %u is a minute and should not be greater than 60.\n", minute_);
            std::exit(EXIT_FAILURE);
        }
        if (second_ > 60)
        {
            std::fprintf(stderr, "err: %u is a second and should not be greater than 60.\n", second_);
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
        unsigned h = 0, m = 0, s = 0;
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
            if (parse.get(n).second() == openutils::lexer_token::INTEGER && n == 4)
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

    time &time::add(const time &t)
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

        return *this;
    }

    time &time::add(const unsigned long &skip_sec)
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

        return *this;
    }

    time &time::substract(const time &t)
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

        return *this;
    }

    time &time::substract(const unsigned long &skip_sec)
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

        return *this;
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

    time time::get_ctime() const
    {
        time x = time();
        return x;
    }

    bool time::is_am() const
    {
        return this->hour < 12;
    }

    sstring time::to_string(bool AMPM) const
    {
        sstring x;
        if (AMPM)
        {
            x.set_formatted(1024, "%u:%u:%u %s", ((this->hour + 11) % 12 + 1), this->minute, this->second, ((this->hour >= 12) ? "PM" : "AM"));
            return x;
        }
        x.set_formatted(1024, "%u:%u:%u", this->hour, this->minute, this->second);
        return x;
    }

    std::size_t time::hash() const
    {
        std::size_t h1 = std::hash<unsigned>()(this->hour);
        std::size_t h2 = std::hash<unsigned>()(this->minute);
        std::size_t h3 = std::hash<unsigned>()(this->second);

        h1 ^= (h2 << 1) ^ (h3 << 2);
        return h1;
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

    time &time::operator+=(const time &dt)
    {
        this->add(dt);
        return *this;
    }

    time &time::operator+=(const unsigned long &skip_sec)
    {
        this->add(skip_sec);
        return *this;
    }

    time &time::operator-=(const time &dt)
    {
        this->substract(dt);
        return *this;
    }

    time &time::operator-=(const unsigned long &skip_sec)
    {
        this->substract(skip_sec);
        return *this;
    }

    time &time::operator=(const time &dt)
    {
        if (this != &dt)
        {
            this->hour = dt.hour;
            this->minute = dt.minute;
            this->second = dt.second;
        }
        return *this;
    }

    time &time::operator=(time &&dt) noexcept
    {
        if (this != &dt)
        {
            this->hour = dt.hour;
            this->minute = dt.minute;
            this->second = dt.second;
        }
        return *this;
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

namespace std
{
    template <>
    struct hash<openutils::time>
    {
        std::size_t operator()(const openutils::time &t) const
        {
            return t.hash();
        }
    };
};

#endif