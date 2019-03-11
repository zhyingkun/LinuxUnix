int main()
{
	int a = 23;
	int const * pa = &a;
	pa = &a;
	//*pa = 23;
	return 12;
}
