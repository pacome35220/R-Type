/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** Error.hpp
*/

#pragma once

#include <string>
#include <exception>

class Error : public std::exception {
public:
    Error(const std::string &_message, const std::string &_file,
          const std::string &_function, const size_t &_line);

public:
    const char *what() const throw();

private:
    const std::string message;
    const std::string file;
    const std::string function;
    const size_t line;
};
