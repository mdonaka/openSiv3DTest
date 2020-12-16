#include "Paddle.hpp"

Paddle::Paddle()
    :m_paddle(Arg::center(Cursor::Pos().x, 500), 60, 10) {}

void Paddle::draw() const {
    m_paddle.draw();
}

Rect Paddle::getPaddle() const {
    return m_paddle;
}

