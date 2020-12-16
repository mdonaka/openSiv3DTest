#pragma once
# include <Siv3D.hpp>

class Ball {

    // �{�[���̑��x
    const double m_speed = 480.0;
    // �{�[���̑���
    Vec2 m_ballVelocity;
    // �{�[��
    Circle m_ball;

public:
    Ball() :m_speed(480.0), m_ballVelocity(0, -m_speed), m_ball(400, 400, 8) {}

    // �{�[�����ړ�
    void move();

    // ���˕Ԃ�
    void rebound(const Rect& paddle);

    // �`�悷��
    void draw()const;

    // �{�[����Ԃ�
    Circle getBall()const;

    // �{�[���̑�����"�Q�Ƃ�"�Ԃ�
    Vec2& getBallVelocity();
};

