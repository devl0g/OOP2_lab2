#ifndef INCLUDE_MODEL_SHAPES_RECTANGLE_HPP_
#define INCLUDE_MODEL_SHAPES_RECTANGLE_HPP_

#include "./shape.hpp"
#include <memory>

class RectangleShape : public Shape {
public:
  RectangleShape() = default;
  RectangleShape(Position a_pos, Position b_pos) : start_position(a_pos), end_position(b_pos) {};
  ~RectangleShape() = default;
  RectangleShape(const RectangleShape& rect_shape) noexcept : start_position(rect_shape.start_position), end_position(rect_shape.end_position) {}
  RectangleShape& operator=(RectangleShape other) {
    this->start_position = other.start_position;
    this->end_position = other.end_position;
    return *this;
  }

  [[nodiscard]] Position getStartPosition() const {
    return start_position;
  }

  void setStartPosition(Position position) {
    this->start_position = position;
  }

  [[nodiscard]] Position getEndPosition() const {
    return start_position;
  }

  void setEndPosition(Position position) {
    this->end_position = position;
  }

  char* getShapeName() const noexcept override {
    static char shape_name[] { "Прямокутник" };
    return shape_name;
  }

  uint8_t getShapeID() const noexcept override {
    return 3;
  }

  std::unique_ptr<Shape> createInstance() const noexcept override {
    return std::make_unique<RectangleShape>();
  }

  void renderShape(QPainter& painter) const override {
    painter.setBrush(QBrush(QColor(255, 255, 0)));
    QPen pen;
    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawRect(start_position.x, start_position.y, end_position.x - start_position.x, end_position.y - start_position.y);
  }

  void renderPhantomShape(QPainter& painter) const override {
    painter.setBrush(Qt::NoBrush);
    QPen pen;
    pen.setColor(QColor(0, 0, 0, 100));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawRect(start_position.x, start_position.y, end_position.x - start_position.x, end_position.y - start_position.y);
  }

  void updateShapeConfig(const Position& drag_start, const Position& drag_end) noexcept override {
    this->start_position = drag_start;
    this->end_position = drag_end;
  }

private:
  Position start_position { 0, 0 };
  Position end_position { 0, 0 };
};

#endif
