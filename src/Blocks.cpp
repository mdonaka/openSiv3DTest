#include "Blocks.hpp"

Blocks::Blocks() :m_blockSize(40, 20) {
    // 横 (Scene::Width() / blockSize.x) 個、縦 5 個のブロックを配列に追加する
    for (auto p : step(Size((Scene::Width() / m_blockSize.x), 5))) {
        m_blocks << Block(p, m_blockSize);
    }
}

std::optional<Block> Blocks::getIntersectsBlock(Ball& ball) {

    // ブロックを順にチェック
    for (auto it = m_blocks.begin(); it != m_blocks.end(); ++it) {
        // ボールとブロックが交差していたら
        if (it->intersects(ball.getBall())) {

            auto block = *it;

            // ブロックを配列から削除
            m_blocks.erase(it);

            return block;
        }
    }
    return std::nullopt;
}

void Blocks::draw() const {
    // すべてのブロックを描画する
    for (const auto& block : m_blocks) {
        block.draw();
    }
}
