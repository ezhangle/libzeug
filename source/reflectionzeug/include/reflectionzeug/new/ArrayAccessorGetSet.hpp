
#pragma once


#include <reflectionzeug/new/ArrayAccessorGetSet.h>


namespace reflectionzeug
{


// Read/write accessor
template <typename Type, size_t Size>
ArrayAccessorGetSet<Type, Size>::ArrayAccessorGetSet(
    const std::function<Type (size_t)> & getter,
    const std::function<void(size_t, const Type &)> & setter)
: m_getter(getter)
, m_setter(setter)
{
}

template <typename Type, size_t Size>
template <class Object>
ArrayAccessorGetSet<Type, Size>::ArrayAccessorGetSet(
    Object * object,
    const Type & (Object::*getter_pointer)(size_t) const,
    void (Object::*setter_pointer)(size_t, const Type &))
: m_getter(std::bind(getter_pointer, object))
, m_setter(std::bind(setter_pointer, object, std::placeholders::_1))
{
}

template <typename Type, size_t Size>
template <class Object>
ArrayAccessorGetSet<Type, Size>::ArrayAccessorGetSet(
    Object * object,
    Type (Object::*getter_pointer)(size_t) const,
    void (Object::*setter_pointer)(size_t, const Type &))
: m_getter(std::bind(getter_pointer, object))
, m_setter(std::bind(setter_pointer, object, std::placeholders::_1))
{
}

template <typename Type, size_t Size>
template <class Object>
ArrayAccessorGetSet<Type, Size>::ArrayAccessorGetSet(
    Object * object,
    Type (Object::*getter_pointer)(size_t) const,
    void (Object::*setter_pointer)(size_t, Type))
: m_getter(std::bind(getter_pointer, object))
, m_setter(std::bind(setter_pointer, object, std::placeholders::_1))
{
}

template <typename Type, size_t Size>
ArrayAccessorGetSet<Type, Size>::~ArrayAccessorGetSet()
{
}

template <typename Type, size_t Size>
std::array<Type, Size> ArrayAccessorGetSet<Type, Size>::getValue() const
{
    std::array<Type, Size> array;
    for (size_t i = 0; i < Size; ++i) {
        array[i] = m_getter(i);
    }

    return array;
}

template <typename Type, size_t Size>
void ArrayAccessorGetSet<Type, Size>::setValue(const std::array<Type, Size> & array)
{
    for (size_t i = 0; i < Size; ++i) {
        m_setter(i, array[i]);
    }
}

template <typename Type, size_t Size>
Type ArrayAccessorGetSet<Type, Size>::getValue(size_t i) const
{
    return m_getter(i);
}

template <typename Type, size_t Size>
void ArrayAccessorGetSet<Type, Size>::setValue(size_t i, const Type & value)
{
    m_setter(i, value);
}


// Read-only accessor
template <typename Type, size_t Size>
ArrayAccessorGetSet<const Type, Size>::ArrayAccessorGetSet(
    const std::function<Type (size_t)> & getter)
: m_getter(getter)
{
}

template <typename Type, size_t Size>
template <class Object>
ArrayAccessorGetSet<const Type, Size>::ArrayAccessorGetSet(
    Object * object,
    const Type & (Object::*getter_pointer)(size_t) const)
: m_getter(std::bind(getter_pointer, object))
{
}

template <typename Type, size_t Size>
template <class Object>
ArrayAccessorGetSet<const Type, Size>::ArrayAccessorGetSet(
    Object * object,
    Type (Object::*getter_pointer)(size_t) const)
: m_getter(std::bind(getter_pointer, object))
{
}

template <typename Type, size_t Size>
ArrayAccessorGetSet<const Type, Size>::~ArrayAccessorGetSet()
{
}

template <typename Type, size_t Size>
std::array<Type, Size> ArrayAccessorGetSet<const Type, Size>::getValue() const
{
    std::array<Type, Size> array;
    for (size_t i = 0; i < Size; ++i) {
        array[i] = m_getter(i);
    }

    return array;
}

template <typename Type, size_t Size>
Type ArrayAccessorGetSet<const Type, Size>::getValue(size_t i) const
{
    return m_getter(i);
}


} // namespace reflectionzeug
