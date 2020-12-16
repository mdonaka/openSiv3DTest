# include <Siv3D.hpp>
#include "./src/Ball.hpp"

void Main() {
    // ブロックのサイズ
    constexpr Size blockSize(40, 20);

    // ブロックの配列
    Array<Rect> blocks;

    // 横 (Scene::Width() / blockSize.x) 個、縦 5 個のブロックを配列に追加する
    for (auto p : step(Size((Scene::Width() / blockSize.x), 5))) {
        blocks << Rect(p.x * blockSize.x, 60 + p.y * blockSize.y, blockSize);
    }

    // ボール
    auto ball = Ball();

    while (System::Update()) {
        // パドル
        const Rect paddle(Arg::center(Cursor::Pos().x, 500), 60, 10);

        // ボールを移動
        ball.move();

        // ブロックを順にチェック
        for (auto it = blocks.begin(); it != blocks.end(); ++it) {
            // ボールとブロックが交差していたら
            if (it->intersects(ball.getBall())) {
                // ボールの向きを反転する
                (it->bottom().intersects(ball.getBall()) || it->top().intersects(ball.getBall()) ? ball.getBallVelocity().y : ball.getBallVelocity().x) *= -1;

                // ブロックを配列から削除（イテレータが無効になるので注意）
                blocks.erase(it);

                // これ以上チェックしない  
                break;
            }
        }

        // ボールを跳ね返す
        ball.rebound(paddle);

        // すべてのブロックを描画する
        for (const auto& block : blocks) {
            block.stretched(-1).draw(HSV(block.y - 40));
        }

        // ボールを描く
        ball.draw();

        // パドルを描く
        paddle.draw();
    }
}