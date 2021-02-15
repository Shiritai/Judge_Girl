/* 37. Metal value */
/* return -1 when the type of metal is a invalid value */
/* return -2 when there is one or more dimension has invalid number (0 or negative) */
# define sq(x) x*x
# define cube(x) x*x*x
int gcd_type2(int a, int b){
    if (a == 0)
        return b;
    return gcd_type2(b%a, a);
}
int value(int type, int width, int height, int length){
    if (width <= 0 || height <= 0 || length <= 0)
        return -2;
    switch (type){
    case 79:
        type = 30;
        break;
    case 47:
        type = 10;
        break;
    case 29:
        type = 4;
        break;
    case 82:
        type = 5;
        break;
    case 26:
        type = 3;
        break;
    case 22:
        type = 9;
        break;
    default:
        return -1;
        break;
    }
    int slice_length = gcd_type2(gcd_type2(width, height), length);
    int mul = width * height * length / (cube(slice_length));
    return sq(cube(slice_length)) * type * mul;
}