#include "mainwindow.h"

#include <QApplication>
#include <QCamera>
#include <QVideoWidget>
#include <QImageCapture>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMediaCaptureSession>
#include <QWidget>
#include <QMediaDevices>
#include <QFileDialog>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Camera Object
    QCamera *camera = new QCamera(QMediaDevices::defaultVideoInput());

    // Widget to display the camera feed
    QVideoWidget *VidWidget = new QVideoWidget;

    // Create MediaCapture session
    QMediaCaptureSession *captureSession = new QMediaCaptureSession;
    captureSession->setCamera(camera);
    captureSession->setVideoOutput(VidWidget);

    // Create an image capture object
    QImageCapture *imageCapture = new QImageCapture;
    captureSession->setImageCapture(imageCapture);

    // Button to capture images
    QPushButton *captureBtn = new QPushButton("Capture Image", &w);

    // Connect the button to capture the image and save it to a file
    QObject::connect(captureBtn, &QPushButton::clicked, &w, [imageCapture, &w]() {
        QString fileName = QFileDialog::getSaveFileName(&w, "Save Image", "", "Images (*.png)");
        if (!fileName.isEmpty()) {
            if (!fileName.endsWith(".png", Qt::CaseInsensitive)) {
                fileName += ".png";
            }

            // Connect the imageCaptured signal to save the image
            QObject::connect(imageCapture, &QImageCapture::imageCaptured, &w, [fileName](int id, const QImage &image) {
                if (image.save(fileName)) {
                    qDebug() << "Image saved successfully at:" << fileName;
                } else {
                    qDebug() << "Failed to save image.";
                }
            });

            imageCapture->capture();
        }
    });

    // Error handling
    /*QObject::connect(imageCapture, &QImageCapture::errorOccurred, &w, [](QImageCapture::Error error, const QString &errorString) {
        qDebug() << "Error capturing image:" << error << errorString;
    });*/

    // Layout setup
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(VidWidget);
    layout->addWidget(captureBtn);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);

    w.setCentralWidget(centralWidget);
    w.show();

    // Start the camera
    camera->start();

    return a.exec();
}
