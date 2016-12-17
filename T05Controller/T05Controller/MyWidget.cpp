#include "MyWidget.h"
#include <QApplication>

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

#include <QComboBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QTextEdit>
#include <QTextBrowser>
#include <QGroupBox>
#include <QSlider>	//模拟方式显示数组
#include <QSpinBox>	//数字
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTimeEdit>
#include <QTabWidget>	//不介绍，不算控件
#include <QCompleter>

#include <QVBoxLayout>

MyWidget::MyWidget(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout *lay = new QVBoxLayout(this);
	QLabel *label;
	QComboBox *combo;
	QPushButton *button;
	QRadioButton *radio;

	lay->addWidget(label = new QLabel("<h1>label</h1> <font color=red>label</font>"));
	lay->addWidget(button = new QPushButton("Button"));
	//设置button风格CSS样式
	button->setStyleSheet("QPushButton {font:bold 40px; color:red}");
	lay->addWidget(radio = new QRadioButton("Radio"));
	//设置Radio风格CSS样式
	radio->setStyleSheet("QRadioButton {font:bold 40px; color:blue; padding:5px}");

	lay->addWidget(new QCheckBox("check box"));
	lay->addWidget(combo = new QComboBox());
	//combox中添加控件
	combo->addItem("Select item1");
	combo->addItem("Select item2");
	//设置combo可编辑
	combo->setEditable(true);
	//设置自动提示
	//combo->setCompleter(new QCompleter(QStringList() << "aaa" << "bbb"));
	combo->setCompleter(new QCompleter(combo->model()));

	lay->addWidget(new QTextEdit);		//可以用来做报表
	lay->addWidget(new QGroupBox);
	lay->addWidget(new QSlider);
	lay->addWidget(new QSpinBox);
	lay->addWidget(new QDateTimeEdit);



	ui.setupUi(this);
}
