#include <stdio.h>
#include <termios.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define PASSWORDSIZE 12

int main(void)
{
 time_t current_time;
 time(&current_time);
 
int time1, time2;
int dif;
 int fd;
 int nread, cnt=0, errcnt=0;

 char ch, text[] = "뜨거운 여름밤은 가고 남은 건 볼품 없지만.";
 size_t length=strlen(text);
 struct termios init_attr, new_attr;
 

 time1 = time(&current_time);
 fd = open(ttyname(fileno(stdin)), O_RDWR);
 tcgetattr(fd, &init_attr);

 new_attr = init_attr;
 new_attr.c_lflag &= ~ICANON; 
 new_attr.c_lflag &= ~ECHO; /* ~(ECHO | ECHOE | ECHOK | ECHONL); */
 new_attr.c_cc[VMIN] = 1;
 new_attr.c_cc[VTIME] = 0;
 
 if(tcsetattr(fd, TCSANOW, &new_attr) != 0) {
  fprintf(stderr, "터미널 속성을 설정할 수 없음.\n");
 }
 printf("다음 문장을 그대로 입력하세요.\n %s \n", text);

while ((nread=read(fd, &ch, 1)) > 0 && ch != '\n') {
   if(ch == text[cnt++])
  write(fd, &ch, 1);
   else{
  write(fd, "*", 1);
  errcnt++;
  }
     }
 time2 =time(&current_time);
 
 dif= (length/(time2-time1))*60;
 printf("\nminute typing: %d\n",dif);
 printf("\n타이핑 오류의 횟수는 %d\n", errcnt);
 tcsetattr(fd, TCSANOW, &init_attr);
 close(fd);
   
 

 return 0;
} 
