/********************************************************************************
** Form generated from reading UI file 'T06Event.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T06EVENT_H
#define UI_T06EVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_T06EventClass
{
public:

    void setupUi(QWidget *T06EventClass)
    {
        if (T06EventClass->objectName().isEmpty())
            T06EventClass->setObjectName(QStringLiteral("T06EventClass"));
        T06EventClass->resize(600, 400);

        retranslateUi(T06EventClass);

        QMetaObject::connectSlotsByName(T06EventClass);
    } // setupUi

    void retranslateUi(QWidget *T06EventClass)
    {
        T06EventClass->setWindowTitle(QApplication::translate("T06EventClass", "T06Event", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class T06EventClass: public Ui_T06EventClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T06EVENT_H
