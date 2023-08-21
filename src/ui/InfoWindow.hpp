#pragma once

#include <QDialog>

class InfoWindow : public QDialog
{
    Q_OBJECT

  public:
    InfoWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

  protected:
    void keyPressEvent(QKeyEvent *event) override;

  private:
    Q_DISABLE_COPY(InfoWindow)
};
