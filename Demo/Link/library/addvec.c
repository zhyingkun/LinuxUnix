int addcnt = 0;

extern void addvec(int *x, int *y, int *z, int n)
{
    int i = 0;
    addcnt++;
    for (i = 0; i < n; i++)
    {
        z[i] = x[i] + y[i];
    }
}