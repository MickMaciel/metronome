#include "metronome.h"
#include "./ui_metronome.h"

Metronome::Metronome(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Metronome)
{
    ui->setupUi(this);

    // Define o intervalo do slider e o valor inicial
    ui->horizontalSlider->setRange(20, 300);
    ui->horizontalSlider->setValue(120);

    // Conecta o sinal valueChanged do slider ao lcdNumber
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &Metronome::on_lcdNumber_overflow);
}

Metronome::~Metronome()
{
    delete ui;
}

void Metronome::on_pushButton_clicked()
{
    if (ui->pushButton->text() == "Play") {
        ui->pushButton->setText("Pause");

        // pega o valor bpm e converte para ms
        int bpm = ui->horizontalSlider->value();
        int ms = static_cast<int>(60000 / bpm);

        metronomeTimer.start(ms);

    } else {
        // Alterna para "Play"
        ui->pushButton->setText("Play");

        metronomeTimer.stop();
    }
}

void Metronome::on_horizontalSlider_rangeChanged(int min, int max) {}

void Metronome::on_lcdNumber_overflow()
{
    ui->lcdNumber->display(ui->horizontalSlider->value());
}
