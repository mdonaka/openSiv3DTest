#pragma once
#include <Siv3D.hpp>
#include "./Ball.hpp"
#include "./Block.hpp"

class Blocks {

    // ブロックのサイズ
    const Size m_blockSize;

    // ブロックの列
    Array<Block> m_blocks;

public:
    Blocks();
    
    // 各ブロックとボールの当たりを判定
    void intersectsBlock(Ball& ball);

    // 描画
    void draw()const;
};

