#pragma once
#include <Siv3D.hpp>

class Block {

    // ブロック
    Rect m_block;

public:
    Block(const Point& p, const Size& blockSize);

    // 描画
    void draw()const;

    // 当たり判定
    template <class Shape2DType>
    bool intersects(const Shape2DType& shape)const {
        return this->m_block.intersects(shape);
    }
    template <class Shape2DType>
    bool intersectsTopBottom(const Shape2DType& shape)const {
        return m_block.bottom().intersects(shape) ||
            m_block.top().intersects(shape);
    }
    template <class Shape2DType>
    bool intersectsRightLeft(const Shape2DType& shape)const {
        return m_block.right().intersects(shape) ||
            m_block.left().intersects(shape);
    }
};
