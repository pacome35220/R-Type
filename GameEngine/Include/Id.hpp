/**
 * @file      Id.hpp
 */

#pragma once

#include <cstddef>

/**
 * @class Id "Include/Id.hpp"
 * @brief This is the Id class
 * @details This class will be used to generate a static id for each entities.
 */
class Id {
public:
    Id();
    std::size_t getId() const;
    void setId(size_t id);

protected:
    std::size_t id;

private:
    static std::size_t idGen;
};
