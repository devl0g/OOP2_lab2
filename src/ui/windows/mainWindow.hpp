#ifndef INCLUDE_UI_WINDOWS_MAIN_WINDOW_HPP_
#define INCLUDE_UI_WINDOWS_MAIN_WINDOW_HPP_

#include <QWidget>
#include <QMainWindow>

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget* parent = nullptr) noexcept;
  ~MainWindow() noexcept;

private:
  void initUI() noexcept;
  void implementMenuBar() noexcept;

signals:
private slots:
};

#endif
