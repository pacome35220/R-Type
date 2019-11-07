/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** Error.cpp
*/

#include "Error.hpp"

Error::Error(const std::string &_message, const std::string &_file,
             const std::string &_function, const std::size_t &_line)
    : message(_message), file(_file), function(_function), line(_line) {}

const char *Error::what() const throw() {
    const std::string str = message + " (file:" + file +
                            " | function:" + function +
                            "| line:" + std::to_string(line) + ")";
    return str.c_str();
}
