/*
 * string_traits.hpp
 *
 *  Created on: 05.03.2016
 *      Author: Klemens
 */

#ifndef BOOST_PROCESS_DETAIL_TRAITS_CMD_OR_EXE_HPP_
#define BOOST_PROCESS_DETAIL_TRAITS_CMD_OR_EXE_HPP_

#include <string>
#include <vector>
#include <type_traits>
#include <initializer_list>
#include <boost/filesystem/path.hpp>
#include <boost/process/detail/traits/decl.hpp>

namespace boost { namespace process { namespace detail {

struct cmd_or_exe_tag {};
struct shell_;

template<> struct initializer_tag<boost::filesystem::path> { typedef cmd_or_exe_tag type;};

template<> struct initializer_tag<const char*    > { typedef cmd_or_exe_tag type;};
template<> struct initializer_tag<const wchar_t* > { typedef cmd_or_exe_tag type;};

template<> struct initializer_tag<char*    > { typedef cmd_or_exe_tag type;};
template<> struct initializer_tag<wchar_t* > { typedef cmd_or_exe_tag type;};

template<std::size_t Size> struct initializer_tag<const char    [Size]> { typedef cmd_or_exe_tag type;};
template<std::size_t Size> struct initializer_tag<const wchar_t [Size]> { typedef cmd_or_exe_tag type;};

template<std::size_t Size> struct initializer_tag<const char    (&)[Size]> { typedef cmd_or_exe_tag type;};
template<std::size_t Size> struct initializer_tag<const wchar_t (&)[Size]> { typedef cmd_or_exe_tag type;};

template<> struct initializer_tag<std::basic_string<char    >> { typedef cmd_or_exe_tag type;};
template<> struct initializer_tag<std::basic_string<wchar_t >> { typedef cmd_or_exe_tag type;};

template<> struct initializer_tag<std::vector<std::basic_string<char    >>> { typedef cmd_or_exe_tag type;};
template<> struct initializer_tag<std::vector<std::basic_string<wchar_t >>> { typedef cmd_or_exe_tag type;};

template<> struct initializer_tag<std::initializer_list<std::basic_string<char    >>> { typedef cmd_or_exe_tag type;};
template<> struct initializer_tag<std::initializer_list<std::basic_string<wchar_t >>> { typedef cmd_or_exe_tag type;};

template<> struct initializer_tag<std::vector<char    *>> { typedef cmd_or_exe_tag type;};
template<> struct initializer_tag<std::vector<wchar_t *>> { typedef cmd_or_exe_tag type;};

template<> struct initializer_tag<std::initializer_list<char    *>> { typedef cmd_or_exe_tag type;};
template<> struct initializer_tag<std::initializer_list<wchar_t *>> { typedef cmd_or_exe_tag type;};

template<> struct initializer_tag<shell_> { typedef cmd_or_exe_tag type; };

struct exe_setter_;
template <class String, bool Append = false>
struct arg_setter_;

template <class String, bool Append>
struct initializer_tag<arg_setter_<String, Append>> { typedef cmd_or_exe_tag type;};
template<> struct initializer_tag<exe_setter_> { typedef cmd_or_exe_tag type;};

template<>
struct initializer_builder<cmd_or_exe_tag>;

//template

template<typename T> struct is_wchar_t {typedef std::false_type type;};

template<> struct is_wchar_t<boost::filesystem::path> {typedef std::true_type type;};

template<> struct is_wchar_t<const wchar_t* > { typedef std::true_type type;};

template<> struct is_wchar_t<wchar_t* > { typedef std::true_type type;};

template<std::size_t Size> struct is_wchar_t<const wchar_t [Size]>    { typedef std::true_type type;};
template<std::size_t Size> struct is_wchar_t<const wchar_t (&)[Size]> { typedef std::true_type type;};

template<> struct is_wchar_t<std::basic_string<wchar_t >>              { typedef std::true_type type;};
template<> struct is_wchar_t<std::vector<std::basic_string<wchar_t >>> { typedef std::true_type type;};
template<> struct is_wchar_t<std::initializer_list<std::basic_string<wchar_t >>> { typedef std::true_type type;};
template<> struct is_wchar_t<std::vector<wchar_t *>>           { typedef std::true_type type;};
template<> struct is_wchar_t<std::initializer_list<wchar_t *>> { typedef std::true_type type;};


}}}



#endif /* BOOST_PROCESS_DETAIL_STRING_TRAITS_HPP_ */
