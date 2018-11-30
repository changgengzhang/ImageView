#include "ImageView.h"

ImageView::ImageView(QWidget *parent)
	: QGraphicsView(parent)
{
	this->setFocusPolicy(Qt::FocusPolicy::ClickFocus);

	m_scene = new QGraphicsScene();
	m_image = new QImage();
	m_rect = new QRect(0, 0, 0, 0);

	this->setScene(m_scene);
	m_isImageLoad = false;
	m_rectItem = nullptr;

	m_tlPoint = QPoint(0, 0);
	m_brPoint = QPoint(0, 0);
	
	setCursor(Qt::ArrowCursor);
	// this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	// this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}


ImageView::~ImageView()
{

}


void ImageView::paintEvent(QPaintEvent *paintEvent)
{
	if (!m_isImageLoad)
	{
		return;
	}
	
	QGraphicsView::paintEvent(paintEvent);

	QPainter painter(this->viewport());
}


void ImageView::mousePressEvent(QMouseEvent *mouseEvent)
{
	if (mouseEvent->button() == Qt::LeftButton)
	{
		QPoint localPoint = this->mapFromGlobal(mouseEvent->globalPos());
		QPointF imgPoint = this->mapToScene(localPoint);
		m_tlPoint = this->computeValidImagePoint(imgPoint);
		// std::cout << "Image x = " << m_tlPoint.x() << ", y = " << m_tlPoint.y() << "\n";
		
		setCursor(Qt::CrossCursor);
		mouseEvent->accept();
	}
	else if (mouseEvent->button() == Qt::RightButton)
	{
		m_isPan = true;
		m_panStart = mouseEvent->pos();
		setCursor(Qt::ClosedHandCursor);
		mouseEvent->accept();
	}
}


void ImageView::mouseMoveEvent(QMouseEvent *mouseEvent)
{
	if (mouseEvent->buttons() & Qt::LeftButton)
	{
		QPoint localPoint = this->mapFromGlobal(mouseEvent->globalPos());
		QPointF imgPoint = this->mapToScene(localPoint);
		m_brPoint = this->computeValidImagePoint(imgPoint);

		this->updateRectangle();
		this->viewport()->update();
		
		mouseEvent->accept();
	}
	else if (mouseEvent->buttons() & Qt::RightButton)
	{
		if (m_isPan)
		{
			horizontalScrollBar()->setValue(horizontalScrollBar()->value() - (mouseEvent->x() - m_panStart.x()));
			verticalScrollBar()->setValue(verticalScrollBar()->value() - (mouseEvent->y() - m_panStart.y()));
			m_panStart = mouseEvent->pos();
			mouseEvent->accept();
		}
	}
}

void ImageView::mouseReleaseEvent(QMouseEvent *mouseEvent)
{
	if (mouseEvent->button() == Qt::LeftButton)
	{
		QPoint localPoint = this->mapFromGlobal(mouseEvent->globalPos());
		QPointF imgPoint = this->mapToScene(localPoint);
		m_brPoint = this->computeValidImagePoint(imgPoint);
		// std::cout << "Image x = " << m_brPoint.x() << ", y = " << m_brPoint.y() << "\n";
		
		this->updateRectangle();
		this->viewport()->update();
		
		this->computeCellArea();

		setCursor(Qt::ArrowCursor);
		mouseEvent->accept();
	}
	else if (mouseEvent->button() == Qt::RightButton)
	{
		m_isPan = false;
		setCursor(Qt::ArrowCursor);
		mouseEvent->accept();
	}
}

void ImageView::keyPressEvent(QKeyEvent *keyEvent)
{
	switch (keyEvent->key())
	{
	case Qt::Key_D:
		
	default:
		break;
	}
}

void ImageView::wheelEvent(QWheelEvent *event)
{
	float delta = event->delta();
	if (event->modifiers() & Qt::ControlModifier)
	{
		double factor = pow(1.1, delta / abs(delta));
		this->scale(factor, factor);
	}
	else if (event->modifiers() & Qt::ShiftModifier)
	{
		// QGraphicsView::scrollContentsBy(delta, 0);
		this->verticalScrollBar()->event(event);
	}
	else 
	{
		this->horizontalScrollBar()->event(event);
	}
	this->viewport()->update();
}

void ImageView::slotLoadImage(QString imagePath)
{
	if (m_image->load(imagePath))
	{
		int h = m_image->height();
		int w = m_image->width();

		m_scene->clear();
		m_scene->addPixmap(QPixmap::fromImage(*m_image));
		m_scene->setSceneRect(0, 0, w, h);

		this->centerOn(w / 2, h / 2);
		this->viewport()->update();

		m_isImageLoad = true;
		m_tlPoint = QPoint(0, 0);
		m_brPoint = QPoint(0, 0);
		m_mask.clear();
	}
	else
	{
		m_scene->clear();
		m_isImageLoad = false;
		std::cout << "Load File Failed\n";
	}
}

void ImageView::slotOnPushButtonSaveCroppedImageClicked()
{
	QString saveCropedImageFilepath = QFileDialog::getSaveFileName(this, tr("Save Cropped Image"), "", tr("Image (*.png *.jepg *.jpg)"));
	if (saveCropedImageFilepath.isEmpty())
		return;

	QRect rect(m_tlPoint, m_brPoint);
	QImage croppedImg = m_image->copy(rect);

	croppedImg.save(saveCropedImageFilepath);
}

void ImageView::slotOnPushButtonSaveCroppedImageMaskClicked()
{
	QString saveCropedImageMaskFilepath = QFileDialog::getSaveFileName(this, tr("Save Cropped Image"), "", tr("Image (*.png *.jepg *.jpg)"));
	if (saveCropedImageMaskFilepath.isEmpty())
		return;

	QRect rect(m_tlPoint, m_brPoint);
	QImage croppedImg = m_image->copy(rect);

	int w = croppedImg.width();
	int h = croppedImg.height();
	
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (m_mask[i][j] == 1)
			{
				croppedImg.setPixel(i, j, qRgb(0, 255, 0));
			}
		}
	}
	croppedImg.save(saveCropedImageMaskFilepath);
}

