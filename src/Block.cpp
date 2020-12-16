#include "Block.hpp"

Block::Block(const Point& p, const Size& blockSize)
    : block(p.x* blockSize.x, 60 + p.y * blockSize.y, blockSize) {}

bool Block::intersectsBall(Ball& ball) {
    // ボールとブロックが交差していたら
    if (block.intersects(ball.getBall())) {
        // ボールの向きを反転する
        (block.bottom().intersects(ball.getBall()) || block.top().intersects(ball.getBall()) ? ball.getBallVelocity().y : ball.getBallVelocity().x) *= -1;
        return true;
    }
    return false;
}

void Block::draw() const {
    block.stretched(-1).draw(HSV(block.y - 40));
}
