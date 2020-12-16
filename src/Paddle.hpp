#pragma once
#include <Siv3D.hpp>

class Paddle {

    // パドル
    const Rect m_paddle;

public:
    Paddle();

    // 描画
    void draw() const;

    // パドルを取得
    Rect getPaddle()const;

};

