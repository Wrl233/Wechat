#include "LoginDialog.h"
#include "ui_LoginDialog.h"
#include <QFont>
#include <QColor>
#include <QAction>
#include <QPixmap> // 用于图标缩放

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setFixedSize(320, 400); // 固定窗口大小
    initUIStyle();
    initIcon();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::initUIStyle(){
    this->setStyleSheet(R"(
        /* 主窗口背景 */
        QWidget {
            background-color: #ffffff;
            border-radius: 12px;
        }

        /* 标题样式 */
        QLabel#titleLabel {
            font-family: "Microsoft YaHei";
            font-size: 28px;
            font-weight: bold;
            color: #333333;
        }

        /* 输入框样式 - 核心调整：内边距适配右侧图标 */
        QLineEdit {
            font-family: "Microsoft YaHei";
            font-size: 14px;
            height: 42px;
            border: 1px solid #e5e5e5;
            border-radius: 8px;
            padding-left: 10px; /* 左侧文本内边距（原44px改为12px） */
            padding-right: 44px; /* 右侧留空间给24px图标 + 8px间距 */
            background-color: #f8f8f8;
            text-align: left; /* 文本仍靠左，仅图标靠右 */
        }

        QLineEdit:focus {
            border-color: #409EFF;
            background-color: #ffffff;
        }

        /* 登录按钮样式 */
        QPushButton#loginBtn {
            font-family: "Microsoft YaHei";
            font-size: 16px;
            font-weight: 500;
            height: 48px;
            border: none;
            border-radius: 8px;
            background-color: #409EFF;
            color: #ffffff;
        }

        QPushButton#loginBtn:hover {
            background-color: #3088E3;
        }

        QPushButton#loginBtn:pressed {
            background-color: #2979D9;
        }

        /* 底部链接样式 */
        QLabel#forgotLabel, QLabel#registerLabel {
            font-family: "Microsoft YaHei";
            font-size: 13px;
            color: #999999;
        }

        QLabel#forgotLabel:hover, QLabel#registerLabel:hover {
            color: #409EFF;
            cursor: pointer;
        }
    )");
}

void LoginDialog::initIcon()
{
    // 通用图标尺寸（适配42px高度输入框，视觉协调）
    const int iconSize = 24;
    const QSize iconSizeQSize(iconSize, iconSize);

    // ========== 用户名输入框图标（右侧显示） ==========
    QAction *userAction = new QAction(this);
    QPixmap userPixmap(":/images/user.png");
    QPixmap scaledUserPixmap = userPixmap.scaled(
        iconSizeQSize,
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
        );
    userAction->setIcon(QIcon(scaledUserPixmap));
    userAction->setIconText("用户名");
    // 关键修改：LeadingPosition（左侧）→ TrailingPosition（右侧）
    ui->userEdit->addAction(userAction, QLineEdit::TrailingPosition);

    // ========== 密码输入框图标（右侧显示） ==========
    QAction *pwdAction = new QAction(this);
    QPixmap pwdPixmap(":/images/lock.png");
    QPixmap scaledPwdPixmap = pwdPixmap.scaled(
        iconSizeQSize,
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
        );
    pwdAction->setIcon(QIcon(scaledPwdPixmap));
    pwdAction->setIconText("密码");
    // 关键修改：LeadingPosition → TrailingPosition
    ui->pwdEdit->addAction(pwdAction, QLineEdit::TrailingPosition);

    // 隐藏菜单中图标（不影响输入框显示）
    userAction->setIconVisibleInMenu(false);
    pwdAction->setIconVisibleInMenu(false);

    // 文本仍靠左对齐（仅图标靠右）
    ui->userEdit->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    ui->pwdEdit->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
}
