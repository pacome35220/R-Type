/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** Error.cpp
*/

#include <sstream>
#include "Error.hpp"

std::string error;

Error::Error(const std::string &what, const std::string &_file,
             const std::string &_function, const std::size_t &_line)
    : _what(what), file(_file), function(_function), line(_line) {}

const char *Error::what() const throw() {
    return this->_what.c_str();
}

const char *Error::where() {
    std::stringstream ss;

    ss << this->file << " : " << this->function << " : " << this->line;
    this->_where = ss.str();
    return this->_where.c_str();
}
