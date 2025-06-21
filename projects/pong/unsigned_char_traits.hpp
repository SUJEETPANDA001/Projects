// unsigned_char_traits.hpp
#pragma once
#include <string>
#include <cstring>
#include <cstdint>
#include <streambuf>
#include <iosfwd>
#include <cwchar>
#include <cstddef>

namespace std {
    template <>
    struct char_traits<unsigned int> {
        using char_type = unsigned int;
        using int_type = std::uint_least32_t;
        using off_type = std::streamoff;
        using pos_type = std::u32streampos;
        using state_type = std::mbstate_t;

        static void assign(char_type& r, const char_type& a) noexcept { r = a; }
        static constexpr bool eq(char_type a, char_type b) noexcept { return a == b; }
        static constexpr bool lt(char_type a, char_type b) noexcept { return a < b; }

        static int compare(const char_type* s1, const char_type* s2, size_t n) {
            for (size_t i = 0; i < n; ++i) {
                if (lt(s1[i], s2[i])) return -1;
                if (lt(s2[i], s1[i])) return 1;
            }
            return 0;
        }

        static size_t length(const char_type* s) {
            size_t len = 0;
            while (s[len] != 0) ++len;
            return len;
        }

        static const char_type* find(const char_type* s, size_t n, const char_type& a) {
            for (size_t i = 0; i < n; ++i) {
                if (eq(s[i], a)) return s + i;
            }
            return nullptr;
        }

        static char_type* move(char_type* dest, const char_type* src, size_t n) {
            return static_cast<char_type*>(std::memmove(dest, src, n * sizeof(char_type)));
        }

        static char_type* copy(char_type* dest, const char_type* src, size_t n) {
            return static_cast<char_type*>(std::memcpy(dest, src, n * sizeof(char_type)));
        }

        static char_type* assign(char_type* s, size_t n, char_type a) {
            for (size_t i = 0; i < n; ++i) s[i] = a;
            return s;
        }

        static constexpr int_type not_eof(int_type c) noexcept { return c != eof() ? c : 0; }
        static constexpr char_type to_char_type(int_type c) noexcept { return static_cast<char_type>(c); }
        static constexpr int_type to_int_type(char_type c) noexcept { return static_cast<int_type>(c); }
        static constexpr bool eq_int_type(int_type c1, int_type c2) noexcept { return c1 == c2; }
        static constexpr int_type eof() noexcept { return static_cast<int_type>(-1); }
    };
}
