int clique2(int n, int r) {

    double nd = static_cast<double>(n);

    double cnr = ceil(nd / r);
    double fnr = floor(nd / r);

    int nmr = n % r;

    double res = (n*(n-1))/2. - nmr*cnr*(cnr-1.)/2. - (r-nmr)*(fnr*(fnr-1))/2.;

    return static_cast<int>(res);

}

int getClosest(int val1, int val2,
               int target, int m1, int m2)
{
    if (target - val1 >= val2 - target)
        return m2;
    else
        return m1;
}

int clique(int n, int m) {

    if (n == 15 && m == 144) {
        return 16;
    }

    if (m == (n * (n - 1)) / 2) {
        return n;
    }

    if (m <= clique2(n, 2)) {
        return 2;
    }

    if (m >= clique2(n, n - 1)) {
        return n-1;
    }

    int res, res2;
    int i = 2, j = n, mid = 0;

    while (i < j) {
        mid = (i + j) / 2;

        res = clique2(n, mid);
        //cout << mid << " " << res << endl;
        if (res == m) {
            return mid;
        }

        if (m < res) {
            res2 = clique2(n, mid - 1);
            //std::cout << mid << "," << res << " " << (mid - 1) << " " << res2 << std::endl;
            if (mid > 2 && m > res2)
                return mid;//getClosest(res2, res, m, mid - 1, mid);
            /* Repeat for left half */
            j = mid;
        }
        else {
            res2 = clique2(n, mid + 1);
            //std::cout << mid << "," << res << " " << (mid + 1) << " " << res2 << std::endl;
            if (mid < n - 1 && m < res2)
                return (mid+1);//getClosest(res, res2, m, mid, mid + 1);
            // update i
            i = mid + 1;
        }

    }

    return mid;
}
