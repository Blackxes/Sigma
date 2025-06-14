#pragma once

#include "../Core/Base.h"

namespace Sigma
{
    template <class T>
    class SIGMA_API Vector2D
    {
    public:
        T x, y;

        Vector2D<T>(T x, T y) { this->x = x; this->y = y; }
        Vector2D<T>(const Vector2D<T>& a) { this->x = a.x; this->y = a.y; }
        ~Vector2D<T>() {}

        Vector2D<T>& operator+=(const Vector2D<T>& b) { this->x += b.x; this->y += b.y; }
        Vector2D<T>& operator-=(const Vector2D<T>& b) { this->x -= b.x; this->y -= b.y; }
        Vector2D<T>& operator*=(const Vector2D<T>& b) { this->x *= b.x; this->y *= b.y; }
        Vector2D<T>& operator/=(const Vector2D<T>& b) { this->x /= b.x; this->y /= b.y; }
    };

    // Alias
    using Vector2df = Vector2D<float>;
    using Vector2dd = Vector2D<double>;
    using Vector2di = Vector2D<int>;
}