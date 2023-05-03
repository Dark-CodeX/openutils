/**
  * @file sstring_metrics.hh
  * @brief This file contains definition of metrics calculation functions. Do NOT directly include this file.
  * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
  * @version 3.0.0
  * @author Tushar Chaurasia (Dark-CodeX)
*/

#ifndef SSTRING_METRICS_DEFINED
#define SSTRING_METRICS_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename T>
    int sstring_t_view<T>::lexicographical_comparison(const T *str) const
    {
        if (!this->src)
            return this->len - this->sstr_strlen(str);
        std::size_t str_len = 0;
        for (std::size_t i = 0; this->src[i] && str[str_len]; i++, str_len++)
        {
            if (this->src[i] == str[i])
                continue;
            return (int)this->src[i] - (int)str[i];
        }
        return this->len - str_len;
    }

    template <typename T>
    int sstring_t_view<T>::lexicographical_comparison(const sstring_t_view<T> &str) const
    {
        return this->lexicographical_comparison(str.src);
    }

    template <typename T>
    double sstring_t_view<T>::entropy() const
    {
        if (this->src)
        {
            std::unordered_map<T, std::size_t> freq;
            for (std::size_t i = 0; i < this->len; i++)
                freq[this->src[i]] += 1;

            double result = 0;
            for (const auto &[key, value] : freq)
            {
                double f1 = static_cast<double>(value) / static_cast<double>(this->len);
                result -= f1 * (std::log(f1) / std::log(2.0));
            }
            return result;
        }
        return -1;
    }

    template <typename T>
    double sstring_t_view<T>::password_entropy() const
    {
        if (!this->src)
            return 0;
        // formula = E = L * log2(R)
        std::size_t R = 0;
        //					  0      1      2      3         4
        // 					digit, lower, upper, special, other_ascii
        bool is_added[5] = {false, false, false, false, false};

        for (std::size_t i = 0; i < this->len; i++)
        {
            if (std::isdigit(this->src[i]))
            {
                if (is_added[0] == false)
                {
                    R += 10;
                    is_added[0] = true;
                }
            }
            else if (std::islower(this->src[i]))
            {
                if (is_added[1] == false)
                {
                    R += 26;
                    is_added[1] = true;
                }
            }
            else if (std::isupper(this->src[i]))
            {
                if (is_added[2] == false)
                {
                    R += 26;
                    is_added[2] = true;
                }
            }
            else if ((this->src[i] >= 32 && this->src[i] <= 47) || (this->src[i] >= 58 && this->src[i] <= 64) || (this->src[i] >= 91 && this->src[i] <= 96) || (this->src[i] >= 123 && this->src[i] < 127))
            {
                if (is_added[3] == false)
                {
                    R += 33;
                    is_added[3] = true;
                }
            }
            else
            {
                if (is_added[4] == false)
                {
                    R += 33;
                    is_added[4] = true;
                }
            }
        }
        return (double)this->len * std::log2(R);
    }

    template <typename T>
    std::size_t sstring_t_view<T>::distance(const T *str) const
    {
        if (str && this->src)
        {
            if (this->sstr_strlen(src) == this->len)
            {
                std::size_t cnt = 0;
                for (std::size_t i = 0; this->src[i] != 0; i++)
                    if (this->src[i] != str[i])
                        cnt++;
                return cnt;
            }
        }
        return this->nerr();
    }

    template <typename T>
    std::size_t sstring_t_view<T>::distance(const sstring_t_view<T> &str) const
    {
        return this->distance(str.src);
    }

