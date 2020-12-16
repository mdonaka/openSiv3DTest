#include "Ball.hpp"

void Ball::move() {
    m_ball.moveBy(m_ballVelocity * Scene::DeltaTime());
}

void Ball::rebound(const Paddle& paddle) {
    // �V��ɂԂ�������͂˕Ԃ�
    if (m_ball.y < 0 && m_ballVelocity.y < 0) {
        m_ballVelocity.y *= -1;
    }

    // ���E�̕ǂɂԂ�������͂˕Ԃ�
    if ((m_ball.x < 0 && m_ballVelocity.x < 0) || (Scene::Width() < m_ball.x && m_ballVelocity.x > 0)) {
        m_ballVelocity.x *= -1;
    }

    // �p�h���ɂ���������͂˕Ԃ�
    if (m_ballVelocity.y > 0 && paddle.getPaddle().intersects(m_ball)) {
        // �p�h���̒��S����̋����ɉ����Ă͂˕Ԃ������ς���
        m_ballVelocity = Vec2((m_ball.x - paddle.getPaddle().center().x) * 10, -m_ballVelocity.y).setLength(m_speed);
    }
}

void Ball::draw() const {
    m_ball.draw();
}

Circle Ball::getBall() const {
    return m_ball;
}

Vec2& Ball::getBallVelocity() {
    return m_ballVelocity;
}