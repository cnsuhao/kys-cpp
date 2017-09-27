#pragma once



struct Point
{
public:
    Point() {}
    Point(int _x, int _y):x(_x), y(_y) {}
    ~Point() {}
    int x = 0, y = 0;
};

typedef enum
{
    LeftUp = 0,
    RightUp = 1,
    LeftDown = 2,
    RightDown = 3,
    None
} Towards;

struct PointEx : public Point
{
    PointEx();
    ~PointEx() {}

    int step = 0;
    int g = 0, h = 0, f = 0;
    int Gx = 0, Gy = 0;

    Towards towards;
    PointEx* parent;
    PointEx* child[4];

    void delTree(PointEx*);

    bool lessthan(const PointEx* myPoint) const
    {
        return f > myPoint->f;                                              //���رȽ������
    }
    int Heuristic(int Fx, int Fy);
};

class Compare
{
public:
    bool operator()(PointEx* point1, PointEx* point2)
    {
        return point1->lessthan(point2);
    }
};

