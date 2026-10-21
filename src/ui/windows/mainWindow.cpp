#include "mainWindow.hpp"
#include "../../utils/logger.hpp"
#include "../../config.hpp"
#include <QApplication>
#include <QWidget>

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

  auto *centralContainer = new QWidget(this);
  setCentralWidget(centralContainer);
}

void MainWindow::implementMenuBar() noexcept {
}
