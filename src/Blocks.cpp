#include "Blocks.hpp"

Blocks::Blocks() :m_blockSize(40, 20) {
    // �� (Scene::Width() / blockSize.x) �A�c 5 �̃u���b�N��z��ɒǉ�����
    for (auto p : step(Size((Scene::Width() / m_blockSize.x), 5))) {
        m_blocks << Rect(p.x * m_blockSize.x, 60 + p.y * m_blockSize.y, m_blockSize);
    }
}

void Blocks::intersectsBlock(Ball& ball) {

    // �u���b�N�����Ƀ`�F�b�N
    for (auto it = m_blocks.begin(); it != m_blocks.end(); ++it) {
        // �{�[���ƃu���b�N���������Ă�����
        if (it->intersects(ball.getBall())) {
            // �{�[���̌����𔽓]����
            (it->bottom().intersects(ball.getBall()) || it->top().intersects(ball.getBall()) ? ball.getBallVelocity().y : ball.getBallVelocity().x) *= -1;

            // �u���b�N��z�񂩂�폜�i�C�e���[�^�������ɂȂ�̂Œ��Ӂj
            m_blocks.erase(it);

            // ����ȏ�`�F�b�N���Ȃ�  
            break;
        }
    }
}

void Blocks::draw() const {
    // ���ׂẴu���b�N��`�悷��
    for (const auto& block : m_blocks) {
        block.stretched(-1).draw(HSV(block.y - 40));
    }
}