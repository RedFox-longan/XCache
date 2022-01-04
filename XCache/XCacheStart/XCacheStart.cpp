/*
    Copyright (C) 2020-2022 Roy Qu (royqh1979@gmail.com)
    Copyright (C) 2021-2022 XCacha Team
    Copyright (C) 2021-2022 Space Longan

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "XCacheStart.h"
#include "XCache.h"

#include <QAction>
#include <QCoreApplication>
#include <QMouseEvent>
#include <QPainter>
#include <QTime>
#include <QTimer>

#include <QScreen>
#include <QGuiApplication>
#include <QPropertyAnimation>

#include <QDialog>

// XCacheStart.png
QImage image("XCacheStart.png");

XCacheStart::XCacheStart(QDialog *parent) : QDialog(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect mm = screen->availableGeometry();
    int screen_width = mm.width();
    int screen_height = mm.height();

    setAttribute(Qt::WA_TranslucentBackground);

    // 启动界面 关闭
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&XCacheStart::update));
    timer->start(1000);
    QAction *quitAction = new QAction(tr("E&xit"), this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
    addAction(quitAction);
    setContextMenuPolicy(Qt::ActionsContextMenu);

    // 启动界面 逐渐消失并关闭
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(5000);
    // animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    // setWindowTitle(XCACHE_NAME + " " + XCACHE_VERSION);
    setWindowTitle(XCACHE_NAME);
    move((screen_width - sizeHint().width()) / 2, (screen_height - sizeHint().height()) / 2);
}



// 绘画事件
void XCacheStart::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QRect target(0, 0, sizeHint().width(), sizeHint().height());
    painter.drawImage(target, image);
}


// 尺寸提示 const
QSize XCacheStart::sizeHint() const
{
    return QSize(image.width() / 2, image.height() / 2);
    // image.width(), image.height()
}

