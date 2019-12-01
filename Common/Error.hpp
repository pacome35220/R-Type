/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Error.hpp
*/

#pragma once

#include <string>
#include <exception>

/**
 * @class Error
 * @brief This class is used to have a efficient error management
 */
class Error : public std::exception {
public:
    Error(const std::string &_what, const std::string &_file,
          const std::string &_function, const size_t &_line);

public:
    const char *what() const throw() override;
    const char *where();

private:
    const std::string _what;
    std::string _where;

    const std::string file;
    const std::string function;
    const size_t line;
};
