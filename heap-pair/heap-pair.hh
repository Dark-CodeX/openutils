/**
 * @file heap-pair.hh
 * @brief This file contains declaration as well as definition of heap_pair class.
 * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
 * @version 1.2.0
 * @author Tushar Chaurasia (Dark-CodeX)
 */

#ifndef HEAP_PAIR_DEFINED
#define HEAP_PAIR_DEFINED

#include <cstdio>
#include <cstdlib>
#include <utility>
#include <functional>

#define heap_pair_version "1.2.0"

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

    template <typename FIRST, typename SECOND>
    class heap_pair
    {
    private:
        FIRST *t1;
        SECOND *t2;
        static inline std::size_t hash_combine(const FIRST &fir, const SECOND &sec);

    public:
        heap_pair();
        heap_pair(const FIRST &T1, const SECOND &T2);
        heap_pair(FIRST &&T1, SECOND &&T2);
        heap_pair(const heap_pair &pair);
        heap_pair(heap_pair &&pair) noexcept;
        const FIRST &first() const;
        const SECOND &second() const;
        FIRST &first();
        SECOND &second();
        std::size_t hash() const;
        bool compare(const heap_pair &hp) const;
        bool compare_hash(const heap_pair &hp) const;
        heap_pair &swap(heap_pair &hp) noexcept;
        bool operator==(const heap_pair &hp) const;
        bool operator!=(const heap_pair &hp) const;
        heap_pair &operator=(const heap_pair &pair);
        heap_pair &operator=(heap_pair &&pair) noexcept;
        ~heap_pair();

        static heap_pair make_heap_pair(const FIRST &T1, const SECOND &T2);
        static heap_pair make_heap_pair(FIRST &&T1, SECOND &&T2);
    };

    template <typename FIRST, typename SECOND>
    inline std::size_t heap_pair<FIRST, SECOND>::hash_combine(const FIRST &fir, const SECOND &sec)
    {
        std::size_t seed = 0;
        seed ^= std::hash<FIRST>()(fir) + static_cast<std::size_t>(0xc70f6907UL) + (seed << 7) + (seed >> 3);
        seed ^= std::hash<SECOND>()(sec) + static_cast<std::size_t>(0xc70f6907UL) + (seed << 7) + (seed >> 3);
        return seed;
    }

    template <typename FIRST, typename SECOND>
    heap_pair<FIRST, SECOND>::heap_pair()
    {
        this->t1 = nullptr;
        this->t2 = nullptr;
    }

    template <typename FIRST, typename SECOND>
    heap_pair<FIRST, SECOND>::heap_pair(const FIRST &T1, const SECOND &T2)
    {
        this->t1 = new FIRST(T1);
        exit_heap_fail(this->t1);
        this->t2 = new SECOND(T2);
        exit_heap_fail(this->t2);
    }

    template <typename FIRST, typename SECOND>
    heap_pair<FIRST, SECOND>::heap_pair(FIRST &&T1, SECOND &&T2)
    {
        this->t1 = new FIRST(std::move(T1));
        exit_heap_fail(this->t1);
        this->t2 = new SECOND(std::move(T2));
        exit_heap_fail(this->t2);
    }

    template <typename FIRST, typename SECOND>
    heap_pair<FIRST, SECOND>::heap_pair(const heap_pair &pair)
    {
        if (pair.t1 && pair.t2)
        {
            this->t1 = new FIRST(*pair.t1);
            exit_heap_fail(this->t1);
            this->t2 = new SECOND(*pair.t2);
            exit_heap_fail(this->t2);
        }
        else
        {
            this->t1 = nullptr;
            this->t2 = nullptr;
        }
    }

    template <typename FIRST, typename SECOND>
    heap_pair<FIRST, SECOND>::heap_pair(heap_pair &&pair) noexcept
    {
        this->t1 = pair.t1;
        this->t2 = pair.t2;

        pair.t1 = nullptr;
        pair.t2 = nullptr;
    }

    template <typename FIRST, typename SECOND>
    const FIRST &heap_pair<FIRST, SECOND>::first() const
    {
        if (!this->t1)
        {
            std::fprintf(stderr, "err: cannot de-reference a null-pointer\n");
            std::exit(EXIT_FAILURE);
        }
        return *this->t1;
    }

    template <typename FIRST, typename SECOND>
    const SECOND &heap_pair<FIRST, SECOND>::second() const
    {
        if (!this->t2)
        {
            std::fprintf(stderr, "err: cannot de-reference a null-pointer\n");
            std::exit(EXIT_FAILURE);
        }
        return *this->t2;
    }

    template <typename FIRST, typename SECOND>
    FIRST &heap_pair<FIRST, SECOND>::first()
    {
        if (!this->t1)
        {
            std::fprintf(stderr, "err: cannot de-reference a null-pointer\n");
            std::exit(EXIT_FAILURE);
        }
        return *this->t1;
    }

    template <typename FIRST, typename SECOND>
    SECOND &heap_pair<FIRST, SECOND>::second()
    {
        if (!this->t2)
        {
            std::fprintf(stderr, "err: cannot de-reference a null-pointer\n");
            std::exit(EXIT_FAILURE);
        }
        return *this->t2;
    }

    template <typename FIRST, typename SECOND>
    std::size_t heap_pair<FIRST, SECOND>::hash() const
    {
        if (this->t1 && this->t2)
            return this->hash_combine(*this->t1, *this->t2);
        else
            return 0;
    }

    template <typename FIRST, typename SECOND>
    bool heap_pair<FIRST, SECOND>::compare(const heap_pair<FIRST, SECOND> &hp) const
    {
        if (this->t1 && this->t2 && hp.t1 && hp.t2)
        {
            return (*this->t1 == *hp.t1) && (*this->t2 == *hp.t2);
        }
        return false;
    }

    template <typename FIRST, typename SECOND>
    bool heap_pair<FIRST, SECOND>::compare_hash(const heap_pair<FIRST, SECOND> &hp) const
    {
        return this->hash() == hp.hash();
    }

    template <typename FIRST, typename SECOND>
    heap_pair<FIRST, SECOND> &heap_pair<FIRST, SECOND>::swap(heap_pair<FIRST, SECOND> &hp) noexcept
    {
        FIRST *temp_first = this->t1;
        this->t1 = hp.t1;
        hp.t1 = temp_first;

        SECOND *temp_second = this->t2;
        this->t2 = hp.t2;
        hp.t2 = temp_second;
        return *this;
    }

    template <typename FIRST, typename SECOND>
    bool heap_pair<FIRST, SECOND>::operator==(const heap_pair<FIRST, SECOND> &hp) const
    {
        return this->compare(hp);
    }

    template <typename FIRST, typename SECOND>
    bool heap_pair<FIRST, SECOND>::operator!=(const heap_pair<FIRST, SECOND> &hp) const
    {
        return !this->compare(hp);
    }

    template <typename FIRST, typename SECOND>
    heap_pair<FIRST, SECOND> &heap_pair<FIRST, SECOND>::operator=(const heap_pair &pair)
    {
        if (this != &pair)
        {
            if (pair.t1 && pair.t2)
            {
                if (this->t1 && this->t2)
                {
                    delete this->t1;
                    delete this->t2;
                }
                this->t1 = new FIRST(*pair.t1);
                exit_heap_fail(this->t1);
                this->t2 = new SECOND(*pair.t2);
                exit_heap_fail(this->t2);
            }
        }
        return *this;
    }

    template <typename FIRST, typename SECOND>
    heap_pair<FIRST, SECOND> &heap_pair<FIRST, SECOND>::operator=(heap_pair &&pair) noexcept
    {
        if (this != &pair)
        {
            if (pair.t1 && pair.t2)
            {
                if (this->t1 && this->t2)
                {
                    delete this->t1;
                    delete this->t2;
                }
                this->t1 = pair.t1;
                this->t2 = pair.t2;

                pair.t1 = nullptr;
                pair.t2 = nullptr;
            }
        }
        return *this;
    }

    template <typename FIRST, typename SECOND>
    heap_pair<FIRST, SECOND>::~heap_pair()
    {
        if (this->t1 && this->t2)
        {
            delete this->t1;
            delete this->t2;
        }
    }

    template <typename FIRST, typename SECOND>
    heap_pair<FIRST, SECOND> heap_pair<FIRST, SECOND>::make_heap_pair(const FIRST &T1, const SECOND &T2)
    {
        return heap_pair<FIRST, SECOND>(T1, T2);
    }

    template <typename FIRST, typename SECOND>
    heap_pair<FIRST, SECOND> heap_pair<FIRST, SECOND>::make_heap_pair(FIRST &&T1, SECOND &&T2)
    {
        return heap_pair<FIRST, SECOND>(std::move(T1), std::move(T2));
    }
}

namespace std
{
    template <typename FIRST, typename SECOND>
    struct hash<openutils::heap_pair<FIRST, SECOND>>
    {
        std::size_t operator()(const openutils::heap_pair<FIRST, SECOND> &__pair) const
        {
            return __pair.hash();
        }
    };
};

#endif
