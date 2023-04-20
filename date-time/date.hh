/**
 * This header file contains `date` class.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/date-time.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "date.hh" under "date-time" directory
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

#ifndef DATE_DEFINED
#define DATE_DEFINED

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <openutils/sstring/sstring.hh>

#define date_time_version "1.1.0"

namespace openutils
{
    class date
    {
      private:
        unsigned year, month, day;
        constexpr static inline bool is_leap(const unsigned &y);
        const unsigned month_day_count[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

      public:
        date();
        date(const date &dt);
        date(date &&dt) noexcept;
        date(const unsigned &day_, const unsigned &month_, const unsigned &year_);
        date(const openutils::sstring &str);
        int days_between(const date &dt) const;
        unsigned days_beginning() const;
        date &add(const date &dt);
        date &add(const int &skip_days);
        date &substract(const date &dt);
        date &substract(const int &skip_days);
        bool is_leap() const;
        date get_ctime() const;
        sstring to_string() const;
        date &swap(date &dt) noexcept;
        std::size_t hash() const;
        date operator+(const date &dt) const;
        date operator+(const int &skip_days) const;
        date operator-(const date &dt) const;
        date operator-(const int &skip_days) const;
        date &operator+=(const date &dt);
        date &operator+=(const int &skip_days);
        date &operator-=(const date &dt);
        date &operator-=(const int &skip_days);
        date &operator=(const date &dt);
        date &operator=(date &&dt) noexcept;
        bool operator>(const date &dt) const;
        bool operator<(const date &dt) const;
        bool operator>=(const date &dt) const;
        bool operator<=(const date &dt) const;
        bool operator==(const date &dt) const;
        bool operator!=(const date &dt) const;
        ~date();
    };

    constexpr inline bool date::is_leap(const unsigned &y)
    {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
            return true;
        return false;
    }

    date::date()
    {
        std::time_t t = std::time(nullptr);
        struct std::tm *ct = std::localtime(&t);

        this->year = ct->tm_year + 1900;
        this->month = ct->tm_mon + 1;
        this->day = ct->tm_mday;
    }

    date::date(const date &dt)
    {
        this->year = dt.year;
        this->month = dt.month;
        this->day = dt.day;
    }

    date::date(date &&dt) noexcept
    {
        this->year = dt.year;
        this->month = dt.month;
        this->day = dt.day;
    }

    date::date(const unsigned &day_, const unsigned &month_, const unsigned &year_)
    {
        if (!this->is_leap(year_) && month_ == 2)
        {
            if (day_ >= 29)
            {
                std::fprintf(stderr, "err: %u is greater than or equal to 29 in the February month of a non-leap year (%u).\n", day_, year_);
                std::exit(EXIT_FAILURE);
            }
        }
        if (day_ > 31)
        {
            std::fprintf(stderr, "err: %u is a day and should not be greater than 31.\n", day_);
            std::exit(EXIT_FAILURE);
        }
        if (month_ > 12)
        {
            std::fprintf(stderr, "err: %u is a month and should not be greater than 12.\n", month_);
            std::exit(EXIT_FAILURE);
        }
        if (year_ < 1000 || year_ > 9999)
        {
            std::fprintf(stderr, "err: %u is a year and should be in-between 1000 and 9999.\n", year_);
            std::exit(EXIT_FAILURE);
        }

        std::tm i_tm = {};
        i_tm.tm_mday = day_;
        i_tm.tm_mon = month_;
        i_tm.tm_year = year_;
        std::mktime(&i_tm);

        this->day = i_tm.tm_mday;
        this->month = i_tm.tm_mon;
        this->year = i_tm.tm_year;
    }

    date::date(const openutils::sstring &str)
    {
        unsigned m = 0, d = 0, y = 0;
        vector_t<heap_pair<sstring, enum lexer_token>> parse = str.lexer();
        std::size_t n = 0;
        while (parse.get(n).second() != openutils::lexer_token::NULL_END)
        {
            if (parse.get(n).second() == openutils::lexer_token::INTEGER && n == 0)
            {
                d = std::strtoull(parse[n].first().c_str(), nullptr, 10);
                n++;
            }
            else
            {
                std::fprintf(stderr, "err: `%s` in `%s` should be a day (integer).\n", parse[n].first().c_str(), str.c_str());
                std::exit(EXIT_FAILURE);
            }
            if (parse.get(n).second() != openutils::lexer_token::SPECIAL_CHAR && n == 1)
            {
                std::fprintf(stderr, "err: `%s` in `%s` should be a separator between day and month.\n", parse[n].first().c_str(), str.c_str());
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
                std::fprintf(stderr, "err: `%s` in `%s` should be a month (integer).\n", parse[n].first().c_str(), str.c_str());
                std::exit(EXIT_FAILURE);
            }
            if (parse.get(n).second() != openutils::lexer_token::SPECIAL_CHAR && n == 3)
            {
                std::fprintf(stderr, "err: `%s` in `%s` should be a separator between month and year.\n", parse[n].first().c_str(), str.c_str());
                std::exit(EXIT_FAILURE);
            }
            else
                n++;
            if (parse.get(n).second() == openutils::lexer_token::INTEGER && n == 4)
            {
                y = std::strtoull(parse[n].first().c_str(), nullptr, 10);
                n++;
            }
            else
            {
                std::fprintf(stderr, "err: `%s` in `%s` should be a year (integer).\n", parse[n].first().c_str(), str.c_str());
                std::exit(EXIT_FAILURE);
            }
            if (parse.length() != n + 1)
            {
                std::fprintf(stderr, "err: `%s` in `%s` is exceeding the date format (DD/MM/YYYY).\n", parse[n].first().c_str(), str.c_str());
                std::exit(EXIT_FAILURE);
            }
        }
        *this = date(d, m, y);
    }

    int date::days_between(const date &dt) const
    {
        int n1 = this->year * 365 + this->day;
        for (unsigned i = 0; i < this->month - 1; i++)
            n1 += this->month_day_count[i];

        unsigned yrs = this->year;
        if (this->month <= 2)
            yrs--;
        n1 += (yrs / 4) - (yrs / 100) + (yrs / 400);

        int n2 = dt.year * 365 + dt.day;
        for (unsigned i = 0; i < dt.month - 1; i++)
            n2 += dt.month_day_count[i];

        unsigned yrs2 = dt.year;
        if (dt.month <= 2)
            yrs2--;
        n2 += (yrs2 / 4) - (yrs2 / 100) + (yrs2 / 400);

        return (n1 - n2);
    }

    unsigned date::days_beginning() const
    {
        unsigned os = this->day;
        switch (this->month - 1)
        {
        case 11:
            os += 30;
            break;
        case 10:
            os += 31;
            break;
        case 9:
            os += 30;
            break;
        case 8:
            os += 31;
            break;
        case 7:
            os += 31;
            break;
        case 6:
            os += 30;
            break;
        case 5:
            os += 31;
            break;
        case 4:
            os += 30;
            break;
        case 3:
            os += 31;
            break;
        case 2:
            os += 28;
            break;
        case 1:
            os += 31;
            break;
        }
        if (this->is_leap(this->year) && this->month > 2)
            os += 1;
        return os;
    }

    date &date::add(const date &dt)
    {
        unsigned long long int days_bw = this->days_between(dt);
        std::tm ti = {};
        ti.tm_year = this->year - 1900;
        ti.tm_mon = this->month - 1;
        ti.tm_mday = this->day;
        ti.tm_mday += days_bw;
        std::mktime(&ti);

        this->year = ti.tm_year + 1900;
        this->month = ti.tm_mon + 1;
        this->day = ti.tm_mday;

        return *this;
    }

    date &date::add(const int &skip_days)
    {
        std::tm ti = {};
        ti.tm_year = this->year - 1900;
        ti.tm_mon = this->month - 1;
        ti.tm_mday = this->day;
        ti.tm_mday += skip_days;
        std::mktime(&ti);

        this->year = ti.tm_year + 1900;
        this->month = ti.tm_mon + 1;
        this->day = ti.tm_mday;

        return *this;
    }

    date &date::substract(const date &dt)
    {
        unsigned long long int days_bw = this->days_between(dt);
        std::tm ti = {};
        ti.tm_year = this->year - 1900;
        ti.tm_mon = this->month - 1;
        ti.tm_mday = this->day;
        ti.tm_mday -= days_bw;
        std::mktime(&ti);

        this->year = ti.tm_year + 1900;
        this->month = ti.tm_mon + 1;
        this->day = ti.tm_mday;

        return *this;
    }

    date &date::substract(const int &skip_days)
    {
        std::tm ti = {};
        ti.tm_year = this->year - 1900;
        ti.tm_mon = this->month - 1;
        ti.tm_mday = this->day;
        ti.tm_mday -= skip_days;
        std::mktime(&ti);

        this->year = ti.tm_year + 1900;
        this->month = ti.tm_mon + 1;
        this->day = ti.tm_mday;

        return *this;
    }

    bool date::is_leap() const
    {
        return this->is_leap(this->year);
    }

    date date::get_ctime() const
    {
        date x = date();
        return x;
    }

    openutils::sstring date::to_string() const
    {
        openutils::sstring x;
        x.set_formatted(1024, "%u/%u/%u", this->day, this->month, this->year);
        return x;
    }

    date &date::swap(date &dt) noexcept
    {
        std::swap(this->year, dt.year);
        std::swap(this->month, dt.month);
        std::swap(this->day, dt.day);
        return *this;
    }

    std::size_t date::hash() const
    {
        std::size_t h1 = std::hash<unsigned>()(this->year);
        std::size_t h2 = std::hash<unsigned>()(this->month);
        std::size_t h3 = std::hash<unsigned>()(this->day);

        h1 ^= (h2 << 1) ^ (h3 << 2);
        return h1;
    }

    date date::operator+(const date &dt) const
    {
        date d = date(*this);
        d.add(dt);
        return d;
    }

    date date::operator+(const int &skip_days) const
    {
        date d = date(*this);
        d.add(skip_days);
        return d;
    }

    date date::operator-(const date &dt) const
    {
        date d = date(*this);
        d.substract(dt);
        return d;
    }

    date date::operator-(const int &skip_days) const
    {
        date d = date(*this);
        d.substract(skip_days);
        return d;
    }

    date &date::operator+=(const date &dt)
    {
        this->add(dt);
        return *this;
    }

    date &date::operator+=(const int &skip_days)
    {
        this->add(skip_days);
        return *this;
    }

    date &date::operator-=(const date &dt)
    {
        this->substract(dt);
        return *this;
    }

    date &date::operator-=(const int &skip_days)
    {
        this->substract(skip_days);
        return *this;
    }

    date &date::operator=(const date &dt)
    {
        if (this != &dt)
        {
            this->year = dt.year;
            this->month = dt.month;
            this->day = dt.day;
        }
        return *this;
    }

    date &date::operator=(date &&dt) noexcept
    {
        if (this != &dt)
        {
            this->year = dt.year;
            this->month = dt.month;
            this->day = dt.day;
        }
        return *this;
    }

    bool date::operator>(const date &dt) const
    {
        if (this->year > dt.year)
            return true;
        else if (this->year < dt.year)
            return false;
        else
        {
            if (this->month > dt.month)
                return true;
            else if (this->month < dt.month)
                return false;
            else
            {
                if (this->day > dt.day)
                    return true;
                else if (this->day < dt.day)
                    return false;
                else
                    return false;
            }
        }
    }

    bool date::operator<(const date &dt) const
    {
        if (this->year > dt.year)
            return false;
        else if (this->year < dt.year)
            return true;
        else
        {
            if (this->month > dt.month)
                return false;
            else if (this->month < dt.month)
                return true;
            else
            {
                if (this->day > dt.day)
                    return false;
                else if (this->day < dt.day)
                    return true;
                else
                    return false;
            }
        }
    }

    bool date::operator>=(const date &dt) const
    {
        if (this->year > dt.year)
            return true;
        else if (this->year < dt.year)
            return false;
        else
        {
            if (this->month > dt.month)
                return true;
            else if (this->month < dt.month)
                return false;
            else
            {
                if (this->day > dt.day)
                    return true;
                else if (this->day < dt.day)
                    return false;
                else
                    return true;
            }
        }
    }

    bool date::operator<=(const date &dt) const
    {
        if (this->year > dt.year)
            return false;
        else if (this->year < dt.year)
            return true;
        else
        {
            if (this->month > dt.month)
                return false;
            else if (this->month < dt.month)
                return true;
            else
            {
                if (this->day > dt.day)
                    return false;
                else if (this->day < dt.day)
                    return true;
                else
                    return true;
            }
        }
    }

    bool date::operator==(const date &dt) const
    {
        return ((this->year == dt.year) && (this->month == dt.month) && (this->day == dt.day));
    }

    bool date::operator!=(const date &dt) const
    {
        return ((this->year != dt.year) && (this->month != dt.month) && (this->day != dt.day));
    }

    date::~date() = default;
}

namespace std
{
    template <>
    struct hash<openutils::date>
    {
        std::size_t operator()(const openutils::date &d) const
        {
            return d.hash();
        }
    };
};

#endif