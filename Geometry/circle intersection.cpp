struct coor{
    double x, y;
};
struct circle{
    double x, y, r;
};
vector<circle> circles;
vector<coor> intersect;
void intersectC(circle a, circle b){
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    double d = hypot(dx, dy);
    if((d>(a.r + b.r)) || (d<fabs(a.r - b.r)) || (d == 0 && a.r == b.r))return;
    double aa = (a.r*a.r - b.r*b.r + d*d)/(2*d);
    double h = sqrt(a.r*a.r - aa*aa);
    double x2 = a.x + (dx*aa/d), y2 = a.y + (dy*aa/d);
    double rx = -dy*h/d, ry = dx*h/d;
    intersect.push_back({x2+rx, y2+ry});
    intersect.push_back({x2-rx, y2-ry});
}
