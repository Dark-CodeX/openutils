/**
 * @file chunkio_writer.hh
 * @brief This file contains declaration and definition chunkio_writer class.
 * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
 * @version 1.0.0
 * @author Tushar Chaurasia (Dark-CodeX)
 */

#ifndef OPENUTILS_CHUNKIO_WRITER_DEFINED
#define OPENUTILS_CHUNKIO_WRITER_DEFINED

#define OPENUTILS_chunkio_version "1.0.0"

#include <cstdio>

namespace openutils
{
    template <typename T>
    class chunkio_writer
    {
    private:
        std::FILE *fptr;

    public:
        chunkio_writer();
        chunkio_writer(const char *loc);
        bool save_next(const T *data, std::size_t n = 1) const;
        bool file_created() const;
        ~chunkio_writer();
    };

    template <typename T>
    chunkio_writer<T>::chunkio_writer()
    {
        this->fptr = nullptr;
    }

    template <typename T>
    chunkio_writer<T>::chunkio_writer(const char *loc)
    {
        if (loc)
        {
            this->fptr = std::fopen(loc, "wb");
            if (!this->fptr)
                this->fptr = nullptr;
        }
        else
            this->fptr = nullptr;
    }

    template <typename T>
    bool chunkio_writer<T>::save_next(const T *data, std::size_t n) const
    {
        if (!data || !this->fptr)
            return false;
        if (std::fwrite(data, sizeof(T), n, this->fptr) == 0)
            return false;
        return true;
    }

    template <typename T>
    bool chunkio_writer<T>::file_created() const
    {
        return this->fptr != nullptr;
    }

    template <typename T>
    chunkio_writer<T>::~chunkio_writer()
    {
        if (this->fptr)
            std::fclose(this->fptr);
    }
}

#endif