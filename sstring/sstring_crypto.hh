#ifndef SSTRING_CRYPTO_DEFINED
#define SSTRING_CRYPTO_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::encrypt(const T *key)
    {
        if (key && this->src)
        {
            std::size_t val = sstring_t_view(key).hash() % 128;
            bool add = true;

            T *buff = static_cast<T *>(std::calloc(this->len + 1, sizeof(T)));
            exit_heap_fail(buff);

            for (std::size_t i = 0; this->src[i] != 0; i++)
            {
                if (add == true && this->src[i] + val > 0)
                {
                    buff[i] = this->src[i] + val;
                    add = false;
                }
                else if (add == false && this->src[i] - val > 0)
                {
                    buff[i] = this->src[i] - val;
                    add = true;
                }
                else
                {
                    std::free(buff);
                    return *this;
                }
            }

            std::free(this->src);
            this->src = buff; // now this->len does not changes
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::encrypt(const sstring_t_view<T> &key)
    {
        return this->encrypt(key.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::decrypt(const T *key)
    {
        if (key && this->src)
        {
            std::size_t val = sstring_t_view(key).hash() % 128;
            bool add_invr = true;

            T *buff = static_cast<T *>(std::calloc(this->len + 1, sizeof(T)));
            exit_heap_fail(buff);

            for (std::size_t i = 0; this->src[i] != 0; i++)
            {
                if (add_invr == true && this->src[i] + val > 0)
                {
                    buff[i] = this->src[i] - val;
                    add_invr = false;
                }
                else if (add_invr == false && this->src[i] - val > 0)
                {
                    buff[i] = this->src[i] + val;
                    add_invr = true;
                }
                else
                {
                    std::free(buff);
                    return *this;
                }
            }

            std::free(this->src);
            this->src = buff; // now this->len does not changes
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::decrypt(const sstring_t_view<T> &key)
    {
        return this->decrypt(key.src);
    }

    template <typename T>
    sstring_t_view<char> sstring_t_view<T>::encode_base64() const
    {
        if (this->src)
        {
            // some temps
            const T *temp_src = this->src;
            std::size_t temp_len = this->len;
            // end temps

            const char *base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
            sstring_t_view<char> ret;
            std::size_t i = 0, j = 0;
            unsigned char char_array_3[3] = {}, char_array_4[4] = {};

            while (temp_len--)
            {
                char_array_3[i++] = *(temp_src++);
                if (i == 3)
                {
                    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
                    char_array_4[3] = char_array_3[2] & 0x3f;

                    for (i = 0; i < 4; i++)
                        ret += base64_chars[char_array_4[i]];
                    i = 0;
                }
            }

            if (i)
            {
                for (j = i; j < 3; j++)
                    char_array_3[j] = 0;

                char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
                char_array_4[3] = char_array_3[2] & 0x3f;

                for (j = 0; j < i + 1; j++)
                    ret += base64_chars[char_array_4[j]];

                while (i++ < 3)
                    ret += '=';
            }

            return ret;
        }
        return nullptr;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::decode_base64(const char *encoded) const
    {
        if (this->src)
        {
            // some temps
            std::size_t temp_len = sstring_t_view<char>::sstr_strlen(encoded);
            const char *encoded_string = encoded;
            // end temp

            const sstring_t_view<char> base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

            std::size_t i = 0, j = 0, in_ = 0;
            unsigned char char_array_4[4] = {}, char_array_3[3] = {};
            sstring_t_view<T> ret;

            while (temp_len-- && (encoded_string[in_] != 61) && (std::isalnum(encoded_string[in_]) || (encoded_string[in_] == 43) || (encoded_string[in_] == 47)))
            {
                char_array_4[i++] = encoded_string[in_];
                in_++;
                if (i == 4)
                {
                    for (i = 0; i < 4; i++)
                        char_array_4[i] = static_cast<unsigned char>(base64_chars.find(char_array_4[i]));

                    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
                    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
                    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
                    for (i = 0; i < 3; i++)
                        ret += static_cast<T>(char_array_3[i]);
                    i = 0;
                }
            }

            if (i)
            {
                for (j = i; j < 4; j++)
                    char_array_4[j] = 0;

                for (j = 0; j < 4; j++)
                    char_array_4[j] = static_cast<unsigned char>(base64_chars.find(char_array_4[j]));

                char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
                char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
                char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

                for (j = 0; j < i - 1; j++)
                    ret += static_cast<T>(char_array_3[j]);
            }

            return ret;
        }
        return nullptr;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::decode_base64(const sstring_t_view<char> &encoded) const
    {
        return this->decode_base64(encoded.c_str());
    }
}

#endif