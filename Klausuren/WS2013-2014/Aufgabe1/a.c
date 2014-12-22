typedef struct point {
    int x;
    int y;
} point_t;

typedef struct polygon {
    int x;
    point_t* p;
} poly_t;


point_t f1(point_t a, point_t b){
}
int f2(point_t c) {
}
point_t f3(int d, int e){}
poly_t f4(point_t* f, int g, point_t h){}
void f5(int i, int j, poly_t k){}


int main() {
    point_t z = {17,4}, pnts[] = {{1,1}, {1,2}, {2,2}, {2,1}};
    poly_t q, p = {4, pnts };
    int x,y;
    
    p.p[2] = f1(p.p[0], z);
    x = p.x * f2 ( f1(z, p.p[0]));
    y = f3(17,2).y;
    q = f4(p.p, y, z);
    f5(f3(x,y).y, z.x, q);
    
    return 0;
}