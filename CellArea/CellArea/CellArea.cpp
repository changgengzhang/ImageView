#include "CellArea.h"

CellArea::CellArea(QWidget *parent)
	: QMainWindow(parent)
{
	m_ui.setupUi(this);
	this->connectSignalsAndSlots();
}

void CellArea::connectSignalsAndSlots()
{
	connect(m_ui.actionLoadImage, SIGNAL(triggered()), this, SLOT(slotOnActionLoadImageTriggered()));
	connect(this, SIGNAL(signalLoadImage(QString)), m_ui.imageView, SLOT(slotLoadImage(QString)));
	connect(m_ui.pushButtonSaveCroppedImage, SIGNAL(clicked()), m_ui.imageView, SLOT(slotOnPushButtonSaveCroppedImageClicked()));
	connect(m_ui.pushButtonSaveCroppedImageMask, SIGNAL(clicked()), m_ui.imageView, SLOT(slotOnPushButtonSaveCroppedImageMaskClicked()));
}


//////////////////////////////////////////////////////////////////////////
// slots
void CellArea::slotOnActionLoadImageTriggered()
{
	QString getImageFilepath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image (*.png *.jepg *.jpg)"));
	if (getImageFilepath.isEmpty())
		return;
	
	m_ui.messageShow->setText(getImageFilepath);
	
	emit signalLoadImage(getImageFilepath);
}
