#include "MainWindow.h"

#include <QApplication>
#include <QIcon>
#include <QKeyEvent>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include <knock/Knock>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle(tr("About ") + qAppName());
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    auto *w = new QWidget(this);
    auto *layout = new QVBoxLayout(w);
    setCentralWidget(w);

    // logo显示
    auto *logo = new QLabel(this);
    layout->addWidget(logo, 0, Qt::AlignCenter);
    logo->setPixmap(QApplication::windowIcon().pixmap(64));

    // 点击会功德+1的计数按钮
    auto *c = new knock::Knock();
    auto *btn = new QPushButton(this);
    layout->addWidget(btn, 0, Qt::AlignCenter);
    connect(c, &knock::Knock::num_changed, btn, [btn](int num) { btn->setText("功德: " + QString::number(num)); });
    c->set_num(0);
    connect(btn, &QPushButton::clicked, c, &knock::Knock::knock);

    // 版本&系统信息
    QString str("<h1>" + qAppName() + " " + qApp->applicationVersion() + "</h1>");
    str += R"(<div>Created by <a href="https://zmoth.top" target="_blank">Moth</a>; </div>)";
    str += "<div>Locale : " + QLocale::system().name() + "</div>";
    str += "<div>OS : " + QSysInfo::prettyProductName() + "</div>";
    str += "<div>CPU : " + QSysInfo::currentCpuArchitecture() + "</div>";

    auto *info = new QLabel(str, this);
    layout->addWidget(info);
    info->setOpenExternalLinks(true);

    setFixedSize(sizeHint());
    show();
}
