#pragma once

#include <iostream>
#include <vector>
#include <filesystem>
#include <unordered_set>
#include "file.h"
#include "shape.h"

class Document
{
public:
    Document() = default;

    ~Document() = default;

    bool ImportDocument(const std::filesystem::path &path)
    {
        _file.Open(path);
        _file_is_open = true;
        buffer data = _file.Read();
        return Deserialize(data);
    }

    bool ExportDocument()
    {
        if (!_file_is_open)
        {
            std::cout << "No file to save" << std::endl;
            return false;
        }
        return Serialize();
    }

    bool ExportDocument(const std::filesystem::path &path)
    {
        _file.Open(path);
        _file_is_open = true;
        return Serialize();
    }

    void Render()
    {
        for (auto &shape : _shapes)
            shape->Render();
    }

    const Shape::ShapePtr &CreateRectangle(Point point, int width, int height)
    {
        auto [a, b] = _shapes.emplace(std::make_unique<Rectangle>(point, width, height));
        return *a;
    }

    const Shape::ShapePtr &CreateCircle(Point center, uint32_t radius)
    {
        auto [a, b] = _shapes.emplace(std::make_unique<Circle>(center, radius));
        return *a;
    }

    const Shape::ShapePtr &CreateLine(Point point, int length)
    {
        auto [a, b] = _shapes.emplace(std::make_unique<Line>(point, length));
        return *a;
    }

    void DeleteShape(const Shape::ShapePtr &shape)
    {
        _shapes.erase(shape);
    }

private:
    File _file{};
    bool _file_is_open{};
    std::unordered_set<Shape::ShapePtr> _shapes{};

private:
    bool Serialize()
    {
        std::cout << "Serialized" << std::endl;
        buffer data{};
        _file.Write(data);
        return true;
    }

    bool Deserialize(const buffer &data[[maybe_unused]])
    {
        std::cout << "Deserialized" << std::endl;
        return true;
    }
};
