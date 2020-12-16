# include <Siv3D.hpp>
#include "./src/Ball.hpp"
#include "./src/Paddle.hpp"
#include "./src/Blocks.hpp"

void Main() {

    // 全てのブロック
    auto blocks = Blocks();

    // ボール
    auto ball = Ball();

    while (System::Update()) {
        // パドル
        const auto paddle = Paddle();

        // ボールを移動
        ball.move();

        // ブロックとボールの当たりを判定
        blocks.intersectsBlock(ball);

        // ボールを跳ね返す
        ball.rebound(paddle);

        // すべてのブロックを描画する
        blocks.draw();

        // ボールを描く
        ball.draw();

        // パドルを描く
        paddle.draw();
    }
}