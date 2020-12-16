#pragma once
# include <Siv3D.hpp>
#include "./Paddle.hpp"

class Ball {

    // ボールの速度
    const double m_speed = 480.0;
    // ボールの速さ
    Vec2 m_ballVelocity;
    // ボール
    Circle m_ball;

public:
    Ball();

    // ボールを移動
    void move();

    // 跳ね返る
    void rebound(const Paddle& paddle);

    // 描画する
    void draw()const;

    // ボールを返す
    Circle getBall()const;

    // ボールの速さを"参照で"返す
    Vec2& getBallVelocity();
};

