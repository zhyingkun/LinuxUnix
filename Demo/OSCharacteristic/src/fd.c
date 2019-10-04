#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int fd_test_main(int argc, char* argv[]) {
  printf("Start...\n");
  int fd = 0;
  fd = open("123.txt", O_CREAT | O_RDWR, 0644);
  printf("fd: %d\n", fd);
  fd = open("456.txt", O_CREAT | O_RDWR, 0644);
  printf("fd: %d\n", fd);
  fd = open("789.txt", O_CREAT | O_RDWR, 0644);
  printf("fd: %d\n", fd);
  fd = open("abc.txt", O_CREAT | O_RDWR, 0644);
  printf("fd: %d\n", fd);
  fd = open("def.txt", O_CREAT | O_RDWR, 0644);
  printf("fd: %d\n", fd);
  char buffer[2048];
  scanf("%s", buffer);
  printf("%s\nEnd\n", buffer);
  return 2;
}

int fd_main(int argc, char* argv[]) {
  printf("__FILE__:%s, __LINE__:%d\n", __FILE__, __LINE__);
  int fd, fd1, fd2, fd3;
  fd = open("test.txt", O_WRONLY);
  printf("test : %d\n", fd);
  //	write(1, (char)fd, 1);
  if (fd == -1) {
    return -1;
  }

  fd1 = open("test1.txt", O_WRONLY);
  printf("test1 : %d\n", fd1);
  if (fd == -1) {
    return -1;
  }
  //	write(1, "Hello\n", 6);
  close(fd);
  close(fd1);

  fd2 = open("test2.txt", O_WRONLY);
  printf("test2 : %d\n", fd2);
  if (fd == -1) {
    return -1;
  }
  //	write(1, "Hello\n", 6);
  close(fd2);

  fd3 = open("error.txt", O_WRONLY);
  printf("error : %d\n", fd3);
  if (fd == -1) {
    return -1;
  }
  //	write(1, "Hello\n", 6);
  close(fd3);

  write(1, "Hello\n", 6);
  write(2, "Write to 2\n", 11);
  // fprintf((FILE *)2, "Error Out Put");

  fd_test_main(argc, argv);
  return 0;
}
