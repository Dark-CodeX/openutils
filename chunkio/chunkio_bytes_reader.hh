/**
 * @file chunkio_bytes_reader.hh
 * @brief This file contains declaration and definition chunkio_bytes_reader class.
 * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
 * @version 1.0.0
 * @author Tushar Chaurasia (Dark-CodeX)
 */

#ifndef CHUNKIO_BYTES_READER_DEFINED
#define CHUNKIO_BYTES_READER_DEFINED

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
    class chunkio_bytes_reader
    {
    private:
        std::FILE *fptr;
        std::size_t bytes;
        T *ptr_data;

    public:
        chunkio_bytes_reader();
        chunkio_bytes_reader(const char *loc, std::size_t bytes_to_read);
        T *&read_next();
        bool file_exists() const;
        ~chunkio_bytes_reader();
    };

    template <typename T>
    chunkio_bytes_reader<T>::chunkio_bytes_reader()
    {
        this->fptr = nullptr;
        this->ptr_data = nullptr;
        this->bytes = 0;
    }

    template <typename T>
    chunkio_bytes_reader<T>::chunkio_bytes_reader(const char *loc, std::size_t bytes_to_read)
    {
        if (loc)
        {
            this->fptr = std::fopen(loc, "rb"); // just for reading
            if (!this->fptr)
            {
                this->fptr = nullptr;
                this->ptr_data = nullptr;
                this->bytes = 0;
            }
            else
            {
                this->ptr_data = nullptr;
                this->bytes = bytes_to_read;

                std::fseek(this->fptr, 0, SEEK_SET);
            }
        }
        else
        {
            this->fptr = nullptr;
            this->ptr_data = nullptr;
            this->bytes = 0;
        }
    }

    template <typename T>
    T *&chunkio_bytes_reader<T>::read_next()
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

            this->ptr_data = static_cast<T *>(std::malloc((this->bytes + 1) * sizeof(T)));
            exit_heap_fail(this->ptr_data);

            std::size_t where_end = std::fread(this->ptr_data, sizeof(T), this->bytes, this->fptr);
            this->ptr_data[where_end] = 0;
        }
        return this->ptr_data;
    }

    template <typename T>
    bool chunkio_bytes_reader<T>::file_exists() const
    {
        return this->fptr != nullptr;
    }

    template <typename T>
    chunkio_bytes_reader<T>::~chunkio_bytes_reader()
    {
        if (this->fptr)
            std::fclose(fptr);
        if (this->ptr_data)
            std::free(this->ptr_data);
        this->bytes = 0;
    }
}

#endif