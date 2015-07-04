
#include <gmock/gmock.h>

#include <string>

#include <reflectionzeug/property/Property.h>

#include "../MyObject.h"

using namespace reflectionzeug;



class PropertyInstanceInt8_T_test : public testing::Test
{
public:
    PropertyInstanceInt8_T_test()
    {
    }

protected:
};


// Propterty instanciaton (read/write)

TEST_F(PropertyInstanceInt8_T_test, instanciatePropertyWith_String_LambdaGetter_LambdaSetter)
{
    auto get = [] () {return 0;};
    auto set = [] (const int8_t & val) {};

    auto prop = new Property<int8_t>("int8_tProperty", get, set);

    ASSERT_EQ(typeid(int8_t), prop->type());

    delete prop;
}

TEST_F(PropertyInstanceInt8_T_test, instanciatePropertyWith_String_Object_ConstGetterConst_SetterConst)
{
    auto obj = new MyObject<int8_t>;
    auto prop = new Property<int8_t>("int8_tProperty", obj, &MyObject<int8_t>::constgetterconst, &MyObject<int8_t>::setterconst);

    ASSERT_EQ(typeid(int8_t), prop->type());


    delete prop;
    delete obj;
}

TEST_F(PropertyInstanceInt8_T_test, instanciatePropertyWith_String_Object_GetterConst_SetterConst)
{
    auto obj = new MyObject<int8_t>;
    auto prop = new Property<int8_t>("int8_tProperty", obj, &MyObject<int8_t>::getterconst, &MyObject<int8_t>::setterconst);

    ASSERT_EQ(typeid(int8_t), prop->type());


    delete prop;
    delete obj;
}

TEST_F(PropertyInstanceInt8_T_test, instanciatePropertyWith_String_Object_GetterConst_Setter)
{
    auto obj = new MyObject<int8_t>;
    auto prop = new Property<int8_t>("int8_tProperty", obj, &MyObject<int8_t>::getterconst, &MyObject<int8_t>::setter);

    ASSERT_EQ(typeid(int8_t), prop->type());


    delete prop;
    delete obj;
}


// Propterty instanciaton (read only)

TEST_F(PropertyInstanceInt8_T_test, instanciateConstPropertyWith_String_LambdaGetter_LambdaSetter)
{
    auto get = [] () {return 0;};

    auto prop = new Property<const int8_t>("int8_tProperty", get);

    ASSERT_EQ(typeid(int8_t), prop->type());

    delete prop;
}

TEST_F(PropertyInstanceInt8_T_test, instanciateConstPropertyWith_String_Object_ConstGetterConst_SetterConst)
{
    auto obj = new MyObject<int8_t>;
    auto prop = new Property<const int8_t>("int8_tProperty", obj, &MyObject<int8_t>::constgetterconst);

    ASSERT_EQ(typeid(int8_t), prop->type());


    delete prop;
    delete obj;
}

TEST_F(PropertyInstanceInt8_T_test, instanciateConstPropertyWith_String_Object_GetterConst_SetterConst)
{
    auto obj = new MyObject<int8_t>;
    auto prop = new Property<const int8_t>("int8_tProperty", obj, &MyObject<int8_t>::getterconst);

    ASSERT_EQ(typeid(int8_t), prop->type());


    delete prop;
    delete obj;
}



// Propterty instanciaton with Accessor (read/write)

TEST_F(PropertyInstanceInt8_T_test, instanciateAccessorWith_String)
{
    auto accessor = new AccessorValue<int8_t>();
    auto prop = new Property<int8_t>("int8_tProperty", accessor);

    ASSERT_EQ(typeid(int8_t), prop->type());

    delete prop;
}

TEST_F(PropertyInstanceInt8_T_test, instanciateAccessorWith_String_Value)
{
    auto accessor = new AccessorValue<int8_t>(0);
    auto prop = new Property<int8_t>("int8_tProperty", accessor);

    ASSERT_EQ(typeid(int8_t), prop->type());

    delete prop;
}

