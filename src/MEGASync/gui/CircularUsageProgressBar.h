#ifndef CIRCULARUSAGEPROGRESSBAR_H
#define CIRCULARUSAGEPROGRESSBAR_H

#include <QWidget>
#include <QPen>
#include <QIcon>

#define ALMOSTOVERQUOTA_VALUE 90

const char DEFAULT_FGCOLOR[] = "#00BFA5";
const char DEFAULT_BKCOLOR[] = "#E5E5E5";
const char DEFAULT_OQCOLOR[] = "#DF4843";
const char DEFAULT_ALMOSTOQCOLOR[] = "#F98400";
const char DEFAULT_FGCOLOR_QUOTA[] = "#8DD0EF";
const char DEFAULT_TEXT_COLOR[] = "#000000";

class CircularUsageProgressBar : public QWidget
{
    Q_OBJECT
public:
    static const int MAXVALUE = 100;
    static const int MINVALUE = 0;
    explicit CircularUsageProgressBar(QWidget *parent = 0);

    int getValue() const;
    void setValue(int value);
    void setEmptyBarTotalValueUnknown();
    void setFullBarTotalValueUnkown();

    QColor getBackgroundColor() const;
    void setBackgroundColor(const QColor &color);

    QColor getForegroundColor() const;
    void setForegroundColor(const QColor &color);

    QColor getOverquotaColor() const;
    void setOverquotaColor(const QColor &color);

    QColor getAlmostOverquotaColor() const;
    void setAlmostOverquotaColor(const QColor &color);

protected:
    void paintEvent(QPaintEvent *event);
    void drawBackgroundBar(QPainter &p, QRectF &baseRect);
    void drawArcValue(QPainter &p, const QRectF &baseRect, double arcLength);
    void drawText(QPainter &p, const QRectF &innerRect, double innerRadius, double progressBarValue);
    void setPenColor(QPen &pen, QColor color, bool forceRepaint = true);
    void setBarTotalValueUnkown(int value, const QColor& color);

    int progressBarValue = -1;
    double penWidth;
    double outerRadius;
    QString textValue;

    QColor backgroundColor;
    QColor foregroundColor;
    QColor overquotaColor;
    QColor almostOverquotaColor;
    QColor currentColor;

    QPen backgroundPen;
    QPen foregroundPen;

    const QIcon markWarning;
    const QIcon markFull;
    const QIcon dynamicTransferBlue;
    const QIcon dynamicTransferRed;
    bool totalValueUnkown;
};

#endif // CIRCULARUSAGEPROGRESSBAR_H
