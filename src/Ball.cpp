#include "Ball.hpp"

Ball::Ball() : m_speed(480.0), m_ballVelocity(0, -m_speed), m_ball(400, 400, 8) {}

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
    if (m_ballVelocity.y > 0 && paddle.intersects(m_ball)) {
        // �p�h���̒��S����̋����ɉ����Ă͂˕Ԃ������ς���
        m_ballVelocity = Vec2(paddle.distanceOfCenterX(m_ball.x) * 10, -m_ballVelocity.y).setLength(m_speed);
    }
}

void Ball::rebound(const Block& block) {
    if (block.intersectsTopBottom(m_ball)) {
        m_ballVelocity.y *= -1;
    } else {
        m_ballVelocity.x *= -1;
    }
}

void Ball::draw() const {
    m_ball.draw();
}

Circle Ball::getBall() const{
    return m_ball;
}