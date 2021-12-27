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


#ifndef SHAPEDCLOCK_H
#define SHAPEDCLOCK_H

// #include <QWidget>
#include <QDialog>

// QDialog QWidget
class XCacheStart : public QDialog {
Q_OBJECT
public:
    XCacheStart(QDialog *parent = nullptr);
    QSize sizeHint() const override;

protected:
    // void mouseMoveEvent(QMouseEvent *event) override;
    // void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    // void resizeEvent(QResizeEvent *event) override;
private:
    QPoint dragPosition;
};

#endif
