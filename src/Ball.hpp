#pragma once
# include <Siv3D.hpp>

class Ball {

    // ボールの速度
    const double m_speed = 480.0;
    // ボールの速さ
    Vec2 m_ballVelocity;
    // ボール
    Circle m_ball;

public:
    Ball() :m_speed(480.0), m_ballVelocity(0, -m_speed), m_ball(400, 400, 8) {}

    // ボールを移動
    void move();

    // 跳ね返る
    void rebound(const Rect& paddle);

    // 描画する
    void draw()const;

    // ボールを返す
    Circle getBall()const;

    // ボールの速さを"参照で"返す
    Vec2& getBallVelocity();
};

