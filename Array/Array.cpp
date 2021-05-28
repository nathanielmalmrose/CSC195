#include "Array.h"

//nc::array::array()
//{
//}
//
//nc::array::array(const std::initializer_list<T>& ilist)
//{
//    size_t i = 0;
//    for (auto iter = ilist.begin(); iter != ilist.end(); iter++)
//    {
//        m_elements[i] = *iter;
//        i++;
//    }
//}
//
//int& nc::array::operator[](size_t position)
//{
//    return m_elements[position];
//}
//
//const int& nc::array::operator[](size_t position) const
//{
//    return m_elements[position];
//}
//
//int& nc::array::at(size_t position)
//{
//    return m_elements[position];
//}
//
//const int& nc::array::at(size_t position) const
//{
//    return m_elements[position];
//}
//
//int& nc::array::front()
//{
//    return m_elements[0];
//}
//
//int& nc::array::back()
//{
//    return m_elements[9];
//}
//
//int* nc::array::data()
//{
//    return m_elements;
//}
//
//void nc::array::fill(int value)
//{
//    for (int i = 0; i < 10; i++)
//    {
//        m_elements[i] = value;
//    }
//}
//
//void nc::array::swap(array& other)
//{
//    nc::array temp{ other };
//    for (int i = 0; i < m_size; i++)
//    {
//        other.m_elements[i] = this->m_elements[i];
//        this->m_elements[i] = temp[i];
//    };
//}
//
//bool nc::array::empty() const
//{
//    bool IsEmpty;
//    if (m_size == 0) {
//        IsEmpty = true;
//    }
//    else
//    {
//        IsEmpty = false;
//    }
//    return IsEmpty;
//}
//
//size_t nc::array::size() const
//{
//    return m_size;
//}
