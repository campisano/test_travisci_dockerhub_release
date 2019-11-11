#ifndef POSITION__HPP__
#define POSITION__HPP__

#include <memory>
#include "number.hpp"

class Position
{
public:
    explicit Position();
    Position(const Position &) = delete;
    Position(Position &&) = default;
    virtual ~Position();

    Position & operator=(const Position &) = delete;
    Position & operator=(Position &&) = default;

public:
    const MovableNum & number();
    void place(MovableNum & _number);

private:
    MovableNum m_number;
};

#endif
