#include "InfoWindow.hpp"

#include <QApplication>
#include <QIcon>
#include <QKeyEvent>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>

#include "core/count.hpp"

InfoWindow::InfoWindow(QWidget *parent, Qt::WindowFlags flags) : QDialog(parent, flags)
{
    setWindowTitle(tr("About ") + qAppName());
    // setAttribute(Qt::WA_DeleteOnClose);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    // layout
    {
        auto *layout = new QVBoxLayout(this);

        // logo
        {
            auto *logo = new QLabel(this);
            layout->addWidget(logo, 0, Qt::AlignCenter);
            logo->setPixmap(QApplication::windowIcon().pixmap(64));
        }

        // button
        {
            auto *c = new Count();
            auto *btn = new QPushButton(this);
            layout->addWidget(btn, 0, Qt::AlignCenter);
            connect(c, &Count::numChanged, btn,
                    [btn](int num) { btn->setText("count: " + QString::number(num)); });
            c->setNum(0);
            connect(btn, &QPushButton::clicked, c, &Count::numCount);
        }

        // info
        {
            QString str("<h1>" + qAppName() + " " + qApp->applicationVersion() + "</h1>");
            str +=
                R"(<div>Created by <a href="https://zmoth.top" target="_blank">Moth</a>; </div>)";
            str += R"(<div>Organization : <a href=")" + qApp->organizationDomain() +
                   R"(" target="_blank">)" + qApp->organizationName() + "</a></div>";
            str += "<div>Locale : " + QLocale::system().name() + "</div>";
            str += "<div>OS : " + QSysInfo::prettyProductName() + "</div>";
            str += "<div>CPU : " + QSysInfo::currentCpuArchitecture() + "</div>";

            auto info = new QLabel(str, this);
            layout->addWidget(info);
            info->setOpenExternalLinks(true);
        }
    }

    setFixedSize(sizeHint());
    show();
}

void InfoWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        close();
    }
}