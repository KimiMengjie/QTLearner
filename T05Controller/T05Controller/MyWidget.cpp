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
#include <QDebug>
#include <QPixmap>
#include <QLCDNumber>

#include <QVBoxLayout>

MyWidget::MyWidget(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout *lay = new QVBoxLayout(this);
	QLabel *label;
	QComboBox *combo;
	QPushButton *button;
	QRadioButton *radio;
	QTextEdit *edit;
	QGroupBox *groupBox;

	lay->addWidget(label = new QLabel("<a href=www.baidu.com>baidu</a>"));
	label->setPixmap(QPixmap("./lena.bmp"));
	//�źŲ�Lambda���ʽ
	connect(label, &QLabel::linkActivated, [](QString str) {
		qDebug() << str << endl;
	});
	lay->addWidget(button = new QPushButton("Button"));
	//����button���CSS��ʽ
	button->setStyleSheet("QPushButton {font:bold 40px; color:red}");

	lay->addWidget(radio = new QRadioButton("Radio"));
	//����Radio���CSS��ʽ
	radio->setStyleSheet("QRadioButton {font:bold 40px; color:blue; padding:5px}");
	connect(radio, &QRadioButton::clicked, [](bool v) {
		qDebug() << v;
	});

	//checkBox�Ƚϳ���
	lay->addWidget(new QCheckBox("check box"));

	//combobox
	lay->addWidget(combo = new QComboBox());
	//combox����ӿؼ�
	combo->addItem("Select item1");
	combo->addItem("Select item2");
	//����combo�ɱ༭
	combo->setEditable(true);
	//�źŲ�
	connect(combo, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotComboxIndexChanged(QString)));

	//�����Զ���ʾ
	//combo->setCompleter(new QCompleter(QStringList() << "aaa" << "bbb"));
	combo->setCompleter(new QCompleter(combo->model()));

	lay->addWidget(edit = new QTextEdit);
	edit->setText("<table border=1><tr><th>head1</th><th>header2</th></tr>"
		"<tr><td>value1</td><td>value2</td></tr>"
		"<tr><td>value3</td><td>value4</td></tr>"
		"</table><br>"
		"<img src=./lena.jpg></img>");
	//������ֱ仯
	m_edit = edit;
	connect(edit, &QTextEdit::textChanged, [&]() {
		qDebug() << m_edit->toPlainText();
		//����emoji����Ļ�����������������ж��滻��Ǳ������ֱ�ΪͼƬ��
	});
	//������ֱ����������
	edit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	edit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//��Ϸ���,���ɸ�С�Ŀؼ��������������������һ��layout
	lay->addWidget(groupBox = new QGroupBox);
	QHBoxLayout *hBoxLay;
	groupBox->setLayout(hBoxLay = new QHBoxLayout);
	hBoxLay->addWidget(new QPushButton("aaaa"));
	hBoxLay->addWidget(new QPushButton("bbbb"));

	//������
	QSlider *slider;
	lay->addWidget(slider = new QSlider(Qt::Horizontal));
	slider->setMaximum(100);
	slider->setMinimum(0);
	
	//����ѡֵ����
	QSpinBox *spinBox;
	lay->addWidget(spinBox = new QSpinBox);
	spinBox->setMaximum(100);
	spinBox->setMinimum(0);
	//�����������ı�spinbox��ֵ,����spinbox��ֵ�ı������
	connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
	connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));

	lay->addWidget(new QDateTimeEdit);

	//��ʾLCD��ʽ��Ļ
	QLCDNumber *lcd;
	lay->addWidget(lcd = new QLCDNumber(10));
	//������ʾ����
	lcd->display(12345);
	//������ʾģʽ
	lcd->setMode(QLCDNumber::Hex);
	lcd->setSegmentStyle(QLCDNumber::Flat);


	ui.setupUi(this);
}

void MyWidget::slotComboxIndexChanged(const QString &str)
{
	qDebug() << "slotComboxIndexChanged: " << str << endl;
}
