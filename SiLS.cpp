#include "SiLS.h"
#include "./ui_SiLS.h"

SiLS::SiLS(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SiLS)
{
    ui->setupUi(this);

    viewer_3D.reset (new pcl::visualization::PCLVisualizer ("viewer_3D", false));
    viewer_3D->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());
    ui->qvtkWidget->SetRenderWindow(viewer_3D->getRenderWindow());
}

SiLS::~SiLS()
{
    delete ui;
    //viewer_3D.reset();
    //cout << viewer_3D.use_count() << endl;
}

