#ifndef INCLUDE_MODEL_SHAPES_OVAL_HPP_
#define INCLUDE_MODEL_SHAPES_OVAL_HPP_

#include "./shape.hpp"
#include <cstdlib>

class OvalShape : public Shape {
public:
  OvalShape() = default;
  OvalShape(Position center_pos, Position corner_pos) : center_position(center_pos), corner_position(corner_pos) {};
  ~OvalShape() = default;
  OvalShape(const OvalShape& oval_shape) noexcept : center_position(oval_shape.center_position), corner_position(oval_shape.corner_position) {}
  OvalShape& operator=(OvalShape other) {
    this->center_position = other.center_position;
    this->corner_position = other.corner_position;
    return *this;
  }

  [[nodiscard]] Position getCenterPosition() const {
    return center_position;
  }

  void setCenterPosition(Position position) {
    this->center_position = position;
  }

  [[nodiscard]] Position getCornerPosition() const {
    return corner_position;
  }

  void setCornerPosition(Position position) {
    this->corner_position = position;
  }

  char* getShapeName() const noexcept override {
    static char shape_name[] { "Овал" };
    return shape_name;
  }

  uint8_t getShapeID() const noexcept override {
    return 4;
  }

  std::unique_ptr<Shape> createInstance() const noexcept override {
    return std::make_unique<OvalShape>();
  }

  void renderShape(QPainter& painter) const override {
    painter.setBrush(Qt::NoBrush);
    QPen pen;
    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(2);
    painter.setPen(pen);

    Position half_size { 
      std::abs(center_position.x - corner_position.x),
      std::abs(center_position.y - corner_position.y)
    };

    painter.drawEllipse(
        center_position.x - half_size.x,
        center_position.y - half_size.y,
        half_size.x * 2,
        half_size.y * 2
    );
  }

  void renderPhantomShape(QPainter& painter) const override {
    painter.setBrush(Qt::NoBrush);
    QPen pen;
    pen.setColor(QColor(0, 0, 0, 100));
    pen.setWidth(2);
    painter.setPen(pen);

    Position half_size { 
      std::abs(center_position.x - corner_position.x),
      std::abs(center_position.y - corner_position.y)
    };

    painter.drawEllipse(
        center_position.x - half_size.x,
        center_position.y - half_size.y,
        half_size.x * 2,
        half_size.y * 2
    );
  }

  void updateShapeConfig(const Position& drag_start, const Position& drag_end) noexcept override {
    this->center_position = drag_start;
    this->corner_position = drag_end;
  }

private:
  Position center_position { 0, 0 };
  Position corner_position { 0, 0 };
};

#endif
