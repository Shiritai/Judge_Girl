<= sq_radius[0] \
                    && (sq(x-circle[1][0]) + sq(y-circle[1][1])) <= sq_radius[1] \
                    && (sq(x-circle[2][0]) + sq(y-circle[2][1])) <= sq_radius[2])
                        counter[cases]++, printf("ALL\t(%lld, %lld)\n", x, y);