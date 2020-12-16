#pragma once
#include <Siv3D.hpp>
#include "./Ball.hpp"

class Block {

    // ブロック
    Rect block;

public:
    Block(const Point& p, const Size& blockSize);

    // ブロックとボールの当たりを判定
    bool intersectsBall(Ball& ball);

    // 描画
    void draw()const;
};

