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
	//信号槽Lambda表达式
	connect(label, &QLabel::linkActivated, [](QString str) {
		qDebug() << str << endl;
	});
	lay->addWidget(button = new QPushButton("Button"));
	//设置button风格CSS样式
	button->setStyleSheet("QPushButton {font:bold 40px; color:red}");

	lay->addWidget(radio = new QRadioButton("Radio"));
	//设置Radio风格CSS样式
	radio->setStyleSheet("QRadioButton {font:bold 40px; color:blue; padding:5px}");
	connect(radio, &QRadioButton::clicked, [](bool v) {
		qDebug() << v;
	});

	//checkBox比较常用
	lay->addWidget(new QCheckBox("check box"));

	//combobox
	lay->addWidget(combo = new QComboBox());
	//combox中添加控件
	combo->addItem("Select item1");
	combo->addItem("Select item2");
	//设置combo可编辑
	combo->setEditable(true);
	//信号槽
	connect(combo, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotComboxIndexChanged(QString)));

	//设置自动提示
	//combo->setCompleter(new QCompleter(QStringList() << "aaa" << "bbb"));
	combo->setCompleter(new QCompleter(combo->model()));

	lay->addWidget(edit = new QTextEdit);
	edit->setText("<table border=1><tr><th>head1</th><th>header2</th></tr>"
		"<tr><td>value1</td><td>value2</td></tr>"
		"<tr><td>value3</td><td>value4</td></tr>"
		"</table><br>"
		"<img src=./lena.jpg></img>");
	//检测文字变化
	m_edit = edit;
	connect(edit, &QTextEdit::textChanged, [&]() {
		qDebug() << m_edit->toPlainText();
		//例如emoji表情的话，可以在这里进行判断替换标记表情文字变为图片。
	});
	//设置竖直滚动条策略
	edit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	edit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//组合分类,容纳更小的控件，本质上往里面放置了一个layout
	lay->addWidget(groupBox = new QGroupBox);
	QHBoxLayout *hBoxLay;
	groupBox->setLayout(hBoxLay = new QHBoxLayout);
	hBoxLay->addWidget(new QPushButton("aaaa"));
	hBoxLay->addWidget(new QPushButton("bbbb"));

	//滑动条
	QSlider *slider;
	lay->addWidget(slider = new QSlider(Qt::Horizontal));
	slider->setMaximum(100);
	slider->setMinimum(0);
	
	//设置选值窗口
	QSpinBox *spinBox;
	lay->addWidget(spinBox = new QSpinBox);
	spinBox->setMaximum(100);
	spinBox->setMinimum(0);
	//滑动进度条改变spinbox的值,更改spinbox的值改变进度条
	connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
	connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));

	lay->addWidget(new QDateTimeEdit);

	//显示LCD样式屏幕
	QLCDNumber *lcd;
	lay->addWidget(lcd = new QLCDNumber(10));
	//设置显示内容
	lcd->display(12345);
	//设置显示模式
	lcd->setMode(QLCDNumber::Hex);
	lcd->setSegmentStyle(QLCDNumber::Flat);


	ui.setupUi(this);
}

void MyWidget::slotComboxIndexChanged(const QString &str)
{
	qDebug() << "slotComboxIndexChanged: " << str << endl;
}
