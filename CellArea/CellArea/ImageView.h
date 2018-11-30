#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QPoint>
#include <QString>
#include <QEvent>
#include <QMouseEvent>
#include <QApplication>
#include <QRect>
#include <QVector>
#include <QSize>
#include <QFileDialog>
#include <QScrollBar>

#include <iostream>

class ImageView : public QGraphicsView
{
	Q_OBJECT
	//////////////////////////////////////////////////////////////////////////
	// functions
public:
	ImageView(QWidget *parent);
	~ImageView();

protected:
	void paintEvent(QPaintEvent *paintEvent) override;
	void mousePressEvent(QMouseEvent *mouseEvent) override;
	void mouseMoveEvent(QMouseEvent *mouseEvent) override;
	void mouseReleaseEvent(QMouseEvent *mouseEvent) override;
	void keyPressEvent(QKeyEvent *keyEvent) override;
	void wheelEvent(QWheelEvent *wheelEvent) override;

	public slots:
	void slotLoadImage(QString imagePath);
	void slotOnPushButtonSaveCroppedImageClicked();
	void slotOnPushButtonSaveCroppedImageMaskClicked();

private:
	void computeCellArea();

	QPoint computeValidImagePoint(QPointF p);
	void updateRectangle();

	//////////////////////////////////////////////////////////////////////////
	// values
private:
	bool m_isImageLoad;
	
	QGraphicsScene *m_scene;
	QImage *m_image;
	QVector<QVector<int>> m_mask;
	QRect *m_rect;
	QGraphicsItem *m_rectItem;

	QPoint m_tlPoint;
	QPoint m_brPoint;

	bool m_isPan;
	QPoint m_panStart;
};
