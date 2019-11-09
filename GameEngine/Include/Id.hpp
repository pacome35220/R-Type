/**
 * @file      Id.hpp
 * @brief     This is the Id class
 * @details   This class will be used to generate a static id for each entities.
 */

#pragma once

#include <cstddef>

/**
 * @class Id "Include/Id.hpp"
 */
class Id {
public:
    Id();
    const std::size_t &getId() const;

protected:
    const std::size_t id;

private:
    static std::size_t idGen;
};
