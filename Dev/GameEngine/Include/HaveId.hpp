/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** HaveId.hpp
*/

#pragma once

//#include <> // ?

class HaveId
{
public:
    HaveId();

protected:
    const size_t id;

private:
    static size_t idGen;
};
