/**
  * @file sstring_lexer_split.hh
  * @brief This file contains definition of lexer and split functions. Do NOT directly include this file.
  * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
  * @version 3.0.0
  * @author Tushar Chaurasia (Dark-CodeX)
*/

#ifndef SSTRING_LEXER_SPLIT_DEFINED
#define SSTRING_LEXER_SPLIT_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename T>
    vector_t<sstring_t_view<T>> sstring_t_view<T>::split(const T *str) const
    {
        if (this->src && str)
        {
            if (str[0] == 0)
            {
                vector_t<sstring_t_view<T>> x(this->len);
                for (std::size_t i = 0; i < this->len; i++)
                    x.add(this->src[i]);
                return x;
            }
            T *temp = static_cast<T *>(std::calloc(this->len + 1, sizeof(T)));
            exit_heap_fail(temp);
            std::memmove(temp, this->src, this->len * sizeof(T));
            std::size_t str_len = this->sstr_strlen(str);
            T *tok = this->fast_strtok(temp, str, str_len);
            vector_t<sstring_t_view<T>> x;
            while (tok)
            {
                x.add(tok);
                tok = this->fast_strtok(nullptr, str, str_len);
                if (!tok)
                    break;
            }
            std::free(temp);
            return x;
        }
        return vector_t<sstring_t_view<T>>();
    }

    template <typename T>
    vector_t<sstring_t_view<T>> sstring_t_view<T>::split(const sstring_t_view<T> &str) const
    {
        return this->split(str.src);
    }

    template <typename T>
    vector_t<heap_pair<sstring_t_view<T>, enum lexer_token>> sstring_t_view<T>::lexer() const
    {
        vector_t<heap_pair<sstring_t_view<T>, enum lexer_token>> vec;
        sstring_t_view<T> toks;
        for (std::size_t i = 0; i < this->len;)
        {
            if ((this->src[i] >= 97 && this->src[i] <= 122) || (this->src[i] >= 65 && this->src[i] <= 90))
            {
                toks.clear();
                while ((this->src[i] >= 97 && this->src[i] <= 122) || (this->src[i] >= 65 && this->src[i] <= 90))
                    toks.append_char(this->src[i++]);
                vec.add({toks, lexer_token::WORD});
            }
            else if (this->src[i] == 32)
            {
                toks.clear();
                toks.append_char(this->src[i++]);
                vec.add({toks, lexer_token::WHITESPACE});
            }
            else if (std::isdigit(this->src[i]))
            {
                toks.clear();
                while (std::isdigit(this->src[i]))
                    toks.append_char(this->src[i++]);
                vec.add({toks, lexer_token::INTEGER});
            }
            else if (this->src[i] == 92 || this->src[i] == 7 || this->src[i] == 8 || this->src[i] == 12 || this->src[i] == 10 || this->src[i] == 13 || this->src[i] == 9 || this->src[i] == 11 || this->src[i] == 34 || this->src[i] == 39 || this->src[i] == 63)
            {
                toks.clear();
                while (this->src[i] == 92 || this->src[i] == 7 || this->src[i] == 8 || this->src[i] == 12 || this->src[i] == 10 || this->src[i] == 13 || this->src[i] == 9 || this->src[i] == 11 || this->src[i] == 34 || this->src[i] == 39 || this->src[i] == 63)
                {
                    toks.clear();
                    toks.set_char(this->src[i++]);
                    vec.add({toks, lexer_token::ESC_SEQ});
                }
            }
            else if ((this->src[i] == 33) || (this->src[i] >= 35 && this->src[i] <= 38) || (this->src[i] >= 40 && this->src[i] <= 47) || (this->src[i] >= 58 && this->src[i] <= 62) || (this->src[i] == 64) || (this->src[i] == 91) || (this->src[i] >= 93 && this->src[i] <= 96) || (this->src[i] >= 123 && this->src[i] <= 126))
            {
                toks.clear();
                while ((this->src[i] == 33) || (this->src[i] >= 35 && this->src[i] <= 38) || (this->src[i] >= 40 && this->src[i] <= 47) || (this->src[i] >= 58 && this->src[i] <= 62) || (this->src[i] == 64) || (this->src[i] == 91) || (this->src[i] >= 93 && this->src[i] <= 96) || (this->src[i] >= 123 && this->src[i] <= 126))
                {
                    toks.clear();
                    toks.set_char(this->src[i++]);
                    vec.add({toks, lexer_token::SPECIAL_CHAR});
                }
            }
            else
            {
                toks.clear();
                while (!(this->src[i] > 0 && this->src[i] <= 127)) // while (not ascii) -> for non ascii characters
                    toks.append_char(this->src[i++]);
                vec.add({toks, lexer_token::WORD});
            }
        }
        vec.add({sstring_t_view<T>(), lexer_token::NULL_END});
        return vec;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::from_lexer(const vector_t<heap_pair<sstring_t_view<T>, enum lexer_token>> &toks)
    {
        if (toks.length() != 0)
        {
            if (this->src)
                std::free(this->src);
            this->len = 0;

            std::size_t buff_len = 0;
            for (std::size_t i = 0; i < toks.length(); i++)
                buff_len += toks[i].first().len;

            this->src = static_cast<T *>(std::calloc(buff_len + 1, sizeof(T)));
            exit_heap_fail(this->src);

            for (std::size_t i = 0; i < toks.length(); i++)
                this->fast_strncat(this->src, toks[i].first().src, this->len);
        }
        return *this;
    }

    template <typename T>
    vector_t<sstring_t_view<T>> sstring_t_view<T>::to_argv(const T *argv0) const
    {
        if (!this->src)
            return vector_t<sstring_t_view<T>>();

        vector_t<sstring_t_view<T>> args;
        if (argv0)
            args.add(argv0);
        sstring_t_view<T> arg;
        bool in_quotes = false;

        for (size_t i = 0; i < this->len; i++)
        {
            T c = this->src[i];
            if (c == 34)
                in_quotes = !in_quotes;
            else if (c == 32 && !in_quotes)
            {
                if (!arg.is_empty())
                {
                    args.add(arg);
                    arg.clear();
                }
            }
            else if (c == 92)
            {
                if (in_quotes && i + 1 < this->len)
                    arg.append_char(this->src[++i]);
            }
            else
                arg.append_char(c);
        }
        if (!arg.is_empty())
            args.add(arg);

        return args;
    }
}

#endif