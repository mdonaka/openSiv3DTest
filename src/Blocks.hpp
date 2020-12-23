#pragma once
#include <Siv3D.hpp>
#include <optional>
#include "./Ball.hpp"
#include "./Block.hpp"

class Blocks {

    // ブロックのサイズ
    const Size m_blockSize;

    // ブロックの列
    Array<Block> m_blocks;

public:
    Blocks();

    // ボールと当たっているブロックを返す
    std::optional<Block> getIntersectsBlock(Ball& ball);

    // 描画
    void draw()const;

};

