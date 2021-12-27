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


#ifndef ABOUTGUI_H
#define ABOUTGUI_H

#include <QWidget>

namespace Ui {
class AboutGUI;
}

class AboutGUI : public QWidget
{
    Q_OBJECT

public:
    explicit AboutGUI(QWidget *parent = nullptr);
    ~AboutGUI();

private:
    Ui::AboutGUI *ui;
};

#endif // ABOUTGUI_H
