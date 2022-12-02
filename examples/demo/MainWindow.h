/**
 * @file MainWindow.h
 * @author moth (QianMoth@qq.com)
 * @brief
 * @version 0.0.1
 * @date 2022-12-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <QMainWindow>

class DebugDemo;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    DebugDemo *_output;
};
