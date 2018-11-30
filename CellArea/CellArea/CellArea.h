#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QLabel>
#include "ui_CellArea.h"

#include "ImageView.h"

class CellArea : public QMainWindow
{
	Q_OBJECT

public:
	CellArea(QWidget *parent = Q_NULLPTR);
private:
	void connectSignalsAndSlots();

	private slots:
	void slotOnActionLoadImageTriggered();

signals:
	void signalLoadImage(QString path);

private:
	Ui::CellArea m_ui;
};
