#include "Block.hpp"

Block::Block(const Point& p, const Size& blockSize)
    : m_block(p.x* blockSize.x, 60 + p.y * blockSize.y, blockSize) {}


void Block::draw() const {
    m_block.stretched(-1).draw(HSV(m_block.y - 40));
}
