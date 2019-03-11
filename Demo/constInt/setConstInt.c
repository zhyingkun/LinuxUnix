int main()
{
int *b;
const int **a=&b;
const int c=1;
*a=&c;
*b=2;
	return c;
}
