#pragma once

#include <propertyguizeug/PropertyEditor.h>
#include <signalzeug/Connection.h>

namespace reflectionzeug
{
    class EnumPropertyInterface;
}

namespace propertyguizeug
{

class PROPERTYGUIZEUG_API EnumEditor : public PropertyEditor
{
public:
    using Type = reflectionzeug::EnumPropertyInterface;
    
public:
    EnumEditor(reflectionzeug::EnumPropertyInterface * property, 
               QWidget * parent = nullptr);
    virtual ~EnumEditor();
    
    void setString(const QString & text);

private:
    reflectionzeug::EnumPropertyInterface * m_property;
    signalzeug::Connection m_propertyChangedConnection;
};

} // namespace propertyguizeug
