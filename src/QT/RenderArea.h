#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QObject>
#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    
signals:
    
};

#endif // RENDERAREA_H
