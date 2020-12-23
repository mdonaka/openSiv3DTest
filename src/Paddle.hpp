#pragma once
#include <Siv3D.hpp>

class Paddle {

    // パドル
    const Rect m_paddle;

public:
    Paddle();

    // 描画
    void draw() const;

    // パドルとshapeとの当たり判定
    template <class Shape2DType>
    bool intersects(const Shape2DType& shape)const {
        return this->m_paddle.intersects(shape);

    };

    // パドルの中心との距離(X座標のみ)
    double distanceOfCenterX(double targetX)const;
};

