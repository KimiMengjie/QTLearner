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
#include <QSlider>	//ģ�ⷽʽ��ʾ����
#include <QSpinBox>	//����
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTimeEdit>
#include <QTabWidget>	//�����ܣ�����ؼ�
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
	//����button���CSS��ʽ
	button->setStyleSheet("QPushButton {font:bold 40px; color:red}");
	lay->addWidget(radio = new QRadioButton("Radio"));
	//����Radio���CSS��ʽ
	radio->setStyleSheet("QRadioButton {font:bold 40px; color:blue; padding:5px}");

	lay->addWidget(new QCheckBox("check box"));
	lay->addWidget(combo = new QComboBox());
	//combox����ӿؼ�
	combo->addItem("Select item1");
	combo->addItem("Select item2");
	//����combo�ɱ༭
	combo->setEditable(true);
	//�����Զ���ʾ
	//combo->setCompleter(new QCompleter(QStringList() << "aaa" << "bbb"));
	combo->setCompleter(new QCompleter(combo->model()));

	lay->addWidget(new QTextEdit);		//��������������
	lay->addWidget(new QGroupBox);
	lay->addWidget(new QSlider);
	lay->addWidget(new QSpinBox);
	lay->addWidget(new QDateTimeEdit);



	ui.setupUi(this);
}
