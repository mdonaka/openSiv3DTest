#pragma once
# include <Siv3D.hpp>
#include "./Paddle.hpp"
#include "./Block.hpp"

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
    void rebound(const Block& block);

    // 描画する
    void draw()const;

    Circle getBall() const;
};

