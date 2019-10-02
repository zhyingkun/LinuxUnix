int (*pf)(void);

int f(void)
{
return 10;
}

int (*genf(void))(void)
{
	return f;
}
int main()
{
pf = f;
int (*localFunc)(void) = genf();
return (***********************pf)()+localFunc()+genf()();
}
