#pragma once
#include <Siv3D.hpp>
#include "./Ball.hpp"

class Block {

    // �u���b�N
    Rect block;

public:
    Block(const Point& p, const Size& blockSize);

    // �u���b�N�ƃ{�[���̓�����𔻒�
    bool intersectsBall(Ball& ball);

    // �`��
    void draw()const;
};

