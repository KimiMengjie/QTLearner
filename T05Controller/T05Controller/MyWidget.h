#pragma once

#include <QtWidgets/QWidget>
#include "ui_MyWidget.h"
#include <QTextEdit>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = Q_NULLPTR);
	

signals:
	public slots :
		void slotComboxIndexChanged(const QString &);

private:
    Ui::MyWidgetClass ui;
	QTextEdit *m_edit;
};
