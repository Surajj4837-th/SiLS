#ifndef SILS_H
#define SILS_H

#include <QMainWindow>
#include <pcl/visualization/pcl_visualizer.h>
#include <vtkRenderWindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class SiLS; }
QT_END_NAMESPACE

class SiLS : public QMainWindow
{
    Q_OBJECT

public:
    SiLS(QWidget *parent = nullptr);
    ~SiLS();

private:
    Ui::SiLS *ui;
    pcl::visualization::PCLVisualizer::Ptr viewer_3D;
};
#endif // SILS_H
