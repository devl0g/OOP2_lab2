#include "mainWindow.hpp"
#include "../../utils/logger.hpp"
#include "../../config.hpp"
#include <QApplication>
#include <QWidget>
#include "../components/shapesCanvas.hpp"

MainWindow::MainWindow(QWidget* parent) noexcept : 
  QMainWindow(parent) {

  initUI();
}

MainWindow::~MainWindow() noexcept {
  Logger::info("window closed");
}

// UI

void MainWindow::initUI() noexcept {
  setWindowTitle(tr(WINDOW_TITLE));
  implementMenuBar();

  setCentralWidget(new ShapesCanvas(this));
}

void MainWindow::implementMenuBar() noexcept {
}
