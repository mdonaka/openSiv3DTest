#include "Blocks.hpp"

Blocks::Blocks() :m_blockSize(40, 20) {
    // 横 (Scene::Width() / blockSize.x) 個、縦 5 個のブロックを配列に追加する
    for (auto p : step(Size((Scene::Width() / m_blockSize.x), 5))) {
        m_blocks << Block(p, m_blockSize);
    }
}

void Blocks::intersectsBlock(Ball& ball) {

    // ブロックを順にチェック
    for (auto it = m_blocks.begin(); it != m_blocks.end(); ++it) {
        // ボールとブロックが交差していたら
        if (it->intersectsBall(ball)) {

            // ブロックを配列から削除（イテレータが無効になるので注意）
            m_blocks.erase(it);

            // これ以上チェックしない  
            break;
        }
    }
}

void Blocks::draw() const {
    // すべてのブロックを描画する
    for (const auto& block : m_blocks) {
        block.draw();
    }
}
