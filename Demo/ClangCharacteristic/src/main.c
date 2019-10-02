int args_main(int argc, char* argv[]);
int bitmode_main(int argc, char* argv[]);
int cal_main(int argc, char* argv[]);
int cfuncpointer_main(int argc, char* argv[]);
int copystruct_main(int argc, char* argv[]);
int declareinfunc_main(int argc, char* argv[]);
int include_main(int argc, char* argv[]);
int printf_main(int argc, char const* argv[]);

int main(int argc, char* argv[]) {
  args_main(argc, argv);
  bitmode_main(argc, argv);
  cal_main(argc, argv);
  cfuncpointer_main(argc, argv);
  copystruct_main(argc, argv);
  declareinfunc_main(argc, argv);
  include_main(argc, argv);
  printf_main(argc, argv);
  return 0;
}
