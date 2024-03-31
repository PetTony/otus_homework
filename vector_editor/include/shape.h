#pragma once

#include <iostream>
#include "color.h"

struct Point
{
    int _x = 0;
    int _y = 0;
};

std::ostream& operator<<(std::ostream& stream, const Point &point)
{
    stream << "Point{"
       << point._x << ", "
       << point._y << "}";

    return stream;
}

class Shape
{
public:
    using ShapePtr = std::unique_ptr<Shape>;
    virtual ~Shape() = default;
    virtual void Render() = 0;
    virtual void Move(Point point) = 0;
    virtual void Scale(int scale) = 0;
    virtual void Rotate(int rotation_angle) = 0;

    void SetColor(const Color &shape_color)
    {
        _shape_color = shape_color;
    }
    Color GetColor()
    {
        return _shape_color;
    }
private:
    Color _shape_color{};
};

class Rectangle : public Shape
{
public:
    Rectangle(Point point, int width, int height) :
        _point(point),
        _width(width),
        _height(height)
        {}

    virtual void Render() override
    {
        std::cout << "Rectangle " << _point
            << ", Width{" << _width
            << "}, Height{" << _height
            << "}, Rotation{" << _rotation << "}, "
            << GetColor() << std::endl;
    }
    virtual void Move(Point point) override
    {
        _point = point;
    }
    virtual void Scale(int scale) override
    {
        if(scale)
        {
            _width *= scale;
            _height *= scale;
        }
    }
    virtual void Rotate(int rotation) override
    {
        _rotation = rotation;
    }
private:
    Point _point{};
    int _width{};
    int _height{};
    int _rotation{};
};

class Circle : public Shape
{
public:
    Circle(Point center, uint32_t radius) :
         _center(center), _radius(radius){}

    virtual void Render() override
    {
        std::cout << "Circle " << _center
            << ", Radius{" << _radius << "}, "
            << GetColor()
            << std::endl;
    }
    virtual void Move(Point p) override
    {
        _center = p;
    }
    virtual void Scale(int scale) override
    {
        if(scale)
        {
            _radius *= scale;
        }
    }
    virtual void Rotate(int rotation[[maybe_unused]]) override
    {
        return;
    }
private:
    Point _center{};
    uint32_t _radius{};
};

class Line : public Shape
{
public:
    Line(Point point, int length) :
        _point(point),
        _length(length){}

    virtual void Render() override
    {
        std::cout << "Line " << _point
        << ", Length{" << _length
        << "}, Rotation{" << _rotation << "}, "
        << GetColor()
        <<std::endl;
    }

    virtual void Move(Point point) override
    {
        _point = point;
    }

    virtual void Scale(int scale) override
    {
        if(scale)
        {
            _length *= scale;
        }
    }

    virtual void Rotate(int rotation) override
    {
        _rotation = rotation;
    }
private:
    Point _point{};
    int _length{};
    int _rotation{};
};
