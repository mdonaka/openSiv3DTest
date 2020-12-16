#pragma once
#include <Siv3D.hpp>
#include "./Ball.hpp"

class Blocks {

    // �u���b�N�̃T�C�Y
    const Size m_blockSize;

    // �u���b�N�̗�
    Array<Rect> m_blocks;

public:
    Blocks();
    
    // �e�u���b�N�ƃ{�[���̓�����𔻒�
    void intersectsBlock(Ball& ball);

    // �`��
    void draw()const;
};

