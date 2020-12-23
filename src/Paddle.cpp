#include "Paddle.hpp"

Paddle::Paddle()
    :m_paddle(Arg::center(Cursor::Pos().x, 500), 60, 10) {}


void Paddle::draw() const {
    m_paddle.draw();
}


double Paddle::distanceOfCenterX(double targetX) const {
    return targetX - m_paddle.center().x;
}
