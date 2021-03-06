#include "parameters.h"

Parameters::Parameters(QObject* parent) : QObject(parent)
{
}

Parameters::Parameters(QSize& collageSize, int& photoSize, int& nbPhotos, int& distanceBetweenPhotos, QPixmap& background, CollageForm form, QStringList photoList, QObject* parent) : QObject(parent) {
    this->collageSize = collageSize;
    this->photoSize = photoSize;
    this->nbPhotos = nbPhotos;
    this->distanceBetweenPhotos = distanceBetweenPhotos;
    this->background = background;
    this->form = form;
    this->photoList = photoList;
}

Parameters::Parameters(const Parameters& params) {
    this->collageSize = params.getCollageSize();
    this->photoSize = params.getPhotoSize();
    this->nbPhotos = params.getNbPhotos();
    this->distanceBetweenPhotos = params.getDistanceBetweenPhotos();
    this->background = params.getBackground();
    this->form = params.getForm();
    this->polygon = params.getPolygon();
    this->nbVertex = params.getNbVertex();
    this->photoList = params.getPhotoList();
    this->drawingAnimation = params.getDrawingAnimation();
}

QSize Parameters::getCollageSize() const
{
    return collageSize;
}

void Parameters::setCollageSize(const QSize &value)
{
    collageSize = value;
}
int Parameters::getPhotoSize() const
{
    return photoSize;
}

void Parameters::setPhotoSize(const int &value)
{
    photoSize = value;
}
int Parameters::getNbPhotos() const
{
    return nbPhotos;
}

void Parameters::setNbPhotos(const int &value)
{
    nbPhotos = value;
}
int Parameters::getDistanceBetweenPhotos() const
{
    return distanceBetweenPhotos;
}

void Parameters::setDistanceBetweenPhotos(const int &value)
{
    distanceBetweenPhotos = value;
}
QPixmap Parameters::getBackground() const
{
    return background;
}

void Parameters::setBackground(const QPixmap &value)
{
    background = value;
}
CollageForm Parameters::getForm() const
{
    return form;
}

void Parameters::setForm(const CollageForm &value)
{
    form = value;
}
QStringList Parameters::getPhotoList() const
{
    return photoList;
}

void Parameters::setPhotoList(const QStringList &value)
{
    photoList = value;
}
bool Parameters::getDrawingAnimation() const
{
    return drawingAnimation;
}

void Parameters::setDrawingAnimation(bool value)
{
    drawingAnimation = value;
}

QPolygon Parameters::getPolygon() const
{
    return polygon;
}

void Parameters::setPolygon(const QPolygon &value)
{
    polygon = value;
}
int Parameters::getNbVertex() const
{
    return nbVertex;
}

void Parameters::setNbVertex(int value)
{
    nbVertex = value;
}




QDebug operator <<(QDebug dbg, const Parameters& obj) {
    dbg.nospace() << "CollageSize: " << obj.getCollageSize().rheight() << "x" << obj.getCollageSize().rwidth();
    dbg.space() << "PhotoSize: " << obj.getPhotoSize();
    dbg.space() << "Nb Photos: " << obj.getNbPhotos();
    dbg.space() << "Distance: " << obj.getDistanceBetweenPhotos();
    dbg << "Background: " << obj.getBackground().isNull() << obj.getBackground().size().rheight() <<  "x" << obj.getBackground().size().rwidth();
    dbg.space() << "form: " << obj.getForm();
    dbg.space() << "PhotoList:";
    foreach (QString photo, obj.getPhotoList()) {
        dbg.space()<< photo;
    }
    return dbg.space();
}
