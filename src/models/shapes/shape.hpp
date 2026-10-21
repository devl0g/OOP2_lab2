#ifndef INCLUDE_MODEL_SHAPES_SHAPE_HPP_
#define INCLUDE_MODEL_SHAPES_SHAPE_HPP_

#include <QPainter>
#include <cstdint>

struct Position {
  int64_t x { 0 };
  int64_t y { 0 };
};

class Shape {
public:
  ~Shape() noexcept = default;

  [[nodiscard]] virtual char* getShapeName() noexcept = 0;
  [[nodiscard]] virtual uint8_t getShapeID() noexcept = 0;

  virtual void renderShape(QPainter& painter) = 0;
  virtual void renderPhantomShape(QPainter& painter) = 0;
  virtual void updateShapeConfig(const Position& drag_start, const Position& drag_end) noexcept = 0;
};

#endif
