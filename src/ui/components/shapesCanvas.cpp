#include "shapesCanvas.hpp"
#include <QPaintEvent>

void ShapesCanvas::paintEvent(QPaintEvent* event) {
  Q_UNUSED(event);

  QPainter painter(this);
    
  painter.setRenderHint(QPainter::Antialiasing);
  painter.fillRect(rect(), QColor(255, 255, 255));

  for (const auto& shape : canvasShapes) {
    shape->renderShape(painter);
  }

  if (drawingShape) {
    drawingShape->renderPhantomShape(painter);
  }
}

void ShapesCanvas::mousePressEvent(QMouseEvent* event) {
  if (event->button() == Qt::MouseButton::LeftButton) {
    const auto position = event->pos();

    mouseState.isDragging = true;
    mouseState.dragStartX = position.x();
    mouseState.dragStartY = position.y();
    mouseState.dragEndX = position.x();
    mouseState.dragEndY = position.y();

    if (currentShapeType) {
      drawingShape = currentShapeType->createInstance();
      drawingShape->updateShapeConfig({ mouseState.dragStartX, mouseState.dragStartY }, { mouseState.dragEndX, mouseState.dragEndY });
    }
  }
}

void ShapesCanvas::mouseMoveEvent(QMouseEvent* event) {
  const auto position = event->pos();

  mouseState.dragEndX = position.x();
  mouseState.dragEndY = position.y();

  if (drawingShape) {
    drawingShape->updateShapeConfig({ mouseState.dragStartX, mouseState.dragStartY }, { mouseState.dragEndX, mouseState.dragEndY });
    update();
  }
}

void ShapesCanvas::mouseReleaseEvent(QMouseEvent* event) {
  if (event->button() == Qt::MouseButton::LeftButton && mouseState.isDragging) {
    mouseState.isDragging = false;

    if (drawingShape) {
      if (canvasShapes.size() >= 112) {
        canvasShapes.erase(canvasShapes.begin() + 0);
      }

      canvasShapes.push_back(std::move(drawingShape));
    }

    update();
  }
}