//////////////////////////////////////////////////////////////////////////
// algorithm

void ImageView::computeCellArea()
{
	if (!m_isImageLoad)
	{
		return;
	}

	QRect rect(m_tlPoint, m_brPoint);
	QImage croppedImg = m_image->copy(rect);

	int w = croppedImg.width();
	int h = croppedImg.height();

	m_mask.clear();
	for (int i = 0; i < w; i++)
	{
		QVector<int> col(h, 0);
		m_mask.push_back(col);
	}

	int validPixelCount = 0;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			QColor p = croppedImg.pixel(i, j);
			if (p.red() + p.green() <= p.blue())
			{
				validPixelCount++;
				m_mask[i][j] = 1;
			}
		}
	}

	float ratio = 0.0f;
	if (w * h != 0)
	{
		ratio = (float)validPixelCount / (w * h) * 100.0f;
	}
	std::cout
		<< "Total Area " << w * h
		<< ", Cell Area " << validPixelCount
		<< ", Percentage is  %" << ratio
		<< "\n";
}

QPoint ImageView::computeValidImagePoint(QPointF p)
{
	QPoint q;
	
	if (p.x() < 0) q.setX(0);
	else if (p.x() >= m_image->width()) q.setX(m_image->width() - 1);
	else q.setX(p.x());

	if (p.y() < 0) q.setY(0);
	else if (p.y() >= m_image->height()) q.setY(m_image->height() - 1);
	else q.setY(p.y());

	return q;
}

void ImageView::updateRectangle()
{
	if (!m_isImageLoad)
	{
		false;
	}

	if (m_rectItem)
	{
		m_scene->removeItem(m_rectItem);
	}

	m_rect->setTopLeft(m_tlPoint);
	m_rect->setBottomRight(m_brPoint);

	QPen pen(Qt::red);

	m_rectItem = m_scene->addRect(*m_rect, pen);
}