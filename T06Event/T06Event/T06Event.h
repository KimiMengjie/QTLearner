#pragma once

#include <QtWidgets/QWidget>
#include "ui_T06Event.h"

class T06Event : public QWidget
{
    Q_OBJECT

public:
    T06Event(QWidget *parent = Q_NULLPTR);

private:
    Ui::T06EventClass ui;
};
