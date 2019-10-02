int printf(const char* format, ...);
int include_main(int argc, char* argv[]) {
  printf("__FILE__:%s, __LINE__:%d\n", __FILE__, __LINE__);
  printf("Hello World!\n");
  return 0;
}
