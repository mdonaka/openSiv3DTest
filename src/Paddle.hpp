#pragma once
#include <Siv3D.hpp>

class Paddle {

    // �p�h��
    const Rect m_paddle;

public:
    Paddle();

    // �`��
    void draw() const;

    // �p�h�����擾
    Rect getPaddle()const;

};

