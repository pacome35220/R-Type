/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** Error.hpp
*/

#pragma once

#include <string>
#include <exception>

using namespace std;

#define ERROR(message) Error(message, __FILE__, __FUNCTION__, __LINE__)

class Error : public std::exception
{
public:
    Error(const string &_message, const string &_file, const string &_function, const size_t &_line)

public:
    const char *what() const throw();

private:
    const string message;
    const string file;
    const string function;
    const size_t line;
};
