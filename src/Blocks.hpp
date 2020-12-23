#pragma once
#include <Siv3D.hpp>
#include <optional>
#include "./Ball.hpp"
#include "./Block.hpp"

class Blocks {

    // �u���b�N�̃T�C�Y
    const Size m_blockSize;

    // �u���b�N�̗�
    Array<Block> m_blocks;

public:
    Blocks();

    // �{�[���Ɠ������Ă���u���b�N��Ԃ�
    std::optional<Block> getIntersectsBlock(Ball& ball);

    // �`��
    void draw()const;

};

