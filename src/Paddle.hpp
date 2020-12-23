#pragma once
#include <Siv3D.hpp>

class Paddle {

    // �p�h��
    const Rect m_paddle;

public:
    Paddle();

    // �`��
    void draw() const;

    // �p�h����shape�Ƃ̓����蔻��
    template <class Shape2DType>
    bool intersects(const Shape2DType& shape)const {
        return this->m_paddle.intersects(shape);

    };

    // �p�h���̒��S�Ƃ̋���(X���W�̂�)
    double distanceOfCenterX(double targetX)const;
};

