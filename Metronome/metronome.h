#ifndef METRONOME_H
#define METRONOME_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Metronome;
}
QT_END_NAMESPACE

class Metronome : public QMainWindow
{
    Q_OBJECT

public:
    Metronome(QWidget *parent = nullptr);
    ~Metronome();

private slots:
    void on_pushButton_clicked();

    void on_horizontalSlider_rangeChanged(int min, int max);

    void on_lcdNumber_overflow();

private:
    Ui::Metronome *ui;
    QTimer metronomeTimer;
};
#endif // METRONOME_H