TEST_F(PropertyInstanceInt8_T_test, instanciateAccessorWith_String_LambdaGetter_LambdaSetter)
{
    auto get = [] () {return 0;};
    auto set = [] (const int8_t & val) {};
    auto accessor = new AccessorGetSet<int8_t>(get, set);

    auto prop = new Property<int8_t>("int8_tProperty", accessor);

    ASSERT_EQ(typeid(int8_t), prop->type());

    delete prop;
}

TEST_F(PropertyInstanceInt8_T_test, instanciateAccessorWith_String_Object_ConstGetterConst_SetterConst)
{
    auto obj = new MyObject<int8_t>;
    auto accessor = new AccessorGetSet<int8_t>(obj, &MyObject<int8_t>::constgetterconst, &MyObject<int8_t>::setterconst);
    auto prop = new Property<int8_t>("int8_tProperty", accessor);

    ASSERT_EQ(typeid(int8_t), prop->type());


    delete prop;
    delete obj;
}

TEST_F(PropertyInstanceInt8_T_test, instanciateAccessorWith_String_Object_GetterConst_SetterConst)
{
    auto obj = new MyObject<int8_t>;
    auto accessor = new AccessorGetSet<int8_t>(obj, &MyObject<int8_t>::getterconst, &MyObject<int8_t>::setterconst);
    auto prop = new Property<int8_t>("int8_tProperty", accessor);

    ASSERT_EQ(typeid(int8_t), prop->type());


    delete prop;
    delete obj;
}

TEST_F(PropertyInstanceInt8_T_test, instanciateAccessorWith_String_Object_GetterConst_Setter)
{
    auto obj = new MyObject<int8_t>;
    auto accessor = new AccessorGetSet<int8_t>(obj, &MyObject<int8_t>::getterconst, &MyObject<int8_t>::setter);
    auto prop = new Property<int8_t>("int8_tProperty", accessor);

    ASSERT_EQ(typeid(int8_t), prop->type());


    delete prop;
    delete obj;
}


// Propterty instanciaton with Accessor (read only)

TEST_F(PropertyInstanceInt8_T_test, instanciateConstAccessorWith_String)
{
    auto accessor = new AccessorValue<const int8_t>();
    auto prop = new Property<const int8_t>("int8_tProperty", accessor);

    ASSERT_EQ(typeid(int8_t), prop->type());

    delete prop;
}

TEST_F(PropertyInstanceInt8_T_test, instanciateConstAccessorWith_String_Value)
{
    auto accessor = new AccessorValue<const int8_t>(0);
    auto prop = new Property<int8_t>("int8_tProperty", accessor);

    ASSERT_EQ(typeid(int8_t), prop->type());

    delete prop;
}

TEST_F(PropertyInstanceInt8_T_test, instanciateConstAccessorWith_String_LambdaGetter_LambdaSetter)
{
    auto get = [] () {return 0;};
    auto accessor = new AccessorGetSet<const int8_t>(get);

    auto prop = new Property<const int8_t>("int8_tProperty", accessor);

    ASSERT_EQ(typeid(int8_t), prop->type());

    delete prop;
}

TEST_F(PropertyInstanceInt8_T_test, instanciateConstAccessorWith_String_Object_ConstGetterConst_SetterConst)
{
    auto obj = new MyObject<int8_t>;
    auto accessor = new AccessorGetSet<const int8_t>(obj, &MyObject<int8_t>::constgetterconst);
    auto prop = new Property<const int8_t>("int8_tProperty", accessor);

    ASSERT_EQ(typeid(int8_t), prop->type());


    delete prop;
    delete obj;
}

TEST_F(PropertyInstanceInt8_T_test, instanciateConstAccessorWith_String_Object_GetterConst_SetterConst)
{
    auto obj = new MyObject<int8_t>;
    auto accessor = new AccessorGetSet<const int8_t>(obj, &MyObject<int8_t>::getterconst);
    auto prop = new Property<const int8_t>("int8_tProperty", accessor);

    ASSERT_EQ(typeid(int8_t), prop->type());


    delete prop;
    delete obj;
}
