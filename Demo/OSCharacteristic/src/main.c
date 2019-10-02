int fd_main(int argc, char* argv[]);
int sysconf_main(int argc, char const* argv[]);
int time_main(int argc, char* argv[]);

int main(int argc, char* argv[]) {
  fd_main(argc, argv);
  sysconf_main(argc, argv);
  time_main(argc, argv);
}
