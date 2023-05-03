#ifndef SSTRING_CONVERSION_DEFINED
#define SSTRING_CONVERSION_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename TO, typename FROM>
    sstring_t_view<TO> static convert_sstring(const FROM *frm)
    {
        if (!frm)
            return nullptr;
#if __cplusplus >= 201703L
        if (std::is_same<TO, FROM>::value == true) // require C++17
            return (TO *)frm;
#endif

        sstring_t_view<TO> to;
        std::size_t frm_len = sstring_t_view<FROM>::sstr_strlen(frm);
        TO *buff = static_cast<TO *>(std::calloc(frm_len + 1, sizeof(TO)));
        exit_heap_fail(buff);

        for (std::size_t i = 0; i < frm_len; i++)
            buff[i] = static_cast<TO>(frm[i]);

        to.get() = buff;
        to.change_length(frm_len);

        return to;
    }

    template <typename TO, typename FROM>
    sstring_t_view<TO> static convert_sstring(const sstring_t_view<FROM> &frm)
    {
        return convert_sstring(frm.c_str());
    }
}

#endif