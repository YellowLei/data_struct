struct Point
{
    double x,y;
    Point (double x = 0, double y = 0):x(x),y(y) {}
};

typedef Point Vector; //从程序上看，Vector只是Point的别名

//向量+向量=向量，向量+点=点
Vector operator + (Vector A,Vector B){return Vector(A.x+B.x,A.y+B.y);}

//点-点=向量
Vector operator - (Point A,Point B){return Vector(A.x-B.x,A.y-B.y);}

//向量*数=向量
Vector operator * (Point A,double p){return Vector(A.x*p,A.y*p);}

//向量/数=向量
Vector operator / (Point A,double p){return Vector(A.x/p,A.y/p);}

bool operator < (const Point& a,const& b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}

const double eps = 1e-10;
int dcmp(double x)
{
    if(fabs(x) < eps)
        return 0;
    else
        return x<0?-1:1;
}

bool operator == (const Point& a,const Point &b )
{
    return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}


//点积
double Dot(Vector A,Vector B) {return (A.x*B.x+A.y*B.y);}
double Length(Vector A) {return sqrt(Dot(A,A);)}
double Angle(Vector A,Vector B) {return acos(Dot(A,B))/Lengle(A)/Lengle(B);}

//叉积
double Cross(Vector A,Vector B) {return (A.x*B.y,A.y*B.x);}
double Area2(Point A,Point B,Point C) {return Cross(B-A,C-A);}

//向量旋转,rad是逆时针旋转的弧度角
Vector Roate(Vector A,double rad)
{
    return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}

//求单位法向量,旋转90°后归一化，调用前确保A不是零向量
Vector Normal(Vector A)
{
    double L = Length(A);
    return Vector(-A.y/L,A.x/L);
}

//两条直线的交点
point GetLineIntersection(Point P,Vector v,Point Q,Vector w)
{
    Vector u = p-Q;
    double t = Cross(w,u)/Cross(v,w);
    return P+v*t;
}

//点到直线的距离，叉积算出平行四边形面积，距离=面积/底边
double DistanceToLine(Point P,Point A,Point B)
{
    Vector v1 = B - A,v2 = P - A;
    return fabs(Cross(v1,v2))/Length(v1);//如果不取绝对值，得到的是有向距离
}

//点到线段距离
double DistanceToSegment(Point P,Point A,Point B)
{
    if(A == B) return Length(P-A);
    Vector v1 = B - A;V2 = p - A,V3 = p - b;
    if(dcmp(Dot(v1,v2)) < 0) return Length(v2);     //p点在射线AB上方
    else if(dcmp(Dot(v1,v3)) > 0) return Length(v3);//p点在射线BA上方
    else return fabs(Cross(v1,v2))/Length(v1);      //P点在线段上方
}

//点在直线上的投影点Q,Q=A+t*v
//PQ垂直于AB则Dot(v,P-(A+t*v))=0(v是AB)，得Dot(v,P-A)-t*Dot(v,v)=0,求得t
Point GetLineProjection(Point P,Point A,Point B)
{
    Vector v = B-A;
    return A+v*(Dot(v,P-A)/Doot(v,v));
}

//线段相交判定,交点不再端点
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2)
{
    double  c1 = Cross(a2-a1,b1-a1),c2 = Cross(a2-a1,b2-b1),
            c3 = Cross(b2-b1,a1-b1),c4 = Cross(b2-b1,a2-a1);
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}

//多边形面积,凸多边形和凹多边形都可以
double PolygonArea(Point* p,int n)
{
    double area = 0;
    for(int i = 1;i < n-1;i++)
    {
        area += Cross(p[i]-p[0],p[i+1]-p[0]);
    }
    return area/2;
}














