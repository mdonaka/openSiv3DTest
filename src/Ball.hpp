#pragma once
# include <Siv3D.hpp>
#include "./Paddle.hpp"
#include "./Block.hpp"

class Ball {

    // �{�[���̑��x
    const double m_speed = 480.0;
    // �{�[���̑���
    Vec2 m_ballVelocity;
    // �{�[��
    Circle m_ball;

public:
    Ball();

    // �{�[�����ړ�
    void move();

    // ���˕Ԃ�
    void rebound(const Paddle& paddle);
    void rebound(const Block& block);

    // �`�悷��
    void draw()const;

    Circle getBall() const;
};