#ifndef MIN3
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#endif

    template <typename T>
    std::size_t sstring_t_view<T>::edit_distance(const T *str) const
    {
        if (str && this->src)
        {
            std::size_t len_str = this->sstr_strlen(str), x, y, last, old;
            std::size_t *cols = static_cast<std::size_t *>(std::calloc(this->len + 1, sizeof(std::size_t)));
            exit_heap_fail(cols);
            for (y = 1; y <= this->len; y++)
                cols[y] = y;
            for (x = 1; x <= len_str; x++)
            {
                cols[0] = x;
                for (y = 1, last = x - 1; y <= this->len; y++)
                {
                    old = cols[y];
                    cols[y] = MIN3(cols[y] + 1, cols[y - 1] + 1, last + (this->src[y - 1] == str[x - 1] ? 0 : 1));
                    last = old;
                }
            }
            std::size_t r = cols[this->len];
            std::free(cols);
            return r;
        }
        return this->nerr();
    }

    template <typename T>
    std::size_t sstring_t_view<T>::edit_distance(const sstring_t_view<T> &str) const
    {
        return this->edit_distance(str.src);
    }

    template <typename T>
    double sstring_t_view<T>::percentage_matched(const T *str) const
    {
        if (str && this->src)
        {
            std::size_t len_str = this->sstr_strlen(str);
            std::size_t max = ((this->len > len_str) ? this->len : len_str);
            std::size_t edit_dis = this->edit_distance(str);
            return (max - edit_dis) * 100.0 / max;
        }
        return -1;
    }

    template <typename T>
    double sstring_t_view<T>::percentage_matched(const sstring_t_view<T> &str) const
    {
        return this->percentage_matched(str.src);
    }

    template <typename T>
    std::size_t sstring_t_view<T>::count(const T *what) const
    {
        if (what && this->src)
        {
            std::size_t cnt = 0, what_len = this->sstr_strlen(what);
            const T *sub = this->src;
            while ((sub = this->fast_strstr(sub, this->sstr_strlen(sub), what)))
            {
                cnt++;
                sub += what_len;
            }
            return cnt;
        }
        return 0;
    }

    template <typename T>
    std::size_t sstring_t_view<T>::count(const sstring_t_view<T> &what) const
    {
        return this->count(what.src);
    }

    template <typename T>
    std::size_t sstring_t_view<T>::count_char(const T what) const
    {
        if (what != 0 && this->src)
        {
            std::size_t cnt = 0;
            for (std::size_t i = 0; this->src[i] != 0; i++)
                if (this->src[i] == what)
                    cnt++;
            return cnt;
        }
        return 0;
    }

    template <typename T>
    sstring_t_view<char> sstring_t_view<T>::soundex() const
    {
        if (this->src)
        {
            std::size_t s = 1;
            const char *map = "01230120022455012623010202"; // not stored in heap memory, do not free it
            T c;
            char res[5] = {};
            res[0] = std::toupper(this->src[0]);
            for (std::size_t i = 1; i < this->len; ++i)
            {
                c = std::toupper(this->src[i]) - 65;
                if (c >= 0 && c <= 25) // from ASCII table
                {
                    if (map[static_cast<std::size_t>(c)] != 0)
                    {
                        if (map[static_cast<std::size_t>(c)] != res[s - 1])
                        {
                            res[s] = map[static_cast<std::size_t>(c)];
                            s++;
                        }
                        if (s > 3)
                            break;
                    }
                }
            }
            if (s <= 3)
            {
                while (s <= 3)
                {
                    res[s] = '0';
                    s++;
                }
            }
            return sstring_t_view<char>(res);
        }
        return nullptr;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::most_used(const T *dl) const
    {
        if (dl && this->src)
        {
            sstring_t_view ret;
            vector_t<sstring_t_view<T>> vec = this->split(dl);
            std::unordered_map<sstring_t_view<T>, std::size_t> map;
            for (std::size_t i = 0; i < vec.length(); i++)
            {
                map[std::move(vec[i])] += 1;
            }
            vec.erase();

            std::size_t max = 0;
            for (auto &&[key, value] : map)
            {
                if (max < value)
                {
                    max = value;
                    ret = std::move(key);
                }
            }
            return ret;
        }
        return nullptr;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::most_used(const sstring_t_view<T> &dl) const
    {
        return this->most_used(dl.src);
    }

    template <typename T>
    T sstring_t_view<T>::most_used_char() const
    {
        if (this->src)
        {
            std::unordered_map<T, std::size_t> freq;
            for (std::size_t i = 0; i < this->len; i++)
                freq[this->src[i]] += 1;

            T _char_t_ = 0;
            std::size_t max = 0;
            for (const auto &[key, value] : freq)
            {
                if (max < value)
                {
                    max = value;
                    _char_t_ = key;
                }
            }
            return _char_t_;
        }
        return 0;
    }

    template <typename T>
    std::size_t sstring_t_view<T>::hash() const
    {
        std::size_t p = 53;
        std::size_t m = 1e9 + 9;
        long long power_of_p = 1;
        long long hash_val = 0;

        for (std::size_t i = 0; i < this->len; i++)
        {
            hash_val = (hash_val + (this->src[i] - 97 + 1) * power_of_p) % m;
            power_of_p = (power_of_p * p) % m;
        }
        return (hash_val % m + m) % m;
    }

    template <typename T>
    sstring_t_view<char> sstring_t_view<T>::hash_digest() const
    {
        std::size_t h = this->hash();
        sstring_t_view<char> digest = sstring_t_view<char>::to_sstring(h);
        digest = digest.encode_base64();
        return digest;
    }
}

#endif