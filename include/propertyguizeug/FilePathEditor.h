
#pragma once

#include <propertyguizeug/propertyguizeug.h>

#include <QLineEdit>

class QFileDialog;
class QHBoxLayout;

namespace zeug {

template <typename Type>
class Property;
class FilePath;
    
class PROPERTYGUIZEUG_API FilePathEditor : public QLineEdit
{
public:
    FilePathEditor(Property<FilePath> * property, QWidget * parent = nullptr);
    virtual ~FilePathEditor();
    
    void setFilePath();
    void handleItemActivated(const QString & text);
    
    QStringList recentlyUsedFilePaths();
    void pushRecentlyUsedFilePath(const QString & filePath);
    
    void openFileDialog();

protected:
    static const QString s_openFileDialog;
    
    Property<FilePath> * m_property;
    bool m_dialogOpened;
    QString m_filePathFromDialog;
    
};

} // namespace
