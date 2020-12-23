#include "Blocks.hpp"

Blocks::Blocks() :m_blockSize(40, 20) {
    // �� (Scene::Width() / blockSize.x) �A�c 5 �̃u���b�N��z��ɒǉ�����
    for (auto p : step(Size((Scene::Width() / m_blockSize.x), 5))) {
        m_blocks << Block(p, m_blockSize);
    }
}

std::optional<Block> Blocks::getIntersectsBlock(Ball& ball) {

    // �u���b�N�����Ƀ`�F�b�N
    for (auto it = m_blocks.begin(); it != m_blocks.end(); ++it) {
        // �{�[���ƃu���b�N���������Ă�����
        if (it->intersects(ball.getBall())) {

            auto block = *it;

            // �u���b�N��z�񂩂�폜
            m_blocks.erase(it);

            return block;
        }
    }
    return std::nullopt;
}

void Blocks::draw() const {
    // ���ׂẴu���b�N��`�悷��
    for (const auto& block : m_blocks) {
        block.draw();
    }
}
