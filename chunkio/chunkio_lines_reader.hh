/**
 * @file chunkio_lines_reader.hh
 * @brief This file contains declaration and definition chunkio_lines_reader class.
 * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
 * @version 1.0.0
 * @author Tushar Chaurasia (Dark-CodeX)
 */

#ifndef CHUNKIO_LINES_READER_DEFINED
#define CHUNKIO_LINES_READER_DEFINED

#define chunkio_version "1.0.0"

#include <cstdlib>
#include <cstdio>
#include <cstring>

namespace openutils
{
#ifndef EXIT_HEAP_FAIL
#define EXIT_HEAP_FAIL
    static inline void exit_heap_fail(const void *ptr)
    {
        if (!ptr)
        {
            std::fprintf(stderr, "err: can't allocate heap memory.\n");
            std::exit(EXIT_FAILURE);
        }
    }
#endif

    /**
     * @brief NOTE: If `T` is `void`, it is recommended to use `void *` instead
     */
    template <typename T>
    class chunkio_lines_reader
    {
    private:
        std::FILE *fptr;
        std::size_t lines;
        T *ptr_data;

    public:
        chunkio_lines_reader();
        chunkio_lines_reader(const char *loc, std::size_t lines_to_read);
        T *&read_next();
        bool file_exists() const;
        ~chunkio_lines_reader();
    };

    template <typename T>
    chunkio_lines_reader<T>::chunkio_lines_reader()
    {
        this->fptr = nullptr;
        this->lines = 0;
        this->ptr_data = nullptr;
    }

    template <typename T>
    chunkio_lines_reader<T>::chunkio_lines_reader(const char *loc, std::size_t lines_to_read)
    {
        if (loc)
        {
            this->fptr = std::fopen(loc, "rb"); // just for reading
            if (!this->fptr)
            {
                this->fptr = nullptr;
                this->ptr_data = nullptr;
                this->lines = 0;
            }
            else
            {
                this->ptr_data = nullptr;
                this->lines = lines_to_read;

                std::fseek(this->fptr, 0, SEEK_SET);
            }
        }
        else
        {
            this->fptr = nullptr;
            this->ptr_data = nullptr;
            this->lines = 0;
        }
    }

    template <typename T>
    T *&chunkio_lines_reader<T>::read_next()
    {
        if (this->fptr)
        {
            if (std::feof(this->fptr))
            {
                if (this->ptr_data)
                    std::free(this->ptr_data);
                this->ptr_data = nullptr;
                return this->ptr_data;
            }

            if (this->ptr_data)
                std::free(this->ptr_data);

            std::size_t curr_line = 0, cap = 64, len = 0;
            this->ptr_data = static_cast<T *>(std::malloc(cap * sizeof(T)));
            exit_heap_fail(this->ptr_data);

            while (!std::feof(this->fptr) && curr_line != this->lines)
            {
                std::fread(this->ptr_data + len, sizeof(T), 1, this->fptr);
                if (this->ptr_data[len] == 10)
                    curr_line++;
                len++;
                if (len == cap)
                {
                    cap *= 2;
                    this->ptr_data = static_cast<T *>(std::realloc(this->ptr_data, cap));
                    exit_heap_fail(this->ptr_data);
                }
                this->ptr_data[len] = 0;
            }
        }
        return this->ptr_data;
    }

    template <typename T>
    bool chunkio_lines_reader<T>::file_exists() const
    {
        return this->fptr != nullptr;
    }

    template <typename T>
    chunkio_lines_reader<T>::~chunkio_lines_reader()
    {
        if (this->fptr)
            std::fclose(fptr);
        if (this->ptr_data)
            std::free(this->ptr_data);
        this->lines = 0;
    }
}

#endif