#include "Ball.hpp"

Ball::Ball() : m_speed(480.0), m_ballVelocity(0, -m_speed), m_ball(400, 400, 8) {}

void Ball::move() {
    m_ball.moveBy(m_ballVelocity * Scene::DeltaTime());
}

void Ball::rebound(const Paddle& paddle) {
    // 天井にぶつかったらはね返る
    if (m_ball.y < 0 && m_ballVelocity.y < 0) {
        m_ballVelocity.y *= -1;
    }

    // 左右の壁にぶつかったらはね返る
    if ((m_ball.x < 0 && m_ballVelocity.x < 0) || (Scene::Width() < m_ball.x && m_ballVelocity.x > 0)) {
        m_ballVelocity.x *= -1;
    }

    // パドルにあたったらはね返る
    if (m_ballVelocity.y > 0 && paddle.intersects(m_ball)) {
        // パドルの中心からの距離に応じてはね返る向きを変える
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