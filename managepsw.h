#ifndef MANAGEPSW_H
#define MANAGEPSW_H

#include <QMainWindow>

namespace Ui {
class managepsw;
}

class managepsw : public QMainWindow
{
    Q_OBJECT

public:
    explicit managepsw(QWidget *parent = 0);
    ~managepsw();
public:
    void setupconnections();

public slots:
    void handlenewButtonClicked();
    void handlemodifyButtonClicked();
    void handledeleteButtonClicked();

    void handlefinishButtonClicked();

private:
    Ui::managepsw *ui;
};

#endif // MANAGEPSW_H
