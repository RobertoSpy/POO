#include <iostream>
#include "Canvas.h"

using namespace std;

Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;
    this->canvas = new char* [height];
    for (int i = 0; i < height; ++i) {
        this->canvas[i] = new char[width];
        for (int j = 0; j < width; ++j) {
            this->canvas[i][j] = ' ';
        }
    }
}

Canvas::~Canvas() {
    
    for (int i = 0; i < this->height; ++i) {
        delete[] this->canvas[i];
    }
    delete[] this->canvas;
}

void Canvas::DrawCircle(int x, int y, int radius, char ch)
{ 
    int cx = radius;
    int cy = 0;
    int error = 0;

    while (cx >= cy) {
        SetPoint(x + cx, y + cy, ch);
        SetPoint(x + cy, y + cx, ch);
        SetPoint(x - cy, y + cx, ch);
        SetPoint(x - cx, y + cy, ch);
        SetPoint(x - cx, y - cy, ch);
        SetPoint(x - cy, y - cx, ch);
        SetPoint(x + cy, y - cx, ch);
        SetPoint(x + cx, y - cy, ch);

        if (error <= 0) {
            cy++;
            error += 2 * cy + 1;
        }

        if (error > 0 && cx >= cy) {
            cx--;
            error -= 2 * cx + 1;
        }
    }
}
void Canvas::FillCircle(int x, int y, int radius, char ch) {
    if (x < 0 || x >= this->width || y < 0 || y >= this->height)
        return;

    if ((x - x) * (x - x) + (y - y) * (y - y) > radius * radius)
        return;

    SetPoint(x, y, ch);

    FillCircle(x + 1, y, radius, ch);
    FillCircle(x - 1, y, radius, ch);
    FillCircle(x, y + 1, radius, ch);
    FillCircle(x, y - 1, radius, ch);
}


void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i <= right; ++i) {
        SetPoint(i, top, ch);
        SetPoint(i, bottom, ch);
    }
    for (int i = top; i <= bottom; ++i) {
        SetPoint(left, i, ch);
        SetPoint(right, i, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    if (left > right || top > bottom)
        return;

    for (int y = top; y <= bottom; ++y) {
        for (int x = left; x <= right; ++x) {
            SetPoint(x, y, ch);
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < this->width && y >= 0 && y < this->height) {
        this->canvas[y][x] = ch;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx, sy;
    if (x1 < x2) {
        sx = 1;
    }
    else {
        sx = -1;
    }
    if (y1 < y2) {
        sy = 1;
    }
    else {
        sy = -1;
    }

    int err = dx - dy;
    int e2;

    while (true) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;

        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}


void Canvas::Print() {
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            cout << this->canvas[i][j];
        }
        cout << endl;
    }
}

void Canvas::Clear() {
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            this->canvas[i][j] = ' ';
        }
    }
}