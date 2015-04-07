
#pragma once


#include <reflectionzeug/new/ArrayAccessorValue.h>


namespace reflectionzeug
{


// Read/write accessor
template <typename Type, size_t Size>
ArrayAccessorValue<Type, Size>::ArrayAccessorValue()
{
}

template <typename Type, size_t Size>
ArrayAccessorValue<Type, Size>::ArrayAccessorValue(const std::array<Type, Size> & defaultValue)
: m_value(defaultValue)
{
}

template <typename Type, size_t Size>
ArrayAccessorValue<Type, Size>::~ArrayAccessorValue()
{
}

template <typename Type, size_t Size>
std::array<Type, Size> ArrayAccessorValue<Type, Size>::getValue() const
{
    return m_value;
}

template <typename Type, size_t Size>
void ArrayAccessorValue<Type, Size>::setValue(const std::array<Type, Size> & value)
{
    m_value = value;
}

template <typename Type, size_t Size>
Type ArrayAccessorValue<Type, Size>::getValue(size_t i) const
{
    return m_value[i];
}

template <typename Type, size_t Size>
void ArrayAccessorValue<Type, Size>::setValue(size_t i, const Type & value)
{
    m_value[i] = value;
}


// Read-only accessor
template <typename Type, size_t Size>
ArrayAccessorValue<const Type, Size>::ArrayAccessorValue()
{
}

template <typename Type, size_t Size>
ArrayAccessorValue<const Type, Size>::ArrayAccessorValue(const std::array<Type, Size> & defaultValue)
: m_value(defaultValue)
{
}

template <typename Type, size_t Size>
ArrayAccessorValue<const Type, Size>::~ArrayAccessorValue()
{
}

template <typename Type, size_t Size>
std::array<Type, Size> ArrayAccessorValue<const Type, Size>::getValue() const
{
    return m_value;
}

template <typename Type, size_t Size>
Type ArrayAccessorValue<const Type, Size>::getValue(size_t i) const
{
    return m_value[i];
}


} // namespace reflectionzeug
