#include <QApplication>
#include "backstage.h"
#include "userinterface.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 创建 BackStage 窗口
    // BackStage backstage;
    // backstage.setWindowTitle("航班管理后台"); // 设置窗口标题
    // backstage.resize(1000, 800);             // 设置窗口大小
    // backstage.show();                        // 显示窗口

    UserInterface *user = new UserInterface();
    user->show();

    return app.exec();
}
