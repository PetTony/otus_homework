#include <string>
#include "document.h"

int main(void)
{
    auto doc = Document();
    doc.ImportDocument("path/to/file");
    const Shape::ShapePtr &circle = doc.CreateCircle(Point{5, 10}, 3);
    const Shape::ShapePtr &rectangle = doc.CreateRectangle(Point{15, 10}, 3, 4);
    const Shape::ShapePtr &line = doc.CreateLine(Point{8, 27}, 3);
    circle->SetColor(Color({255,56,123}));
    circle->Render();
    rectangle->Render();
    rectangle->Scale(3);
    rectangle->Move(Point{7, 35});
    rectangle->Render();
    line->Render();
    line->Rotate(45);
    line->Render();
    doc.ExportDocument();
    doc.ExportDocument("path/to/new/file");
    return 0;
}