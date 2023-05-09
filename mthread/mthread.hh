/**
 * @file mthread.hh
 * @brief This file contains declaration and definition mthread class.
 * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
 * @version 1.0.0
 * @author Tushar Chaurasia (Dark-CodeX)
 */

#ifndef MTHREAD_DEFINED
#define MTHREAD_DEFINED

#define mthread_version "1.0.0"

#include <cstdio>
#include <cstdlib>
#include <thread>
#include <functional>
#include <openutils/vector/vector.hh>

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

    template <typename return_type, typename... args>
    class mthread
    {
    private:
        vector_t<return_type> ret_val;
        vector_t<std::thread> threads;

    public:
        /**
         * @brief Give your vector of functions and its respective arguments (if you want).
         * @param functions vector of functions
         * @param a vector of arguments
         */
        void execute_processes(const vector_t<std::function<return_type(args...)>> &functions, const vector_t<args> &...a);

        /**
         * @brief Returns the final value from each function, the values are in the same order as of `functions`.
         * @brief NOTE: If your function returns `void` (nothing), you must used `return_type` as `void *` and you MAY return `nullptr` from the respective function.
         * @return vector of results
         */
        const vector_t<return_type> &get() const;

        /**
         * @brief Returns the final value from each function, the values are in the same order as of `functions`.
         * @brief NOTE: If your function returns `void` (nothing), you must used `return_type` as `void *` and you MAY return `nullptr` from the respective function.
         * @return vector of results
         */
        vector_t<return_type> &get();

        /**
         * @brief NOTE: That this is not necessarily the maximum limit, as the operating system or runtime environment might impose additional restrictions.
         * @return number of maximum threads per process
         */
        static unsigned int max_threads() noexcept;
    };

    template <typename return_type, typename... args>
    void mthread<return_type, args...>::execute_processes(const vector_t<std::function<return_type(args...)>> &functions, const vector_t<args> &...a)
    {
        vector_t<return_type> r(functions.length());
        this->threads = vector_t<std::thread>(functions.length());

        for (std::size_t i = 0; i < functions.length(); i++)
        {
            this->threads.add(std::thread([i, &r, &functions, &a...]()
                                          { r.add(functions[i](a[i]...)); }));
        }

        for (std::size_t i = 0; i < this->threads.length(); i++)
        {
            this->threads[i].join();
        }

        this->ret_val.swap(r);
    }

    template <typename return_type, typename... args>
    const vector_t<return_type> &mthread<return_type, args...>::get() const
    {
        return this->ret_val;
    }

    template <typename return_type, typename... args>
    vector_t<return_type> &mthread<return_type, args...>::get()
    {
        return this->ret_val;
    }

    template <typename return_type, typename... args>
    unsigned int mthread<return_type, args...>::max_threads() noexcept
    {
        return std::thread::hardware_concurrency();
    }
}

#endif